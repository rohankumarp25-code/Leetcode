/*
=========================================================
Problem: Reverse Vowels of a String
Difficulty: Easy

My Approach:
- Used two pointers:
    - Left pointer starts from the beginning.
    - Right pointer starts from the end.
- Moved each pointer until a vowel was found.
- Swapped the vowels and continued until the pointers met.

Key Concept(s):
- Two Pointers
- String Manipulation
- In-place Swapping

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Two pointers can efficiently process strings from both
  ends while avoiding unnecessary traversals.
- In-place swapping eliminates the need for extra memory.
- Helper functions (like isVowel()) can greatly improve
  readability without changing the algorithm.

Future Improvement:
- Create an isVowel() helper function to avoid repeating
  the vowel checking condition multiple times.

Revision Note:
1. Initialize left and right pointers.
2. Skip non-vowel characters.
3. Swap vowels when both pointers are on vowels.
4. Continue until the pointers cross.
=========================================================
*/
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        if (j == 0)
            return s;
        while (i < j) {
            if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                  s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                  s[i] == 'O' || s[i] == 'U'))
                i++;
            if (!(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                  s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                  s[j] == 'O' || s[j] == 'U'))
                j--;

            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                 s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                 s[i] == 'O' || s[i] == 'U') &&
                (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                 s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                 s[j] == 'O' || s[j] == 'U')) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};