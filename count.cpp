/*
Problem: Count and Say
Difficulty: Medium

My Approach:
I generated each term from the previous term by scanning consecutive
identical digits, counting their occurrences, and appending the count
followed by the digit.

Key Concepts:
- String traversal
- Consecutive character counting
- Simulation
- String construction
- Character arithmetic

Time Complexity:
O(total length of generated sequences)

Space Complexity:
O(L), where L is the length of the current generated sequence.

What I Learned:
The next Count and Say sequence can be generated directly from the
previous sequence by grouping consecutive identical characters.

Future Improvement:
Avoid relying on '\0' as a string boundary and use explicit string
length/bounds checking.

Revision Note:
Scan → count consecutive digits → append count + digit → repeat.

*/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        string copy;
        int count = 0;
        char digit = ans[0];
        for (int i = 2; i <= n; i++) {
            int j = 0;
            copy = "";
            while (1) {
                if (ans[j] == digit)
                    count++;
                else {
                    if (count < 10)
                        copy = copy + (char)('0' + count);
                    copy = copy + digit;
                    if (ans[j] != '\0') {
                        digit = ans[j];
                        count = 1;
                    } else {
                        ans = copy;
                        digit = ans[0];
                        count = 0;
                        break;
                    }
                }
                j++;
            }
        }
        return ans;
    }
};