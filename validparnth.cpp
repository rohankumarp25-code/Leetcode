/*Problem: Valid Parentheses
Difficulty: Easy

My Approach:
Used a stack to store opening brackets. Whenever a closing bracket
was encountered, checked whether it matched the top opening bracket.
If it matched, the opening bracket was removed from the stack.
If it did not match, the string was immediately considered invalid.
After processing the entire string, the string is valid only if the
stack is empty.

Key Concepts:
- Stack
- LIFO (Last In, First Out)
- Matching parentheses
- Nested structures

Time Complexity: O(n)
Space Complexity: O(n)

What I Learned:
A stack is useful when the most recently encountered element must be
processed first. This naturally fits nested parentheses because the
last opening bracket must be closed first.

Future Improvement / Optimization Opportunity:
The algorithm is already optimal in asymptotic complexity. The
implementation can be simplified using a more compact bracket-matching
condition.

Revision Note:
For matching/nested structures, think about whether LIFO behavior is
required. If the most recent opening element must be handled first,
a stack is often the natural data structure.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(s[i]!='\0'){
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            st.push(s[i]);
            else if(!st.empty()&&st.top()=='('&&s[i]==')')
            st.pop();
            else if(!st.empty()&&st.top()=='{'&&s[i]=='}')
            st.pop();
            else if(!st.empty()&&st.top()=='['&&s[i]==']')
            st.pop();
            else
            return 0;
            i++;
        }
        if(!st.empty())
        return 0;

        return 1;
    }
};