/*
=========================================================
Problem: Can Reach
Difficulty: Contest Problem

My Approach:
- Observed that every valid operation preserves the parity
  (even/odd nature) of the sum of the coordinates.
- Computed the parity of:
    - start[0] + start[1]
    - target[0] + target[1]
- If both parities are the same, reaching the target is
  possible; otherwise, it is impossible.

Key Concept(s):
- Mathematical Observation
- Invariant
- Parity

Time Complexity:
O(1)

Space Complexity:
O(1)

What I Learned:
- Some problems do not require simulation.
- Looking for an invariant can reduce a seemingly complex
  problem to a simple mathematical check.
- Identifying what remains unchanged after every operation
  is a powerful problem-solving technique.

Future Improvement:
- Simplify the return statement using:
  return ((start[0] + start[1]) % 2) ==
         ((target[0] + target[1]) % 2);

Revision Note:
1. Find the invariant.
2. Compute parity of both coordinate sums.
3. Compare the parities.
4. Return the result.
=========================================================
*/
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int aim=target[0]+target[1];
        int now=start[0]+start[1];
        if((aim%2==0&&now%2==0)||(aim%2!=0&&now%2!=0)) return true;
        else return false;
        return true;
    }
};