class Solution {
public:
void f(int i,int j,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&vis){
    vis[i][j]=1;
        if(i<n-1 && grid[i+1][j]=='1' && !vis[i+1][j])  f(i+1,j,n,m,grid,vis);
        if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j])  f(i-1,j,n,m,grid,vis);
        if(j<m-1 && grid[i][j+1]=='1' && !vis[i][j+1])  f(i,j+1,n,m,grid,vis);
        if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1])  f(i,j-1,n,m,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
           for(int j=0;j<m;j++){
               if(grid[i][j]=='1' && vis[i][j]==0){
                   c++;
                   f(i,j,n,m,grid,vis);
               }
           }
        }
        return c;
    }
};