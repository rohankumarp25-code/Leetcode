class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>digout=digits;
        int size = digits.size();
        if (digits[size - 1] == 9 && size > 1) {
            for (int i = size - 1; i >= 1; i--) {
                if (digits[i - 1] == 9 && digits[i] == 9) {
                    digout[i - 1] = 0;
                    digout[i] = 0;
                    if (i == 1) {
                        digout.insert(digout.begin(), 1);
                        return digout;
                    }
                }
                if (digits[i - 1] != 9 && digits[i] == 9) {
                    digout[i - 1] = digout[i - 1] + 1;
                    digout[i] = 0;
                    return digout;
                }
            }
        }
        if (digits[size - 1] != 9) {
            digout[size - 1] = digout[size - 1] + 1;
        }
        if (digits[size - 1] == 9 && size == 1) {
            digout.pop_back();
            digout.push_back(1);
            digout.push_back(0);
        }
        return digout;
    }
};