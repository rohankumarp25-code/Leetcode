/*
=========================================================
Problem: Subarray Sum Equals K
Difficulty: Medium

My Approach:
- Used the Prefix Sum + Hash Map technique.
- Maintained the current prefix sum while traversing the
  array.
- Stored the frequency of every prefix sum encountered.
- For the current prefix sum, checked whether
  (prefixSum - k) had appeared previously.
- If it had appeared, every occurrence represents a
  subarray whose sum is exactly k.
- Initialized the hash map with prefix sum 0 having
  frequency 1 to correctly handle subarrays starting
  from index 0.

Key Concept(s):
- Prefix Sum
- Hash Map
- Frequency Counting
- Subarray Sum

Core Observation:
If:

    currentPrefixSum - previousPrefixSum = k

then:

    previousPrefixSum = currentPrefixSum - k

Therefore, for every current prefix sum, I search for
(prefixSum - k) in the hash map.

Time Complexity:
O(n) average case

Space Complexity:
O(n)

What I Learned:
- Prefix sums can transform subarray-sum problems into
  a lookup problem.
- Storing frequencies instead of just whether a prefix
  sum exists is important because the same prefix sum
  can occur multiple times, producing multiple valid
  subarrays.
- Initializing hash[0] = 1 is essential for counting
  subarrays that begin at index 0.

Revision Note:
1. Initialize prefixSum = 0.
2. Store prefix sum 0 with frequency 1.
3. Traverse the array.
4. Update prefixSum.
5. Search for prefixSum - k.
6. Add its frequency to the answer.
7. Store the current prefix sum in the map.
=========================================================
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>hash;
    int prefsum=0;
   hash[prefsum]++;
    for(int i=0;i<nums.size();i++){
        prefsum=prefsum+nums[i];
        if(hash.find(prefsum-k)!=hash.end()){
            count=count+(hash[prefsum-k]);
        }
        hash[prefsum]++;
    }
        return count;
    }
};