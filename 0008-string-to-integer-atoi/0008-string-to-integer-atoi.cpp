class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        char sign = '+';
        string ans;
        int i = 0, a = 0;

        for (i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            } 
            else if (s[i] == '+' || s[i] == '-') {
                sign = s[i];
                a = 1;
                break;
            } 
            else if (isalpha(s[i])) {
                return 0;
            } 
            else {
                break;
            }
        }

        bool b = false;
        int j = i;
        if (a)   j = i + 1;

        for (j; j < n; j++) {
            if (!isdigit(s[j]))    break;
            if (!b && (s[j] - '0') == 0) {   
                continue;
            } 
            else {
                b = true;
                ans += s[j];
            }
        }

        int m = ans.size();
        i = 0;
        long long val = 0;

        while (i < m) {
            int digit = ans[i] - '0';
            if (val > (long long)INT_MAX + 1)
                break;
            val = val * 10 + digit;
            i++;
        }

        if (sign == '-') {
            if (val > (long long)INT_MAX + 1)
                return INT_MIN;
            return -val;
        } 
        else {
            if (val > INT_MAX)
                return INT_MAX;
            return val;
        }
        return 0;
    }
};