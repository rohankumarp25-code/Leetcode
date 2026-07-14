/*
=========================================================
Problem: Remove Element
Difficulty: Easy

My Approach:
- Used a two-pointer technique to remove all occurrences of
  the given value in-place.
- Maintained one pointer from the beginning to locate
  elements equal to the target value.
- Maintained another pointer from the end to locate valid
  elements for swapping.
- Swapped unwanted elements with valid elements from the
  right side until both pointers crossed.

Key Concept(s):
- Two Pointers
- In-place Array Modification
- Swapping

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- When element order is not important, swapping with the end
  of the array is an efficient alternative to shifting
  elements.
- Two pointers moving from opposite directions can simplify
  in-place modification problems.

Revision Note:
1. Initialize left and right pointers.
2. Skip valid elements from the left.
3. Skip target elements from the right.
4. Swap when required.
5. Continue until pointers cross.

=========================================================
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;
        for (int m = 0; m < nums.size(); m++) {
            if (nums[m] == val)
                count++;
        }
        if (count == nums.size())
            return 0;
        else if (nums.size() == 1 && nums[i] != val)
            return 1;
        else {
            while (i < j) {
                if (nums[j] == val) {
                    j--;
                }
                if (nums[i] == val) {
                    swap(nums[i], nums[j]);
                    j--;
                    if (i > j)
                        return j + 1;
                }

                if (nums[i] != val) {
                    i++;
                    if (i == j && nums[i] == val)
                        return i;
                    else if (i > j)
                        return j + 1;
                }
                if (i == j)
                    return i + 1;
            }
        }
        return -1;
    }
};