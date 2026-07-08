/*
=========================================================
Problem: Largest 3-Same-Digit Number in String (LeetCode 2264)
Difficulty: Easy

My Approach:
- Traversed the string once.
- Checked every group of three consecutive characters.
- If all three characters were equal, compared the digit with the best one found so far.
- Stored only the starting index of the largest valid group.
- Constructed the final answer using that index.

Key Concept(s):
- Strings
- Traversal
- Character Comparison
- Greedy Observation

Time Complexity:
O(n)

Space Complexity:
O(1)

What I Learned:
- Sometimes storing an index is enough instead of storing the complete answer.
- Since all three digits in a valid group are identical, comparing only one digit is sufficient.
- Careful observation can simplify string problems.
Can it be Optimized?
- This is already an optimal solution.

Revision Note:
1. Traverse the string.
2. Check every group of three consecutive characters.
3. Keep the index of the largest valid triple.
4. Return the corresponding three-character string.
5. If no valid triple exists, return an empty string.
=========================================================
*/


class Solution {
public:
    string largestGoodInteger(string num) {
        int track=-1;
        for(int i=0;i<num.length()-2;i++){
            if(num[i]==num[i+1]&&num[i]==num[i+2]){
                if(track==-1)
                track=i;
              else  if(num[i]>num[track])
                track=i;
            }
        }
        if(track==-1) return "";
        return {num[track],num[track],num[track]};
    }
};