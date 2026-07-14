/*
=========================================================
Problem: Divide Two Integers
Difficulty: Medium

My Approach:
- Simulated integer division using repeated subtraction.
- Converted operands to positive values to simplify the
  subtraction process.
- Carefully handled integer overflow and special cases
  involving INT_MIN, INT_MAX, zero, and sign combinations.
- Determined the final sign of the quotient based on the
  original signs of the dividend and divisor.

Key Concept(s):
- Integer Arithmetic
- Repeated Subtraction
- Edge Case Handling
- Overflow Management

Time Complexity:
O(|dividend| / |divisor|)

Space Complexity:
O(1)

What I Learned:
- Integer overflow requires careful handling when working
  with INT_MIN and INT_MAX.
- Breaking a problem into special cases can help build a
  correct solution before focusing on optimization.
- Division can be simulated without using multiplication,
  division, or modulus operators.

Future Improvement:
- Learn the optimized bit-manipulation approach to reduce
  the running time significantly.

Revision Note:
1. Handle special overflow cases.
2. Convert values to positive.
3. Perform repeated subtraction.
4. Determine the correct sign.
5. Return the quotient.
=========================================================
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-INT_MAX||divisor==dividend) return 1;
        else if(divisor==INT_MIN) return 0;
        else if(dividend==INT_MIN&&divisor==INT_MAX) return -1;
        else if(dividend==0) return 0;
        else if(dividend==INT_MIN&&divisor==-1) return -(dividend+1);
        else if(divisor==1) return dividend;
        else if(dividend!=INT_MIN){
            if(abs(dividend)<abs(divisor)) return 0;
        }
        int q=0;
        int i;
        int j;
          if(divisor<0) { j=-divisor;}
          else
         j=divisor;
        if(dividend==INT_MIN){
         i=-(dividend+j);
         q=1;
        }
      else  if(dividend<0) { i=-dividend;}
        else
        i=dividend;
       if(i>=j){
        while(i>=j){
            i=i-j;
            q++;
            if(j>i)
            break;
        }
       } 
       if((dividend<0&&divisor<0)||(dividend>0&&divisor>0)) return q;
       return -q;
    }
};