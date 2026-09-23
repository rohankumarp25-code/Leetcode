/*
Problem: Evaluate Reverse Polish Notation
Difficulty: Medium

My Approach:
Used a stack to evaluate the RPN expression from left to right.
Whenever a number is encountered, I manually parse the string and push
the resulting integer onto the stack. Whenever an operator is encountered,
I pop the top two operands, perform the corresponding operation while
maintaining the correct operand order for subtraction and division, and
push the result back onto the stack.

Key Concepts:
- Stack
- Reverse Polish Notation
- Expression Evaluation
- Operand Ordering
- String Parsing

Time Complexity: O(n)

Space Complexity: O(n)

What I Learned:
RPN expressions can be evaluated naturally using a stack because an
operator always operates on the two most recently available operands.
For subtraction and division, the first popped value is the right
operand and the second popped value is the left operand.

I also practiced manually parsing numeric strings, including negative
numbers, instead of relying on a built-in conversion function.

Future Improvement / Optimization Opportunity:
The O(n) time and O(n) space complexity is optimal for this approach.
The code could be made shorter and cleaner by using a standard string
conversion method such as stoi(), but the current implementation helped
me understand the parsing process.

Revision Note:
Remember:
First pop → right operand
Second pop → left operand

For example:
10 2 / → 10 / 2
10 2 - → 10 - 2

Problem Solving Rating: 9/10*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        int a, b;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i][0] == '+' ||
                (tokens[i][0] == '-' && tokens[i][1] == '\0') ||
                tokens[i][0] == '*' || tokens[i][0] == '/') {
                a = res.top();
                res.pop();
                b = res.top();
                res.pop();
                if (tokens[i][0] == '+')
                    res.push(a + b);
                else if (tokens[i][0] == '-')
                    res.push(b - a);
                else if (tokens[i][0] == '*')
                    res.push(a * b);
                else if (tokens[i][0] == '/' && a != 0)
                    res.push(b / a);
            } else {
                int value = 0;
                int j = 0;
                while (tokens[i][j] != '\0') {
                    if (tokens[i][j] != '-')
                        value = value * 10 + tokens[i][j] - '0';
                    j++;
                }
                if (tokens[i][0] == '-')
                    res.push(-value);
                else
                    res.push(value);
            }
        }
        return res.top();
    }
};