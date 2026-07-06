/*
=========================================================
Problem: Sort Colors (LeetCode 75)
Difficulty: Medium

My Approach:
- Counted the frequency of 0s, 1s, and 2s using a fixed-size array.
- Overwrote the original array by placing all 0s first, followed by 1s, then 2s.

Key Concept(s):
- Arrays
- Hashing (Frequency Counting)
- Counting Sort Idea
- Array Reconstruction

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- When the range of values is very small, a fixed-size frequency array is an efficient solution.
- Sometimes rebuilding the array is simpler than repeatedly swapping elements.
- Always use the problem constraints to choose the most suitable data structure.

Mistake I Made:
- Initially, I considered solving it using comparisons and swaps.
- Then I realized there are only three possible values, making frequency counting much simpler.

Can it be Optimized?
- Yes.
- The problem also has a one-pass, in-place solution using constant extra space.
- I will revisit this problem after learning that technique.

Revision Note:
1. Count the number of 0s, 1s, and 2s.
2. Rewrite the array:
   - Place all 0s.
   - Then all 1s.
   - Finally all 2s.
3. Works because the value range is fixed (0–2).
=========================================================
*/



class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>hash(3,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash[0];i++){
            nums[i]=0;
        }
         for(int i=0;i<hash[1];i++){
            nums[i+hash[0]]=1;
        }
         for(int i=0;i<hash[2];i++){
            nums[i+hash[0]+hash[1]]=2;
        }
    }
};