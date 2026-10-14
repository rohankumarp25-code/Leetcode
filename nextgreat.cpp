/*Problem: Next Greater Element I
Difficulty: Easy

My Approach:
Processed nums2 from right to left using a stack to find the next
greater element for each value. Stored the result in a direct-indexed
array and used nums1 to retrieve the answers.

Key Concepts:
- Monotonic stack
- Right-to-left traversal
- Precomputation
- Direct-indexed lookup

Time Complexity: O(N + M + K)
Space Complexity: O(N + M + K), including the answer

What I Learned:
Precomputing next greater elements lets each query be answered
in constant time.

Future Improvement:
Investigate whether the auxiliary note stack and restoration steps
can be eliminated.

Revision Note:
Traverse right to left → maintain candidate elements → precompute
next greater elements → answer queries.

*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        int maxi = 0;
        for (int j = 0; j < nums2.size(); j++) {
            maxi = max(maxi, nums2[j]);
        }
        vector<int> next(maxi + 1, 0);
        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (i == nums2.size() - 1)
                next[nums2[i]] = -1;
            else {
                while (!st.empty() && st.top() < nums2[i]) {
                    st.pop();
                }
                if (st.empty())
                    next[nums2[i]] = -1;
                else
                    next[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(next[nums1[i]]);
        }
        return ans;
    }
};