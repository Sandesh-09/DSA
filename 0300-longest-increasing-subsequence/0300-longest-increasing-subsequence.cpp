class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int last = i - 1; last >= -1; last--) {
                int not_take = dp[i + 1][last+1];
                int take = 0;
                if (last == -1 || nums[i] > nums[last]) {
                    take = 1 + dp[i + 1][i+1];
                }
                dp[i][last + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
};