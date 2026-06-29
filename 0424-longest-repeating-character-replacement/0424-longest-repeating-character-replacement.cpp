class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int ans = 0;
        int l = 0, r = 0;
        int c = 0;
        vector<int> v(26, 0);

        while (r < n) {
            v[s[r] - 'A']++;

            c = max(c, v[s[r] - 'A']);

            if((r - l + 1) - c > k) {
                v[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};