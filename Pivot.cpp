/*
=========================================================
Problem: Find Pivot Index
Difficulty: Easy

My Approach:
- Used a prefix sum array to store the cumulative sum of
  elements from the beginning of the array.
- For every possible pivot index, compared the sum of all
  elements to its left with the sum of all elements to its
  right.
- The left sum was obtained using the previous prefix sum.
- The right sum was calculated by subtracting the current
  prefix sum from the total sum.
- Returned the first index where both sums were equal.
- Handled the first and last indices separately.

Key Concept(s):
- Prefix Sum
- Array Traversal
- Running/Cumulative Sum

Core Observation:
For an index i:

Left Sum  = prefixSum[i - 1]

Right Sum = totalSum - prefixSum[i]

If:

Left Sum == Right Sum

then i is the pivot index.

Time Complexity:
O(n)

Space Complexity:
O(n)

What I Learned:
- Prefix sums allow left and right subarray sums to be
  calculated efficiently without repeatedly traversing
  the array.
- Boundary indices need separate consideration because
  they have an empty left or right subarray.
- A prefix-sum approach converts repeated sum calculations
  into constant-time lookups.

Future Improvement:
- Optimize the solution to O(1) extra space by maintaining
  the total sum and a running left sum instead of storing
  the complete prefix-sum array.

=========================================================
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefsum(nums.size(), 0);
        prefsum[0] = nums[0];
        int pivot = -1;
        for (int i = 1; i < nums.size(); i++) {
            prefsum[i] = prefsum[i - 1] + nums[i];
        }
        if (prefsum[nums.size() - 1] - prefsum[0] == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (prefsum[i - 1] == prefsum[nums.size() - 1] - prefsum[i])
                return i;
        }
        if (prefsum[nums.size() - 2] == 0)
            pivot = nums.size() - 1;
        return pivot;
    }
};