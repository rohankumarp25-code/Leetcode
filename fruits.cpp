/*
Problem: Fruit Into Baskets
Difficulty: Medium

My Approach:
Used a sliding window with two fruit types and counters to track
how many fruits of each type remain in the current window. When
a third type appears, I shrink the window until one type is removed.

Key Concepts:
- Sliding window
- Two pointers
- Frequency/count tracking
- Greedy window adjustment

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

What I Learned:
A sliding window can maintain a constraint of at most two distinct
values without storing a frequency map.

Future Improvement:
Simplify initialization and window updates to reduce special cases
and make the invariant easier to verify.

Revision Note:
Expand the window → handle a third type → shrink until one type
disappears → continue tracking the maximum length.
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int typ1 = fruits[0];
        int b1 = 1;
        if (fruits.size() == 1)
            return 1;
        int end = 1;
        while (end != fruits.size() && fruits[end] == typ1) {
            b1++;
            end++;
            if (end == fruits.size())
                return end;
        }
        int b2 = 1;
        int typ2 = fruits[end];
        int maxlen = end + 1;
        end++;
        while (end != fruits.size()) {
            if (fruits[end] == typ1)
                b1++;
            else if (fruits[end] == typ2)
                b2++;
            else {
                while (b1 > 0 && b2 > 0) {
                    if (fruits[start] == typ1)
                        b1--;
                    else if (fruits[start] == typ2)
                        b2--;
                    start++;
                }
                if (b2 == 0) {
                    typ2 = fruits[end];
                    b2 = 1;
                } else if (b1 == 0) {
                    b1 = b2;
                    typ1 = typ2;
                    typ2 = fruits[end];
                    b2 = 1;
                }
            }
            maxlen = max(maxlen, end - start + 1);
            end++;
        }
        return maxlen;
    }
};