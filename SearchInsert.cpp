/*
=========================================================
Problem: Search Insert Position
Difficulty: Easy

My Approach:
- Used binary search to find the correct insertion position
  of the target in a sorted array.
- Maintained an `ans` variable initialized to nums.size().
- Whenever nums[mid] >= target:
    - Stored mid as a possible insertion position.
    - Continued searching toward the left for an earlier
      valid position.
- When nums[mid] < target:
    - Moved toward the right half.
- The final `ans` represents the first index where
  nums[i] >= target.
- If no such position exists, ans remains nums.size(),
  meaning the target should be inserted at the end.

Key Concept(s):
- Binary Search
- Lower Bound
- Boundary Searching
- Sorted Arrays

Core Observation:
The insertion position is exactly the lower bound of target:

    first index i such that nums[i] >= target

Time Complexity:
O(log n)

Space Complexity:
O(1)

What I Learned:
- Search Insert Position can be solved as a lower-bound
  problem rather than searching for the target directly.
- Maintaining a candidate answer while continuing toward
  the left allows us to find the first valid position.
- Initializing the answer to nums.size() naturally handles
  the case where the target belongs at the end.

Revision Note:
1. Initialize ans = nums.size().
2. Perform binary search.
3. If nums[mid] >= target, store mid and search left.
4. Otherwise search right.
5. Return ans.
=========================================================
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int ans=nums.size();
        int high =ans-1;
        int low=0;
        int mid=0;
        while(low<=high){
            mid=(high+low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            if(nums[mid]<target)
            low=mid+1;
        }
        return ans;

    }
};