/*
=========================================================
Problem: Max Consecutive Ones (LeetCode 485)
Difficulty: Easy

My Approach:
- Traversed the array once.
- Maintained the current streak of consecutive 1s.
- Updated the maximum streak whenever the current streak increased.
- Reset the current streak whenever a 0 was encountered.

Key Concept(s):
- Arrays
- Traversal
- Counting Consecutive Elements
- State Tracking

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Many array problems can be solved by maintaining a running state instead of using extra data structures.
- Updating the answer during traversal avoids unnecessary second passes.

Mistake I Made:
- Initially, I checked for the maximum in both the 1 and 0 cases. Although correct, I realized that thinking carefully about when the maximum actually changes helps simplify the logic.

Can it be Optimized?
- Yes, the logic can be written slightly more concisely, but the time and space complexity are already optimal.

Revision Note:
- Keep two variables:
  1. currentLen -> current streak of 1s.
  2. maxLen -> longest streak seen so far.
- Reset currentLen whenever a 0 appears.
========================================================
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen = 0;
        int currenlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currenlen++;
                if (currenlen > maxlen) {
                    maxlen = currenlen;
                }
            } else if (nums[i] == 0) {
                if (currenlen > maxlen) {
                    maxlen = currenlen;
                }
                currenlen = 0;
            }
        }
        return maxlen;
    }
};