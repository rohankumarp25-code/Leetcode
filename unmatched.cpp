/*
Problem: Minimum Add to Make Parentheses Valid
Difficulty: Medium

My Approach:
I maintained two counters:
- open: number of unmatched '('
- insert: number of ')' that need an opening '(' inserted

Whenever a ')' appears with no unmatched '(', I increment insert.
After scanning the string, all remaining unmatched '(' require closing ')'.

Key Concepts:
- Greedy
- Parentheses balancing
- Counter technique
- String traversal

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
The stack is unnecessary when only the number of unmatched parentheses
matters. A simple counter can track the balance.

Future Improvement:
The code can be simplified slightly by removing the redundant
`else if(open > 0)` condition.

Revision Note:
Track unmatched '(' → handle invalid ')' → add remaining '('.
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int insert=0;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='(')
            open++;
            else if(s[i]==')'){
                if(open==0)
                insert++;
                else if(open>0)
                open--;
            }
        }
       insert=insert+open;
        
        return insert;
    }
};