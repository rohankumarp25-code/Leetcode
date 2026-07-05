//Valid Anagram Solution
//Given two strings s and t, return true if t is an anagram of s,
//and false otherwise. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>shash(26,0);
        vector<int>thash(26,0);
        if(s.length()!=t.length())
        return false;
        else{

        for(int i=0;i<s.length();i++){
            shash[s[i]-'a']++;
            thash[t[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(shash[i]!=thash[i])
            return false;
        }
        }
        return true;
    }
};