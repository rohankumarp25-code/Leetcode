/*
=========================================================
Problem: Reverse Words in a String
Difficulty: Medium

My Approach:
- Traversed the string and recorded the starting index of
  every word in a vector.
- Ignored consecutive spaces when identifying word starts.
- Started processing from the last word and moved toward
  the first word.
- Traversed each word character-by-character and appended
  it to the answer string.
- Added a space between words while constructing the result.
- Returned the final string once all words were processed.

Key Concept(s):
- String Traversal
- Index Tracking
- Vector
- Reverse Word Ordering

Core Observation:
Instead of reversing individual characters, I stored the
starting position of each word and then processed the words
from right to left.

Example:
    "hello world here"

Word starting indices:
    [0, 6, 12]

Processing order:
    here → world → hello

Result:
    "here world hello"

Time Complexity:
O(n)

where n is the length of the input string.

Space Complexity:
O(n)

The vector storing word starting positions can contain up
to O(n) indices in the worst case.

What I Learned:
- A string problem can sometimes be simplified by storing
  important boundary/index information while traversing it.
- Tracking the starting index of each word makes reversing
  the word order straightforward.
- Consecutive spaces need to be handled when identifying
  word boundaries.
- Building the answer while traversing from the last word
  to the first avoids repeatedly searching for words.

Problem Solving Status:
🟢 Independently Solved

Future Optimization:
- Explore whether the extra vector can be eliminated while
  maintaining O(n) time complexity.

=========================================================
*/
class Solution {
public:
    string reverseWords(string s) {
        vector<int> remb;
        string ans;
        if (s[0] != ' ')
            remb.push_back(0);
        for (int i = 1; s[i] != '\0'; i++) {
            if (s[i - 1] == ' '&&s[i]!=' ')
                remb.push_back(i);
        }
        int j = remb.size() - 1;
        int i = remb[j];
        while (j >= 0) {
            ans.push_back(s[i]);
            i++;
            if (s[i] == ' ' || s[i] == '\0') {
                if(j==0)
                return ans;
                ans.push_back(' ');
                j--;
                 i = remb[j];
            }
        }
        return ans;
    }
};