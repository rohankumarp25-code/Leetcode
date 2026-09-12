class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1)
            return s.length();
        vector<int> hash(256, 0);
        int maxlen = 0;
        int currlen = 0;
        int i = 0;
        int j = 0;
        int dup = 0;
        while (s[j] != '\0') {
            if (dup == 0) {
                hash[s[j]]++;
                if (hash[s[j]] == 2)
                    dup++;
                if (dup == 0) {
                    currlen = j - i + 1;
                    maxlen = max(currlen, maxlen);
                    j++;
                }
            } else if (dup != 0) {
                hash[s[i]]--;
                if (hash[s[i]] == 1)
                    dup--;
                i++;
                if (dup == 0) {
                    currlen = j - i + 1;
                    maxlen = max(currlen, maxlen);
                    j++;
                }
            }
        }
        return maxlen;
    }
};