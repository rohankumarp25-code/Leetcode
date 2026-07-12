/*
=========================================================
Problem: Rearrange Array Elements by Sign
Difficulty: Medium

My Approach:
- Traversed the array once to separate positive and negative
  numbers into two vectors.
- Traversed the original array again and alternately placed
  positive and negative elements back into the array.

Key Concept(s):
- Arrays
- Two-Pass Traversal
- Auxiliary Arrays

Time Complexity:
O(n)

Space Complexity:
O(n)

What I Learned:
- Separating data into temporary containers can simplify
  reconstruction problems.
- Maintaining separate indices for positive and negative
  arrays makes alternating placement straightforward.

Future Improvement:
- Construct the answer array directly without creating
  separate positive and negative vectors.

Revision Note:
1. Separate positives and negatives.
2. Traverse the array again.
3. Place positives at even indices.
4. Place negatives at odd indices.

=========================================================
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        int k = 0;
        int i = 0;
        int j = 0;
        while (k < nums.size()) {
            if (k % 2 == 0) {
                nums[k] = pos[i];
                i++;
            }
            if (k % 2 == 1) {
                nums[k] = neg[j];
                j++;
            }
            k++;
        }
        return nums;
    }
};