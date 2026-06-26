class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            vector<int> v(26, 0);
            v[s[i] - 'a']++;

            for (int j = i + 1; j < n; j++) {
                v[s[j] - 'a']++;

                int mx = INT_MIN, mn = INT_MAX;
                for (auto x : v) {
                    if (x != 0 && x > mx) {
                        mx = x;
                    }
                    if (x != 0 && x < mn) {
                        mn = x;
                    }
                }

                if (mn == INT_MAX || mx == INT_MIN)   continue;
                sum += (mx - mn);
            }
        }
        return sum;
    }
};