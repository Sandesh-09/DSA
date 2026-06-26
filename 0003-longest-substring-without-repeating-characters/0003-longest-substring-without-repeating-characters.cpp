class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;

        int maxi = INT_MIN;
        vector<int> v(256, 0);
        int k = 0;
        for (int i = 0; i < n; i++) {
            v[s[i]]++;
            int c = 0;
            bool a=true;
            for (int j = 0; j < 256; j++) {
                if (v[j] > 1) {
                    a = false;
                    v[s[k]]--;
                    k++;
                    break;
                }
                if (v[j] == 1)
                    c++;
            }
            if (a)
                maxi = max(maxi, c);
        }
        return maxi;
    }
};