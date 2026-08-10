/*
=========================================================
Problem: Binary Search
Difficulty: Easy

My Approach:
- Used binary search on the sorted array.
- Maintained two pointers:
    - low  -> beginning of the current search range
    - high -> end of the current search range
- Calculated the middle index of the current range.
- Compared nums[mid] with the target:
    - If equal, returned mid.
    - If nums[mid] > target, searched the left half.
    - If nums[mid] < target, searched the right half.
- Returned -1 if the target was not present.

Key Concept(s):
- Binary Search
- Divide and Conquer
- Sorted Arrays

Core Observation:
Since the array is sorted, each comparison with the middle
element allows half of the remaining search space to be
discarded.

Time Complexity:
O(log n)

Space Complexity:
O(1)

What I Learned:
- Binary search reduces the search space by approximately
  half after every comparison.
- The sorted property of the input is what makes binary
  search possible.
- The condition low <= high ensures that every possible
  position is considered.

Revision Note:
1. Initialize low and high.
2. Find the middle element.
3. Compare it with the target.
4. Search the appropriate half.
5. Return the index if found.
6. Return -1 if the search range becomes empty.
=========================================================
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};