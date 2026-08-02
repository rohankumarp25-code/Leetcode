/*
=========================================================
Problem: Squares of a Sorted Array
Difficulty: Easy

My Approach:
- Observed that although the array is sorted, squaring the
  elements changes their order because negative numbers
  become positive.
- Used two pointers:
    - Left pointer at the beginning.
    - Right pointer at the end.
- Compared the squares of both elements.
- Placed the larger squared value at the current end of the
  result array and moved the corresponding pointer.
- Continued until all positions in the result array were
  filled.

Key Concept(s):
- Two Pointers
- Array Traversal
- Exploiting Sorted Property

Time Complexity:
O(n)

Space Complexity:
O(n)

What I Learned:
- A sorted input often contains hidden properties that can
  eliminate the need for sorting.
- The largest squared value is always produced by one of
  the two extreme elements.
- Two pointers can reduce an O(n log n) solution to O(n).

Future Improvement:
- Simplify the implementation by removing the explicit
  equality cases. The standard two-pointer algorithm works
  correctly with only:
      if(leftSquare > rightSquare)
      else
  making the code shorter and easier to read.

Revision Note:
1. Initialize two pointers at both ends.
2. Compare the squares of both elements.
3. Place the larger square at the current position from the
   end of the answer array.
4. Move the corresponding pointer.
5. Repeat until the pointers cross.
=========================================================
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int i=0;
        int j=nums.size()-1;
        int k=j;
        while(i<=j){
         if(nums[i]*nums[i]>nums[j]*nums[j]){
            ans[k]=nums[i]*nums[i];
            k--;
           i++;
         }
         else if(nums[i]*nums[i]<nums[j]*nums[j]){
            ans[k]=nums[j]*nums[j];
            k--;
            j--;
         }
         else if(nums[i]*nums[i]==nums[j]*nums[j]&&i==j){
            ans[k]=nums[i]*nums[i];
            break;
         }
         else{
             ans[k]=nums[i]*nums[i];
             i++;
             k--;
              ans[k]=nums[j]*nums[j];
              j--;
              k--;
         }
        }
        return ans;
    }
};