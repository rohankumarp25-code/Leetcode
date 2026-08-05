/*
=========================================================
Problem: Find Missing Elements
Difficulty: Easy

My Approach:
- Traversed the array once to find the minimum and maximum
  elements.
- Created a frequency array whose indices represent values
  between the minimum and maximum elements.
- Marked every element present in the array.
- Traversed the frequency array and added all values with
  zero frequency to the answer.

Key Concept(s):
- Frequency Array
- Array Traversal
- Constraint-Based Optimization

Time Complexity:
O(n)

Space Complexity:
O(1)
(The frequency array size is bounded by the problem
constraints: values range from 1 to 100.)

What I Learned:
- Reading the constraints before choosing a data structure
  can lead to a simpler and more efficient solution.
- A frequency array is often preferable to a hash-based
  container when the value range is small and fixed.
- Shifting indices by the minimum value allows efficient
  representation of any contiguous range.

Future Improvement:
- Initialize the minimum and maximum values using the first
  array element instead of fixed constants to make the code
  more reusable for different constraints.

Revision Note:
1. Find the minimum and maximum values.
2. Create a frequency array for the value range.
3. Mark all present elements.
4. Traverse the frequency array.
5. Collect all missing values.
=========================================================
*/
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int large = 0;
        int small = 101;
        for (int i = 0; i < nums.size(); i++) {
            large = max(large, nums[i]);
            small = min(small, nums[i]);
        }
        vector<int> hash(large - small + 1, 0);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i] - small]++;
        }
        for (int i = 0; i <= large - small; i++) {
            if (hash[i] == 0)
                ans.push_back(i + small);
        }
        return ans;
    }
};