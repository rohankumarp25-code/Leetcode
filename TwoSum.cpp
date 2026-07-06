/*
=========================================================
Problem: Two Sum (LeetCode 1)
Difficulty: Easy

My Approach:
- Used an unordered_map to store each number along with its index.
- For every element, calculated the required complement (target - current element).
- Checked whether the complement had already been seen.
- If found, returned the current index and the stored index.
- Otherwise, stored the current element and its index in the hash map.

Key Concept(s):
- Arrays
- Hashing
- unordered_map
- Complement Technique
- One-pass Traversal

Time Complexity:
O(n) Average Case

Space Complexity:
O(n)

What I Learned:
- Hashing can reduce searching problems from O(n log n) to O(n).
- Storing previously visited elements allows finding the answer in a single traversal.
- Sometimes using extra space significantly improves time complexity.

Mistake I Made:
- My first accepted solution used Sorting + Two Pointers, which required O(n log n) time.
- Later I realized hashing allows solving the problem in a single pass while preserving the original indices.

Can it be Optimized?
- The average-case time complexity is already optimal: O(n).
- This is the standard interview solution.

Revision Note:
1. Traverse the array once.
2. Compute the complement = target - current element.
3. If the complement exists in the hash map, return both indices.
4. Otherwise, store the current element and its index.

Problem Solving Rating (My Version):
⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐ (10/10)

=========================================================
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long,int>mp;
        vector<int>ans;
            int more;
        for(int i=0;i<nums.size();i++){
            more=target-nums[i];
            if(mp.find(more)!=mp.end()){
            ans.push_back(i);
            ans.push_back(mp[more]);
            break;
            }
            if(mp.find(more)==mp.end())
             mp[nums[i]]=i;
        }
     
        return ans;

    }
}; 