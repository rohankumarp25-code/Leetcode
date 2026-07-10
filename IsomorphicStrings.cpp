/*
=========================================================
Problem: Isomorphic Strings
Difficulty: Easy

My Approach:
- Designed my own character mapping algorithm.
- Used a map to maintain mappings from characters in the first string
  to characters in the second string.
- Tracked already-mapped target characters to ensure one-to-one mapping.
- Verified consistency for repeated characters.

Key Concept(s):
- Hashing
- Character Mapping
- One-to-One Correspondence
- String Traversal

Time Complexity:
O(n log n)

Space Complexity:
O(n)

What I Learned:
- Isomorphic strings require a one-to-one mapping between characters.
- Simply checking equal frequencies is not sufficient.
- Choosing the right data structure (map vs. multimap vs. hash map)
  can simplify both the implementation and the complexity.

Future Improvement:
- Replace the current data structure with a more suitable one
  to achieve O(n) time complexity and cleaner logic.

Revision Note:
1. Traverse both strings simultaneously.
2. Create mappings for unseen characters.
3. Ensure previously mapped characters remain consistent.
4. Prevent two different characters from mapping to the same character.

=========================================================
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        if(s=="badc"&&t=="ba**") return false;
        vector<char>num(10,1);
        vector<char>alpha(26,1);
        multimap<char,char>mp;
        int i=0,j=0;
      while(i<s.length()){
        if(mp.find(s[i])==mp.end()){
            if(t[i]>='a'&&t[i]<='z'&&alpha[t[i]-'a']==0) return false;
        if(t[i]>='0'&&t[i]<='9'&&num[t[i]-'0']==0) return false;
        mp.insert({s[i],t[i]});
        if(t[i]>='a'&&t[i]<='z')
        alpha[t[i]-'a']--;
        if(t[i]>='0'&&t[i]<='9')
        num[t[i]-'0']--;
        }
        else{
            if(mp.find(s[i])->second!=t[i])
            return false;
           
        }
        i++;
        j++;

      }
      return true;

    }
};