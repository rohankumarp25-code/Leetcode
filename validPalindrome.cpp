/*
=========================================================
Problem: Valid Palindrome (LeetCode 125)
Difficulty: Easy

My Approach:
- Created a new string containing only lowercase letters and digits.
- Ignored all special characters and spaces.
- Converted uppercase letters to lowercase using ASCII arithmetic.
- Used the Two Pointers technique to check whether the processed string is a palindrome.

Key Concept(s):
- Strings
- Character Manipulation
- ASCII Conversion
- Two Pointers
- String Preprocessing

Time Complexity:
O(n)

Space Complexity:
O(n)

What I Learned:
- Preprocessing can simplify a problem significantly.
- Converting all characters into a common format makes comparison easier.
- Two Pointers provide an efficient way to check palindromes.

Mistake I Made:
- Initially, handling uppercase, lowercase, digits, and special characters together seemed complicated.
- Splitting the problem into preprocessing and palindrome checking made the implementation much simpler.

Can it be Optimized?
- Yes.
- The extra string can be avoided by directly using two pointers on the original string while skipping invalid characters.
- I will revisit this problem after learning more advanced string techniques.

Revision Note:
1. Remove all non-alphanumeric characters.
2. Convert uppercase letters to lowercase.
3. Store the processed characters.
4. Use Two Pointers to compare from both ends.
5. If all pairs match, the string is a palindrome.

=========================================================
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string dup;
        if(s==" "||s.length()==1) return true;
       for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z')
        dup.push_back(s[i]);
         if(s[i]>='A'&&s[i]<='Z')
        dup.push_back(s[i]+('a'-'A'));
        if(s[i]>='0'&&s[i]<='9')
        dup.push_back(s[i]);
       }
       int i=0;
       int j=dup.length()-1;
       while(i<j){
        if(dup[i]!=dup[j])
        return false;
        i++;
        j--;
       }
       return true;
    }
};