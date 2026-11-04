/*
Problem: Sqrt(x)
Difficulty: Easy

My Approach:
Used binary search to find the largest integer whose square is
less than or equal to x. Maintained the best valid candidate
while searching the remaining range.

Key Concepts:
- Binary search
- Search space reduction
- Integer overflow prevention
- Boundary tracking

Time Complexity: O(log x)
Auxiliary Space Complexity: O(1)

What I Learned:
Binary search can find an integer answer by checking a monotonic
condition rather than searching through every possible value.

Future Improvement:
Explore returning the final search boundary without maintaining
a separate lower variable.

Revision Note:
Compare mid² with x → adjust search range → track largest valid mid.
*/
class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        long long num=x;
        long long mid;
        long long lower=0;
        while(high>=low){
            mid=(low+high)>>1;
            if(mid*mid==num)
            return mid;
            else if(mid*mid>num)
                high=mid-1;
            else{
                lower=max(lower,mid);
                low=mid+1;
            }
           }
           int ans=lower;
        return ans;
    }
};