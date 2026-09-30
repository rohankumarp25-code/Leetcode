/*
Problem: Remove Outermost Parentheses
Difficulty: Easy

My Approach:
Used a variable to track the current nesting depth instead of using an
actual stack.

For every opening parenthesis, I checked whether it was an outermost
parenthesis. If the current depth was greater than zero, the parenthesis
was part of the inner structure and was added to the answer.

For closing parentheses, I added them only when they were not the final
outermost closing parenthesis of the primitive group.

Key Concepts:
- String Traversal
- Parentheses
- Nesting Depth
- Primitive Decomposition
- Constant-Space Auxiliary Logic

Time Complexity: O(n)

Space Complexity: O(n) for the output string
Auxiliary Space: O(1)

What I Learned:
The outermost parentheses of every primitive can be identified by
tracking the current nesting depth. An explicit stack is unnecessary
when only the depth information is required.

Future Improvement / Optimization Opportunity:
The algorithm is already optimal in time and auxiliary space. The
variable `top` could be renamed to `depth` to make the code more
readable and directly represent what it tracks.

Revision Note:
For every primitive:
- First '(' → exclude
- Inner parentheses → include
- Final ')' → exclude

*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int top=-1;
        int i=0;
        while(s[i]!='\0'){
            if(s[i]=='('){
               if(top>=0)
                 ans=ans+s[i];
                top++;
            }
            else if(s[i]==')'&&top>0){
                ans=ans+(s[i]);
                top--;
            }
            else if(s[i]==')'&&top==0)
            top--;
            i++;
        }
        return ans;
    }
};