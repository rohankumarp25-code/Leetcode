//Rotate Array Solution
/*
Problem: Rotate Array

Approach:
- Solved independently.
- Considered multiple edge cases.
- Used an auxiliary vector to rotate the array.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
This is my first accepted solution. I plan to revisit it after learning more advanced array techniques.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> dup = nums;
        int n = nums.size();
        if (n == k) {
            nums = dup;
        } else if (n > 1 && (k <= n / 2)) {
            k = k % n;
            for (int i = 0; i < k; i++) {
                nums[i] = dup[n - k + i];
            }
            for (int i = 0; i < k; i++) {
                nums[i + k] = dup[i];
            }
            for (int i = 0; i < n - 2 * k; i++) {
                nums[2 * k + i] = dup[i + k];
            }
        } else if (n > 1 && k > n && (k % n) <= n / 2) {
            k = k % n;
            for (int i = 0; i < k; i++) {
                nums[i] = dup[n - k + i];
            }
            for (int i = 0; i < k; i++) {
                nums[i + k] = dup[i];
            }
            for (int i = 0; i < n - 2 * k; i++) {
                nums[2 * k + i] = dup[i + k];
            }
        } else if (n > 1 && k > n / 2) {
            k = k % n;
            for (int i = 0; i < n - k; i++) {
                nums[i + k] = dup[i];
            }
            for (int i = 0; i < 2 * k - n; i++) {
                nums[i] = dup[n - k + i];
            }
            for (int i = 0; i < n - k; i++) {
                nums[2 * k - n + i] = dup[i + k];
            }
        } else if (n > 1 && k > n && (k % n) > n / 2) {
            k = k % n;
            for (int i = 0; i < n - k; i++) {
                nums[i + k] = dup[i];
            }
            for (int i = 0; i < 2 * k - n; i++) {
                nums[i] = dup[n - k + i];
            }
            for (int i = 0; i < n - k; i++) {
                nums[2 * k - n + i] = dup[i + k];
            }
        }
    }
};