/*
=========================================================
Problem: Maximum Subarray (LeetCode 53)
Difficulty: Medium

My Approach:
- Solved using Kadane's Algorithm.
- Maintained a running sum of the current subarray.
- Updated the maximum subarray sum after processing each element.
- Whenever the running sum became negative, reset it to zero since it could not contribute to a larger future sum.

Key Concept(s):
- Arrays
- Greedy Algorithm
- Kadane's Algorithm
- Running Sum

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- A negative running sum can never help in maximizing a future subarray sum.
- Kadane's Algorithm efficiently finds the maximum subarray in a single traversal.
- Some classic algorithms are better learned first and understood deeply rather than rediscovered from scratch.

Mistake I Made:
- I could not derive Kadane's Algorithm on my own initially.
- After watching Striver's explanation, I understood the intuition behind resetting the running sum when it becomes negative.

Can it be Optimized?
- This is the optimal solution in both time and space complexity.

Revision Note:
1. Maintain a running sum.
2. Update the maximum answer after every element.
3. If the running sum becomes negative, reset it to zero.
4. Keep the maximum value seen throughout the traversal.

=========================================================
*/




class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c=0;
        int m=INT_MIN;
        for(int i:nums){
            c=c+i;
            m=max(c,m);
            if(c<0){
                c=0;
            }
        }
        return m;
    }
};