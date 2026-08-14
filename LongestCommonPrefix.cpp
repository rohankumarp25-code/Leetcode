/*
=========================================================
Problem: Longest Common Prefix
Difficulty: Easy

My Approach:
- Used vertical character-by-character comparison.
- Took the first string as the reference string.
- For each character position in the first string:
    - Stored the character as the current reference character.
    - Compared it with the character at the same position
      in every other string.
- If a mismatch occurs or any string ends before the
  current position, returned the prefix constructed so far.
- If all strings contain the same character at the current
  position, appended it to the answer.

Key Concept(s):
- String Traversal
- Character Comparison
- Prefix Matching

Core Observation:
The longest common prefix can be found by comparing the
strings vertically, one character position at a time.

For each position i:
    strs[0][i] must equal strs[1][i], strs[2][i], ...

The first mismatch determines the end of the common prefix.

Time Complexity:
O(N * M)

where:
N = number of strings
M = length of the shortest relevant string

Space Complexity:
O(1) auxiliary space
(O(M) if the returned answer string is counted.)

Why This Is Optimal:
In the worst case, every character of every string may need
to be examined before finding a mismatch. Therefore,
O(N * M) is asymptotically optimal for the general problem.

What I Learned:
- Not every problem needs a complicated data structure or
  advanced algorithm.
- Direct traversal can be optimal when the input itself
  requires examining the relevant characters.
- Early termination at the first mismatch avoids unnecessary
  comparisons.

Revision Note:
1. Use the first string as the reference.
2. Compare each character position across all strings.
3. Stop at the first mismatch or end of a string.
4. Return the prefix built so far.

Problem Solving Status:
🟢 Independently Solved
=========================================================
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ch;
        char check;
        for (int i = 0; i < strs[0].length(); i++) {
            check = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] == '\0' || check != strs[j][i])
                    return ch;
                if (j == strs.size() - 1)
                    ch.push_back(check);
            }
        }
        return ch;
    }
};