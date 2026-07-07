/*
=========================================================
Problem: Largest Odd Number in String (LeetCode 1903)
Difficulty: Easy

My Approach:
- Checked whether the last digit of the string is odd.
- If yes, returned the entire string since it is already the largest possible odd number.
- Otherwise, traversed the string to find the last odd digit.
- Constructed the answer by taking all characters from the beginning up to the last odd digit.

Key Concept(s):
- Strings
- Traversal
- Character Manipulation
- Greedy Observation

Time Complexity:
O(n)

Space Complexity:
O(n)

What I Learned:
- Sometimes the largest valid answer is simply the longest valid prefix.
- Looking for the last valid position can simplify many string problems.
- Checking simple edge cases first can avoid unnecessary computation.


Can it be Optimized?
- Yes.
- The extra string can be avoided by returning the required prefix directly.
- I will revisit this problem after learning more string manipulation techniques.

Revision Note:
1. If the last digit is odd, return the entire string.
2. Otherwise, find the last odd digit.
3. Return the prefix ending at that position.
4. If no odd digit exists, return an empty string.
=========================================================
*/

class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        if (num[num.length() - 1] % 2 == 1)
            return num;
            int track = -1;
            for(int j=num.length()-1;j>=0;j--){
                if (num[j] % 2 == 1) {
                track = j;
                break;
            }
              
            }
            for (int j = 0;j<=track; j++)
                ans.push_back(num[j]);

        return ans;
    }
};