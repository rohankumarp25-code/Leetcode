/*
=========================================================
Problem: Maximum Sum of Distinct Subarrays With Length K
Difficulty: Medium

My Approach:
- Used a fixed-size sliding window of length k.
- Used an unordered_map to maintain the frequency of
  elements currently present in the window.
- Maintained the sum of the current window incrementally
  instead of recalculating it.
- Maintained a variable `dupli` to track how many distinct
  values currently occur more than once in the window.
- When adding an element:
    - Increase its frequency.
    - If its frequency becomes 2, increase `dupli`.
- When removing an element:
    - Decrease its frequency.
    - If its frequency becomes 1, decrease `dupli`.
- A window is valid only when `dupli == 0`.
- For every valid window, updated the maximum sum.

Key Concept(s):
- Sliding Window
- Hash Map / Frequency Counting
- Maintaining a Running Sum
- Maintaining a Window Invariant

Important Observation:
Instead of checking the entire window for duplicates every
time, I maintained the number of duplicated values using
`dupli`.

Frequency transitions:
    1 -> 2 : duplicate appears  -> dupli++
    2 -> 3 : same duplicate     -> no change
    2 -> 1 : duplicate disappears -> dupli--
    1 -> 0 : normal removal     -> no change

Time Complexity:
O(n) average case

Space Complexity:
O(k)

What I Learned:
- A fixed-size sliding window can maintain both the sum and
  frequency information efficiently.
- The window's validity can be maintained using an invariant
  instead of repeatedly checking every element.
- When maintaining frequencies in a sliding window, it is
  important to update the state both when elements enter and
  when elements leave.
- The initial window must also be checked for validity.

Problem-Solving Journey:
- Initially tried resetting the sum when a duplicate appeared,
  which was incorrect because the window sum must be maintained
  independently of whether the window is valid.
- Then realized that the sum and duplicate tracking should be
  handled separately.
- Used `dupli` to maintain whether the current window contains
  repeated values.
- Debugged the initial-window edge case and pointer/frequency
  updates until the solution was accepted.

Learning Status:
🟡 Hint-Assisted
- Core sliding-window approach and implementation were developed
  independently.
- Needed a conceptual hint for maintaining the duplicate count.

Revision Note:
1. Build the first window.
2. Calculate its sum and duplicate count.
3. Slide the window one element at a time.
4. Add the incoming element.
5. Remove the outgoing element.
6. Update `sum` and `dupli`.
7. If `dupli == 0`, update the maximum sum.
=========================================================
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        long long sum=0;
        int dupli=0;
        for(int i=0;i<k;i++){
            hash[nums[i]]++;
            if(hash[nums[i]]==2)
            dupli++;
          sum=sum+nums[i];
        }
        long long maxsum;
        if(dupli==0)
         maxsum=sum;
        else 
        maxsum=0;
        for(int i=k;i<nums.size();i++){
            hash[nums[i]]++;
             if(hash[nums[i]]==2)
            dupli++;
            hash[nums[i-k]]--;
            if(hash[nums[i-k]]==1)
            dupli--;
            sum=sum+nums[i]-nums[i-k];
            if(dupli==0){
            maxsum=max(maxsum,sum);
            }
        }
        return maxsum;
    }
};