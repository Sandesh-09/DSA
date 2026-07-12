class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        vector<vector<char>>v(m,vector<char>(n,'#'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 || i==m-1){
                    v[i][j]='.';
                }
            }
        }
        for(int i=0;i<m;i++){
            string s;
            for(int j=0;j<n;j++){
                s+=v[i][j];
            }
            ans.push_back(s);
        }
        return ans;
    }
};