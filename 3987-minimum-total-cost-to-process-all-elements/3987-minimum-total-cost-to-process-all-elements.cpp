class Solution {
public:
    int mod = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long r = k;
        long long total_op = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > r) {
                int need = nums[i] - r;
                int op = ceil((double)need / k);
                r += k * op;
                total_op += op;
            }
            r -= nums[i];
        }

        long long ans = ((total_op % mod) * ((total_op + 1) % mod) / 2) % mod;
        return ans;
    }
};