/*
=========================================================
Problem: Find First and Last Position of Element in
         Sorted Array
Difficulty: Medium

My Approach:
- Used two binary searches.
- The first binary search finds the first occurrence of
  target.
- The second binary search finds the first element strictly
  greater than target (upper bound).
- The position immediately before the upper bound is the
  last occurrence of target.
- Used a flag to determine whether target was present.

First Binary Search:
- If nums[mid] >= target:
    - Store mid as a possible first occurrence.
    - Continue searching toward the left.
- If nums[mid] < target:
    - Search toward the right.

Second Binary Search:
- If nums[mid] > target:
    - Store mid as a possible upper bound.
    - Continue searching toward the left.
- If nums[mid] <= target:
    - Search toward the right.

Final Answer:
    first occurrence = first
    last occurrence  = last - 1

Key Concept(s):
- Binary Search
- Lower Bound
- Upper Bound
- Boundary Searching
- Sorted Arrays

Time Complexity:
O(log n)

Space Complexity:
O(1)

What I Learned:
- The first and last occurrence of a value can be found
  efficiently using boundary-based binary searches.
- The first occurrence can be viewed as the first index
  where nums[i] >= target.
- The last occurrence can be obtained from the first index
  where nums[i] > target.
- Upper bound can therefore be directly used to determine
  the last occurrence.

Revision Note:
1. Find the first position where nums[i] >= target.
2. Find the first position where nums[i] > target.
3. If target does not exist, return {-1, -1}.
4. Otherwise return {first, upperBound - 1}.
=========================================================
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        vector<int> ans;
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int found = 0;
        while (low <= high) {
            mid = (high + low) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    found = 1;
                first = mid;
                high = mid - 1;
            }
            if (nums[mid] < target)
                low = mid + 1;
        }
        low = 0;
        high = nums.size() - 1;
        int last = nums.size();
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] > target) {
                last = mid;
                high = mid - 1;
            } else if (nums[mid] <= target) {
                low = mid + 1;
                if (nums[mid] == target)
                    found = 1;
            }
        }
        if (found == 0)
            return {-1, -1};
        ans.push_back(first);
        ans.push_back(last - 1);
        return ans;
    }
};