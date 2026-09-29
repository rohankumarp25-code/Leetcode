/*
Problem: Maximum Nesting Depth of the Parentheses
Difficulty: Easy

My Approach:
Maintained the current parenthesis nesting depth using a variable.
Whenever an opening parenthesis '(' was encountered, the depth was
increased. Whenever a closing parenthesis ')' was encountered, the
current depth was checked against the maximum depth and then decreased.

Used top = -1 initially so that top + 1 represents the actual nesting
depth.

Key Concepts:
- String Traversal
- Parentheses
- Nesting Depth
- Greedy Tracking
- Constant-Space Traversal

Time Complexity: O(n)

Space Complexity: O(1)

What I Learned:
The maximum nesting depth can be found by maintaining the current
number of unmatched opening parentheses. There is no need to actually
use a stack because only the depth value is required.

Future Improvement / Optimization Opportunity:
The algorithm is already optimal at O(n) time and O(1) auxiliary space.
The variable could be named `depth` instead of `top` to make the intent
more immediately clear.

Revision Note:
Opening parenthesis → depth increases.
Closing parenthesis → depth decreases.
Track the maximum depth reached.
*/
class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int depth=-1;
        int i=0;
        while(s[i]!='\0'){
            if(s[i]=='(')
            depth++;
            else if(s[i]==')'){
                maxdepth=max(maxdepth,(depth+1));
                depth--;
            }
            i++;
        }
        return maxdepth;
    }
};