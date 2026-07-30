/*
=========================================================
Problem: Faulty Keyboard
Difficulty: Easy

My Approach:
- Created an empty answer string.
- Traversed the input string character by character.
- If the current character was 'i', reversed the current
  answer string.
- Otherwise, appended the character to the answer.
- Returned the final constructed string.

Key Concept(s):
- String Simulation
- String Reversal
- Implementation

Time Complexity:
Worst Case: O(n²)

Space Complexity:
O(n)

What I Learned:
- Simulation problems become much easier by directly
  implementing the operations described in the problem.
- Repeatedly reversing a string can increase the overall
  time complexity.
- A correct simulation is often the first step before
  looking for optimizations.

Future Improvement:
- Explore how to avoid repeated string reversals and
  achieve an O(n) solution.

Revision Note:
1. Traverse the string.
2. Reverse the current answer when 'i' is found.
3. Otherwise append the character.
4. Return the final string.

=========================================================
*/
class Solution {
public:
    string finalString(string s) {
        int i = 0;
        string ans;
        while (i < s.length()) {
            if (s[i] == 'i')
                reverse(ans.begin(), ans.end());
            else
                ans.push_back(s[i]);
            i++;
        }
        return ans;
    }
};