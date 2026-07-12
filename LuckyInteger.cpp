/*
=========================================================
Problem: Find Lucky Integer in an Array
Difficulty: Easy

My Approach:
- Used a frequency array to count the occurrences of each
  integer in the array.
- Traversed the frequency array in reverse order to find
  the largest integer whose value equals its frequency.

Key Concept(s):
- Frequency Counting
- Arrays
- Constraint-Based Optimization

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Constraints can guide the choice of data structure.
- A fixed-size frequency array can be more efficient than
  a hash map when the value range is small.
- Traversing in reverse helps directly obtain the largest
  valid answer without additional comparisons.

Revision Note:
1. Count frequencies using a fixed-size array.
2. Traverse from the maximum possible value downward.
3. Return the first value whose frequency equals its value.
4. Return -1 if no lucky integer exists.
=========================================================
*/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>hash(501,0);
        for(int i=0;i<arr.size();i++)
        hash[arr[i]]++;
        for(int i=500;i>0;i--){
            if(i==hash[i]) return i;
        }
        return -1;
    }
}; 