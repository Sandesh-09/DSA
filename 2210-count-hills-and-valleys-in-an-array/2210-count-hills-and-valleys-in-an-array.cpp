class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        vector<int> v;

        for (int x : nums) {
            if (v.empty() || v.back() != x)
                v.push_back(x);
        }
        for (int j = 1; j < v.size() - 1; j++) {
            if (v[j] > v[j-1] && v[j] > v[j + 1])
                c++;
            else if (v[j] < v[j-1] && v[j] < v[j + 1]) {
                c++;
            }
        }
        return c;
    }
};