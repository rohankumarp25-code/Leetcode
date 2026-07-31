/*
=========================================================
Problem: Find Greatest Common Divisor of Array
Difficulty: Easy

My Approach:
- Traversed the array once to find the minimum and maximum
  elements.
- Started checking from the smaller element downwards.
- Returned the first number that divides both the minimum
  and maximum elements, which is the Greatest Common Divisor.

Key Concept(s):
- Array Traversal
- Mathematical Observation
- Brute Force Divisor Search

Time Complexity:
O(n + min(minElement, maxElement))

Space Complexity:
O(1)

What I Learned:
- The GCD of an array depends only on its minimum and
  maximum elements.
- A straightforward solution can be derived directly from
  the mathematical definition of GCD.
- Although correct, this approach can be optimized using
  Euclid's Algorithm.

Future Improvement:
- Learn and implement Euclid's Algorithm to compute the GCD
  in O(log(min(a, b))) time instead of checking every
  possible divisor.

Revision Note:
1. Find the minimum and maximum elements.
2. Start from the smaller value.
3. Check divisibility of both numbers.
4. Return the first common divisor found.
=========================================================
*/
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=1001;
        int large=0;
        for(int i=0;i<nums.size();i++){
            small=min(nums[i],small);
            large=max(nums[i],large);
        }
        int n=small;
        while(n!=0){
            if(large%n==0&&small%n==0)
            return n;
            else
            n--;
        }
        return 0;
    }
};