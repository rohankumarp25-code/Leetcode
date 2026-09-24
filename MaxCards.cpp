/*
Problem: Maximum Points You Can Obtain from Cards
Difficulty: Medium

My Approach:
Observed that exactly k cards must be taken from the two ends of the
array. Instead of checking every possible combination directly, I started
with the case where all k cards are taken from the right side.

Then I gradually shifted the selection boundary, adding one card from
the left side and removing one card from the right side. This allows all
possible distributions of k cards between the two ends to be evaluated
using a sliding-window style approach.

Key Concepts:
- Sliding Window
- Two Pointers
- Array Traversal
- Optimization from Brute Force
- Choosing Elements from Both Ends

Time Complexity: O(n)

Space Complexity: O(1)

What I Learned:
A problem that appears to require checking many combinations can sometimes
be transformed into a sliding-window problem by looking at what elements
are left unselected.

Instead of directly maximizing the sum of selected cards, I can move the
selection boundary and update the sum incrementally.

Future Improvement / Optimization Opportunity:
The algorithm is already optimal at O(n) time and O(1) auxiliary space.
The indexing logic could be simplified to make the implementation easier
to read and maintain.

Revision Note:
For problems where exactly k elements must be selected from the two ends,
think about the possible k+1 distributions:
0 from left + k from right,
1 from left + k-1 from right,
...
k from left + 0 from right.

*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0;
        int n=cardPoints.size();
        while(i!=(n-k))
        i++;
        int j=i;
        int sum=0;
        while(j!=n)
        sum=sum+cardPoints[j++];
        int maxsum=sum;
        int end=0;
        int start=i;
        while(end!=k){
            if(i>n-1)
            start=i-n;
            else
            start=i;
         sum=sum+cardPoints[end]-cardPoints[start];
         i++;
         end++;
         maxsum=max(sum,maxsum);
        }
     return maxsum;
    }
};