/*
=========================================================
Problem: Pascal's Triangle
Difficulty: Easy

My Approach:
- Generated Pascal's Triangle row by row.
- Created a vector of size i + 1 for every row.
- Set the first and last elements of every row to 1.
- Calculated every middle element using the previous row:
    
    ans[i-1][j-1] + ans[i-1][j]

- Added each completed row to the answer.

Key Concept(s):
- 2D Vectors
- Dynamic Row Construction
- Array Indexing
- Pascal's Triangle Pattern

Core Observation:
Every middle element of Pascal's Triangle is the sum of the
two elements directly above it:

    triangle[i][j] =
        triangle[i-1][j-1] + triangle[i-1][j]

The boundary elements are always 1.

Time Complexity:
O(n²)

Space Complexity:
O(n²) including the output.

Important Note:
Since the output itself contains O(n²) elements, O(n²)
space is necessary to store the complete triangle.

What I Learned:
- A problem can often be solved by constructing the current
  state from the previously computed state.
- The structure of Pascal's Triangle naturally leads to a
  row-by-row dynamic construction.
- Understanding the relationship between adjacent rows makes
  the implementation straightforward.
=========================================================
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> push(i + 1, 0);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    push[j] = 1;
                else
                    push[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(push);
        }
        return ans;
    }
};