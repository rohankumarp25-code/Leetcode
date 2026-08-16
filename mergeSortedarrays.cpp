/*
=========================================================
Problem: Merge Sorted Array
Difficulty: Easy
Constraint Focus: O(1) Extra Space / In-Place

My Approach:
- Used three pointers to merge nums2 into nums1 from the
  back.
- `i` points to the last valid element of nums1.
- `j` points to the last element of nums2.
- `k` points to the last available position in nums1.
- Compared nums1[i] and nums2[j].
- Placed the larger element at nums1[k] and moved the
  corresponding pointer backward.
- When elements were equal, handled both elements while
  preserving the required order.
- After one array's valid elements were exhausted, copied
  the remaining elements of nums2 into nums1.
- Handled the case where nums1 initially contains no valid
  elements separately.

Key Concept(s):
- Two Pointers
- In-Place Array Manipulation
- Merging Sorted Arrays
- Reverse Traversal

Core Observation:
nums1 already contains enough empty positions at the end
to accommodate nums2.

Instead of merging from the beginning and overwriting useful
elements in nums1, I merged from the END.

Pointers:

    i → last valid element in nums1
    j → last element in nums2
    k → last position available in nums1

At every step, place the larger of nums1[i] and nums2[j]
at nums1[k].

Why Merge Backwards?
The empty positions are at the end of nums1. Filling from
the back prevents overwriting elements that still need to
be processed.

Time Complexity:
O(m + n)

Space Complexity:
O(1) extra space

Why This Is Optimal:
Every element from the two sorted arrays may need to be
examined, giving a lower bound of O(m + n) time.

The solution modifies nums1 directly and uses only a constant
number of variables, achieving O(1) auxiliary space.

What I Learned:
- The location of available memory can determine the
  direction in which an algorithm should operate.
- Merging from the back is essential when the destination
  array contains useful elements at the beginning and empty
  positions at the end.
- Two pointers can be used not only for searching but also
  for efficiently merging sorted sequences.
- An Easy problem can become significantly more challenging
  when an O(1) extra-space constraint is imposed.
- Spending time deriving the solution independently helped
  me understand the underlying logic rather than memorizing
  the standard approach.

Problem Solving Status:
🟢 Independently Solved
🟢 Optimized for O(1) Extra Space
=========================================================
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = nums1.size() - 1;
        if (m == 0 && n > 0) {
            nums1 = nums2;
        } else if (m > 0 && n > 0) {
            while (k >= 0 && i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    swap(nums1[i], nums1[k]);
                    i--;
                } else if (nums1[i] < nums2[j]) {
                    nums1[k] = nums2[j];
                    j--;
                } else if (nums1[i] == nums2[j]) {
                    int c = nums1[i];
                    swap(nums1[i], nums1[k]);
                    k--;
                    nums1[k] = c;
                    i--;
                    j--;
                }
                k--;
            }
            if (i < 0) {
                while (k >= 0) {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            }
        }
    }
};