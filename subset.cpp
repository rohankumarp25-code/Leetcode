/*
Problem: Subsets
Difficulty: Medium

My Approach:
Used bitmask enumeration to generate every subset. Each integer
from 0 to 2^n - 1 represents a subset, where a set bit indicates
that the corresponding array element is included.

Key Concepts:
- Bit manipulation
- Bitmasking
- Subset enumeration
- Combinatorics

Time Complexity: O(n * 2^n)
Auxiliary Space Complexity: O(n)
Output Space Complexity: O(n * 2^n)

What I Learned:
Binary masks can represent all possible combinations of elements.

Future Improvement:
Explore recursive backtracking and compare its implementation
with bitmask enumeration.

Revision Note:
Enumerate masks → test each bit → construct the corresponding subset.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=nums.size();
        int k=1<<n;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                if((1<<j)&i)
                temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};