/*
Problem: Kth Missing Positive Number

Difficulty: Easy

My Approach:
Used binary search to find the first index where the number of missing positive integers reaches or exceeds k. Calculated missing numbers before each index using arr[mid] - (mid + 1). After the search, returned low + k.

Key Concepts:
- Binary search
- Sorted array
- Missing element count
- Search space reduction
- Boundary tracking
Time Complexity: O(log n)

Auxiliary Space Complexity: O(1)

What I Learned:
The number of missing positive integers before an index can be calculated directly, allowing binary search without explicitly generating missing numbers.

Future Improvement:
Explore alternative formulations of the missing-count condition to strengthen binary search intuition.

Revision Note:
Missing before index mid = arr[mid] - (mid + 1) → compare with k → adjust search boundaries → return low + k.
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        int missing;
        while(high>=low){
            int mid=(low+high)>>1;
            missing=arr[mid]-(mid+1);
            if(missing<k)
            low=mid+1;
            else 
            high=mid-1;
        }
        return (low+k);
    }
};