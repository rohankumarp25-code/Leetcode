/*
Problem: Capacity To Ship Packages Within D Days

Difficulty: Medium

My Approach:
Used binary search to find the minimum ship capacity required to deliver all packages within the given number of days. For each candidate capacity, simulated the shipping process while preserving the original package order and counted the number of days required.

Key Concepts:
- Binary Search on Answer
- Greedy Simulation
- Monotonicity
- Search Space Reduction
- Capacity Constraints
Time Complexity: O(n log S)

Auxiliary Space Complexity: O(1)

What I Learned:
Binary search can efficiently find the minimum feasible capacity when feasibility is monotonic. Greedy simulation helps determine whether a candidate capacity is sufficient.

Future Improvement:
Simplify the shipping simulation by resetting the capacity and allowing the next iteration to process the current package.

Revision Note:
Set low to the maximum package weight and high to the total weight → simulate shipping for mid capacity → if days required are within the limit, search for a smaller capacity.
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        int low=0;
        int i=0;
        while(i<weights.size()){
            high=high+weights[i];
            low=max(low,weights[i++]);
        }
            int ans=INT_MAX;
        while(high>=low){
            int mid=(low+high)>>1;
            int i=0;
            int day=1;
            int mass=mid;
            while(i<weights.size()){
                if(mass>=weights[i])
                mass=mass-weights[i++];
                else if(mass<weights[i]){
                    mass=mid;
                    day++;
                    mass=mass-weights[i++];
                }
            }
            if(day<=days){
                ans=min(mid,ans);
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};