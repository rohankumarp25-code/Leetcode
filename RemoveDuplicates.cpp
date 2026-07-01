// Remove Duplicates from Sorted Array Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]); 
        }
        int j=0;
        for(auto it=st.begin();it!=st.end();it++){
            nums[j]=*(it);
            j++;
        }
        int k=st.size();
      
        return k;
    }
};