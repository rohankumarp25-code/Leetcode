/*
Problem: Count Good Numbers
Difficulty: Medium

My Approach:
Used binary exponentiation to calculate powers of 20 modulo
1e9 + 7. Multiplied by 5 when n is odd to account for the
extra even-indexed position.

Key Concepts:
- Binary exponentiation
- Modular arithmetic
- Parity
- Mathematical counting

Time Complexity: O(log n)
Auxiliary Space Complexity: O(1)

What I Learned:
Grouping positions in pairs simplifies the formula, and binary
exponentiation computes large powers efficiently.

Future Improvement:
Remove the redundant n == 1 special case and simplify the
exponentiation loop.

Revision Note:
Calculate 20^(n/2) mod M, then multiply by 5 if n is odd.
*/

class Solution {
public:
    int countGoodNumbers(long long n) {
        int m = 1e9 + 7;
        long long ans = 1;
        long long power = n / 2;
        long long x = 20;
        while (power) {
            if (power % 2) {
                ans = (ans * x) % m;
                power--;
            } else {
                x = (x * x) % m;
                power = power / 2;
            }
        }
        if (n & 1) {
            ans = (ans * 5) % m;
        }
        int res = ans;
        return res;
    }
};