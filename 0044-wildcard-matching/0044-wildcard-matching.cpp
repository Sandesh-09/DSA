class Solution {
public:
    bool f(int i, int j, string& s, string& p,vector<vector<int>>&dp) {
        if (i == 0 && j == 0)
            return true;
        if (j == 0)
            return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0) {
            if(p[j-1]=='*'){
               return dp[i][j]=f(i,j-1,s,p,dp);
            }
            else{
                return false;
            }
        }
        
        if (s[i-1] == p[j-1] || p[j-1] == '?') {
            return dp[i][j]=f(i - 1, j - 1, s, p,dp);
        }
        
        bool op1 = false;
        bool op2 = false;
        if (p[j-1] == '*') {
            op1 = f(i - 1, j, s, p,dp);
            op2 = f(i, j - 1, s, p,dp);
        }
        return dp[i][j]=op1 || op2;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n , m , s, p,dp);
    }
};