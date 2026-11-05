/*

## Problem
Find the smallest divisor such that the sum of the ceiling-divided elements is less than or equal to the given threshold.

## Difficulty
Medium

## My Approach
Used binary search on the answer to find the smallest valid divisor. Calculated the sum of ceiling divisions for each candidate and adjusted the search range based on whether the sum exceeded the threshold.

## Key Concepts
- Binary Search on Answer
- Monotonicity
- Ceiling Division
- Search Space Reduction

## Time Complexity
O(n log M)

Where `n` is the number of elements and `M` is the maximum element in the array.

## Auxiliary Space Complexity
O(1)

What I Learned
Binary search can efficiently find the smallest value satisfying a condition when the condition is monotonic.

 Future Improvement
Use a single variable to track the smallest valid divisor instead of maintaining separate candidates for equality and less-than cases.
 Revision Note
If sum > threshold → increase divisor.  
If sum <= threshold → store candidate and search smaller divisors.



*/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = 0;
        int i = 0;
        while (i < nums.size())
            maxi = max(maxi, nums[i++]);
        int low = 1;
        int high = maxi;
        int mid;
        int ans1 = INT_MAX, ans2 = INT_MAX;
        while (high >= low) {
            int sum = 0;
            mid = (low + high) >> 1;
            for (int i = 0; i < nums.size(); i++) {
                int term = nums[i] / mid;
                if ((nums[i] % mid) > 0)
                    term++;
                sum = sum + term;
            }
            if (sum == threshold) {
                ans1 = min(mid, ans1);
                high = mid - 1;
            } else if (sum > threshold) {
                low = mid + 1;
            } else {
                ans2 = min(ans2, mid);
                high = mid - 1;
            }
        }
        if (ans1 != INT_MAX)
            return ans1;
        return ans2;
    }
};