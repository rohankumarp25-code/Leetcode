/*
Problem: Minimum Number of Days to Make m Bouquets

Difficulty: Medium

My Approach:
Used binary search on the answer to find the minimum day required to make the requested number of bouquets. For each candidate day, traversed the array and counted consecutive flowers that had bloomed. Whenever k consecutive flowers were available, formed a bouquet and reset the count.
Key Concepts:
- Binary Search on Answer
- Monotonicity
- Greedy Counting
- Consecutive Elements
- Search Space Reduction
- Overflow Prevention
Time Complexity: O(n log M)

Auxiliary Space Complexity: O(1)

What I Learned:
Binary search can efficiently find the minimum feasible day when feasibility is monotonic. Also, consecutive elements must be handled carefully when counting valid groups.

Future Improvement:
Simplify the feasibility check into a separate helper function for better readability and maintainability.

Revision Note:
For a candidate day, count consecutive bloomed flowers → form bouquets whenever count reaches k → reset after each bouquet → adjust binary search based on whether m bouquets are possible.
*/
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long M=m;
        long long K=k;
        long long N=bloomDay.size();
        if (K*M>N)
            return -1;
        int i = 0;
        int high = 0;
        int low = INT_MAX;
        while (i < bloomDay.size()) {
            low = min(low, bloomDay[i]);
             high = max(high, bloomDay[i++]);
        }
        int ans = high;
        int mid;
        while (high >= low) {
            mid = (low + high) >> 1;
            int point = 0;
            while (point != bloomDay.size() && bloomDay[point] > mid)
                point++;
            int count = 0;
            int length = 0;
            while (point != bloomDay.size()) {
                if (bloomDay[point] <= mid) {
                        point++;
                        length++;
                        if(length==k){
                            count++;
                            length=0;
                        }
                } 
                else {
                    while (point != bloomDay.size() && bloomDay[point] > mid)
                        point++;
                    length = 0;
                }
            }
            if (count >= m) {
                ans = min(ans, mid);
                high = mid - 1;
            } 
            else
                low = mid + 1;
        }
        return ans;
    }
};