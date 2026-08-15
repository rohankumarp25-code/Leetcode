/*
=========================================================
Problem: String to Integer (atoi)
Difficulty: Medium

My Approach:
- Processed the string from left to right.
- Ignored leading whitespace before the number starts.
- Used a sign variable to handle '+' and '-'.
- Once the number begins, processed consecutive digits
  one by one.
- Constructed the integer using:

    compute = compute * 10 + digit

- Stopped processing when an invalid character was
  encountered after the number had started.
- Used long long for intermediate computation to help
  detect integer overflow.
- Returned INT_MAX when the positive result exceeded the
  integer limit.
- Returned INT_MIN when the negative result went below
  the integer limit.

Key Concept(s):
- String Traversal
- Character Validation
- Integer Construction
- Overflow Handling
- State Tracking

Core Observation:
A valid integer can be constructed digit-by-digit using:

    current = current * 10 + digit

The input must be processed in the correct order:
leading spaces → optional sign → digits → stop at the
first invalid character.

Time Complexity:
O(n)

Space Complexity:
O(1)

Why This Is Optimal:
In the worst case, the input string must be scanned to
determine the valid numeric portion, so O(n) time is
necessary. Only a constant number of variables are used.

What I Learned:
- Careful state management is important when a problem has
  many edge cases.
- Integer overflow must be considered while constructing
  numbers digit-by-digit.
- Input parsing problems can often be solved with a single
  left-to-right traversal.
- The order of conditions matters when processing strings
  containing spaces, signs, digits, and invalid characters.

Problem Solving Status:
🟢 Independently Solved


=========================================================
*/
class Solution {
public:
    int myAtoi(string s) {
        int number = 0;
        long long int compute = 0;
        int sign = 1;
        int found = 0;
        int plus = 0;
        int minus = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ' && found == 0)
                continue;
            else if (s[i] == '-' && found == 0) {
                sign = -1;
                minus++;
                found = 1;
                continue;
            } else if (s[i] == '+' && found == 0) {
                plus++;
                found = 1;
                continue;
            }
            if (plus == 1 && minus == 1)
                break;
            if (s[i] != '0' && s[i] != ' ' && !(s[i] >= '0' && s[i] <= '9'))
                break;
            if (found == 1 && !(s[i] >= '0' && s[i] <= '9'))
                break;
            if (s[i] >= '0' && s[i] <= '9') {
                found = 1;
                compute = compute * 10 + s[i] - '0';
                if (compute * sign > INT_MAX)
                    return INT_MAX;
                else if (sign * compute < INT_MIN)
                    return INT_MIN;
            }
        }
        number = compute * sign;
        return number;
    }
};