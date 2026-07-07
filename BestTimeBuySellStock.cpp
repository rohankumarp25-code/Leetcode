/*
=========================================================
Problem: Best Time to Buy and Sell Stock (LeetCode 121)
Difficulty: Easy

My Approach:
- Used two pointers to represent the buying day and the current selling day.
- Kept track of the lowest buying price seen so far.
- If a lower price was found, updated the buying day.
- Otherwise, calculated the current profit and updated the maximum profit.

Key Concept(s):
- Arrays
- Two Pointers
- Greedy Thinking
- Running Maximum

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- While traversing the array, always remember the minimum price seen so far.
- Every new day can either become a better buying day or a better selling day.
- Updating the answer during traversal avoids unnecessary nested loops.

Mistake I Made:
- Initially, I thought about comparing every pair of days.
- Then I realized maintaining the minimum buying price gives an O(n) solution.

Can it be Optimized?
- This is already the optimal solution.

Revision Note:
1. Keep track of the minimum buying price.
2. For every new price, calculate the possible profit.
3. Update the maximum profit.
4. If a lower price is found, make it the new buying day.
=========================================================
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int i=0;//should point beginning day
        for(int j=i+1;j<prices.size();j++){
            if(prices[j]-prices[i]<0){
                i=j;
            }
            
            else if(prices[j]-prices[i]>0)
             profit=max(profit,prices[j]-prices[i]);
        }
        if(profit<0) return 0;
        return profit;
    }
};