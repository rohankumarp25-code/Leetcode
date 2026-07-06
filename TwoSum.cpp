//Two Sum Solution
/*
=========================================================
Problem: Two Sum (LeetCode 1)
Difficulty: Easy

My Approach:
- Created a duplicate of the original array.
- Sorted the duplicate array.
- Used Two Pointers to find two numbers whose sum equals the target.
- Traversed the original array to retrieve the original indices.

Key Concept(s):
- Arrays
- Sorting
- Two Pointers
- Index Mapping

Time Complexity:
O(n log n)

Space Complexity:
O(n)

What I Learned:
- Sorting can simplify searching problems.
- When sorting changes the original order, keeping a copy helps recover original information.
- Multiple DSA concepts can be combined to solve a single problem.

Mistake I Made:
- Initially, I focused only on finding the numbers.
- Then I realized the problem requires returning their original indices, so I preserved the original array.

Can it be Optimized?
- Yes. There is a linear-time solution using another concept I have already started learning.
- I will revisit this problem after mastering that approach.

Revision Note:
1. Copy the original array.
2. Sort the copy.
3. Use Two Pointers to find the target sum.
4. Map the values back to their original indices.

=========================================================
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>dup=nums;
        vector<int>ans;
        sort(dup.begin(),dup.end());
        int i=0;
        int j=dup.size()-1;
        while(i<j){
            if(dup[i]+dup[j]==target)
            break;
          else if(dup[i]+dup[j]>target)
             j--;
             else
             i++;
        }
        for(int k=0;k<nums.size();k++){
            if(nums[k]==dup[i]||nums[k]==dup[j])
            ans.push_back(k);
        }
        return ans;

    }
};