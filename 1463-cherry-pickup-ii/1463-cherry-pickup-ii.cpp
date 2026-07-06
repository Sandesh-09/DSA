class Solution {
public:
    int f(int i, int j, int k, vector<vector<int>>& grid, vector<int>&v,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size(); 

        if(j<0 || j>=m || k<0 || k>=m){
            return -1e9;
        }
        if(i==n-1){
            if(j==k) return grid[i][j];
            else{
                return grid[i][j]+grid[i][k];
            }
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
            
        int maxi=INT_MIN;
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                if(j==k){
                    maxi=max(maxi,grid[i][j]+f(i+1,j+v[p],k+v[q],grid,v,dp));
                }
                else{
                    maxi=max(maxi,grid[i][j]+grid[i][k]+f(i+1,j+v[p],k+v[q],grid,v,dp));
                }
            }
        }
        return dp[i][j][k]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>v={-1,0,1};
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,v,dp);
    }
};