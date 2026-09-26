/*
Problem: Binary Subarrays With Sum
Difficulty: Medium

My Approach:
Used prefix sums combined with a frequency hashmap.

For each current prefix sum, I checked whether the prefix sum
(current_sum - goal) had appeared previously. Every previous occurrence
represents a subarray ending at the current position whose sum is equal
to goal.

Initialized the hashmap with prefix sum 0 so that subarrays beginning
from index 0 are counted correctly.

Key Concepts:
- Prefix Sum
- Hash Map / Frequency Map
- Subarray Sum
- Prefix Sum Difference

Time Complexity: O(n)

Space Complexity: O(n)

What I Learned:
If the sum of a subarray needs to equal a target, prefix sums can
transform the problem into finding previous prefix sums equal to
current_sum - target.

The frequency of a prefix sum matters because the same prefix sum can
occur multiple times, and each occurrence can form a different valid
subarray.

Future Improvement / Optimization Opportunity:
The prefix array itself is unnecessary because the current prefix sum
can be maintained using a single variable. This reduces unnecessary
memory usage, although the hashmap still requires O(n) space.

For this specific binary-array problem, an O(n) time and O(1) space
sliding-window approach is also possible.

Revision Note:
Remember the key equation:

current_prefix - previous_prefix = goal

Therefore:

previous_prefix = current_prefix - goal
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>pref(nums.size(),0);
        unordered_map<int,int>mp;
      mp[0]++;
        pref[0]=nums[0];
        int count=0;
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int i=0;
        while(i!=nums.size()){
            if(mp.find(pref[i]-goal)!=mp.end()){
         count=count+mp[pref[i]-goal];
            }
            mp[pref[i]]++;

         i++;
        }
        return count;
    }
};