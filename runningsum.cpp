// Running Sum of 1d Array Solution
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> run(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                run[i] = nums[i];
            if (i > 0)
                run[i] = run[i - 1] + nums[i];
        }
        return run;
    }
};