/* 
Problem: Max Consecutive Ones III
Difficulty: Medium

My Approach:
Used a variable-size sliding window with two pointers, start and end.
Expanded the window while the number of zeroes was within the allowed
limit k. When another zero was encountered after all flips were used,
moved start forward until the earliest zero in the current window was
removed, thereby restoring the valid window.

Key Concepts:       
- Sliding Window
- Two Pointers
- Maintaining a valid window
- Greedy removal of the earliest zero

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
A sliding window does not always require explicitly storing the number
of elements/frequencies. The window can sometimes be maintained directly
by moving the left pointer to remove the element that violates the
constraint.

Future Improvement / Optimization Opportunity:
The algorithm is already asymptotically optimal: O(n) time and O(1)
auxiliary space. The implementation could be simplified for readability.

Revision Note:
When the window becomes invalid, don't restart the search. Move the left
pointer only as much as necessary to restore the window's validity.

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        int maxlen=0;
        while(end!=nums.size()){
            if(nums[end]==1){
                maxlen=max(maxlen,end-start+1);
                end++;
            }
            else if(nums[end]==0&&k!=0){
                k--;
                maxlen=max(maxlen,end-start+1);
                end++;
            }
            else if(nums[end]==0&&k==0){
                while(nums[start]!=0)
                start++;
                start++;
                maxlen=max(maxlen,end-start+1);
                end++;
            }
        }
        return maxlen;
    }
};
