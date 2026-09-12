class Solution {
public:
    int f(int i,int a,vector<int>& coins,vector<vector<int>>&dp){
        if(i<0){
            if(a==0) return 1;
            return 0;
        }
        if(dp[i][a]!=-1) return dp[i][a];

        int not_take=f(i-1,a,coins,dp);
        int take=0;
        if(a>=coins[i]){
            take=f(i,a-coins[i],coins,dp);
        }
        return dp[i][a]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};