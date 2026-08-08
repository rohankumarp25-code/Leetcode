/*
=========================================================
Problem: Majority Element II
Difficulty: Medium

My Approach:
- Implemented the Extended Boyer-Moore Voting Algorithm.
- Maintained two potential majority candidates and their
  respective counters.
- Traversed the array once to identify possible candidates.
- Performed a second traversal to verify whether the
  candidates actually appeared more than n/3 times.
- Returned all valid majority elements.

Key Concept(s):
- Extended Boyer-Moore Voting Algorithm
- Greedy Observation
- Majority Element
- Candidate Elimination

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- For a threshold of n/3, there can be at most two majority
  elements.
- Candidate elimination allows majority elements to survive
  while non-majority elements cancel each other out.
- A second pass is necessary to verify the candidates
  because the first pass only identifies potential majority
  elements.

Future Improvement:
- Initialize candidate variables explicitly for improved
  code clarity and robustness.

Revision Note:
1. Maintain two candidates and two counters.
2. Update candidates and counters while traversing.
3. Cancel out different elements.
4. Verify both candidates in a second pass.
5. Return the verified majority elements.
=========================================================
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, el1, el2;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1++;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2++;
                el2 = nums[i];
            } else if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }
        if (cnt1 > nums.size() / 3)
            ans.push_back(el1);
        if (cnt2 > nums.size() / 3)
            ans.push_back(el2);
        return ans;
    }
};