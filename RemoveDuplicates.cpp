// Remove Duplicates from Sorted Array Solution
/*
=========================================================
Problem: Remove Duplicates from Sorted Array (LeetCode 26)
Difficulty: Easy

My Approach:
- Used the Two Pointers technique.
- Pointer 'i' keeps track of the position of the last unique element.
- Pointer 'j' scans the remaining elements.
- Whenever a new unique element is found, increment 'i' and swap the current unique element into its correct position.

Key Concept(s):
- Arrays
- Two Pointers
- In-place Array Modification
- Swapping

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Two Pointers can solve many array problems efficiently without using extra space.
- A sorted array allows duplicates to be detected by comparing adjacent unique elements.
- In-place modification is often preferred over using additional data structures.

Mistake I Made:
- My first accepted solution used a set, which increased space complexity.
- While trying Two Pointers, I initially overcomplicated the logic with unnecessary conditions.
- After tracing several edge cases, I realized a much cleaner approach was possible.

Can it be Optimized?
- This is the optimal solution in both time and space complexity.

Revision Note:
- Think of 'i' as the index of the last unique element.
- Let 'j' explore the array.
- When nums[j] is different from nums[i], move it to the next unique position.



=========================================================
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        return i + 1;
    }
};