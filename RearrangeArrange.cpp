#include<bits/stdc++.h>
using namespace std;                
class Solution {
public:
    int rotateString(string s, string goal) {
       if(s.length()!=goal.length()) return false;
        vector<int>hash(26,0);
        char ch;
        for(int m=0;m<s.length();m++){
            hash[s[m]-'a']++;
        }  
        for(int m=0;m<26;m++){
            if(hash[m]==1){
            ch=m+'a';
            break;
            }
        }  
        int i=0;
        for(i=0;i<s.length();i++){
            if(s[i]==ch) break;
        }
        int j=0;
         for(j=0;i<goal.length();j++){
            if(s[j]==ch) break;
        }
        int k=0;
       /* while(k<s.length()){
            if(s[i]!=goal[j]) return false;
            if(k==s.length()-1) break;
          i++;
          j++;
            k++;
            if(j==goal.length())
            j=0;
            if(i==goal.length())
            i=0;
        }*/
        return i;
    }
};
int main(){
    Solution s;
    string str1="dawhwh";
    string str2="hdawhw";
    cout<<s.rotateString(str1,str2);
}