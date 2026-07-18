/*
=========================================================
Problem: Sum of Square Numbers
Difficulty: Medium

My Approach:
- Observed that both numbers in a² + b² = c must lie
  between 0 and √c.
- Initialized two pointers:
    - i = 0
    - j = floor(√c)
- Calculated i² + j²:
    - If equal to c, return true.
    - If greater than c, decrease j.
    - If smaller than c, increase i.
- Continued until the pointers crossed.

Key Concept(s):
- Two Pointers
- Mathematical Observation
- Search Space Reduction

Time Complexity:
O(√c)

Space Complexity:
O(1)

What I Learned:
- Mathematical bounds can drastically reduce the search
  space.
- Two pointers are not limited to arrays; they can be
  applied whenever a monotonic relationship exists.
- Choosing the right search strategy is often more
  important than brute force.

Future Improvement:
- Replace pow(x, 2) with 1LL * x * x for better efficiency
  and to avoid floating-point operations.

Revision Note:
1. Set left = 0 and right = floor(√c).
2. Compute left² + right².
3. Move pointers based on whether the sum is too small or
   too large.
4. Stop when a valid pair is found or pointers cross.
=========================================================
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        float radius=sqrt(c);
          int i=0;
          int j=radius;
          if(i==j) return true;
         while(i<j){
          long long a=pow(i,2)+pow(j,2);
          if(a==c) return true;
          else if(a>c) j--;
           else if(a<c) i++;
             a=pow(i,2)+pow(j,2);
          if(i==j&&a==c) return true;
         }
          return false;
    }
};