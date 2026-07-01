// Richest Customer Wealth Solution
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rows = accounts.size();
        int cols = accounts[0].size();
        int maxwealth=0;
        int currentwealth=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                currentwealth=accounts[i][j]+currentwealth;
            }
            if(currentwealth>maxwealth){
                maxwealth=currentwealth;
            }
            currentwealth=0;
        }
        return maxwealth;
    }
};