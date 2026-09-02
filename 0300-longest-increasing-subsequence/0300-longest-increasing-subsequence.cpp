class Solution {
public:
    int f(int i, int last, vector<int>& nums,vector<vector<int>>&dp){
        int n=nums.size();

        if(i==n) return 0;
        if(dp[i][last+1]!=-1){
            return dp[i][last+1];
        }

        int not_take=f(i+1,last,nums,dp);
        int take=0;
        if(last==-1 || nums[i]>nums[last]){
            take=1+f(i+1,i,nums,dp);
        }
        return dp[i][last+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};