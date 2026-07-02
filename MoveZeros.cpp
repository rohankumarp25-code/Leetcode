//Move Zeroes Solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=i+1;j<=nums.size()-1;j++){
            if(nums[i]==0&&nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
            if(nums[i]!=0)
            i++;
            
        }
    }
};