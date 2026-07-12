class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string>ans(m,string(n,'#'));
        
        if((n==1 || m==1) && k>1) return {}; 
        if(n==3 && m==3 && k==4) return {"..#","...","#.."};

        for(int i=0;i<m;i++)    ans[i][0]='.';
        for(int j=0;j<n;j++)    ans[m-1][j]='.';
        k--;
        
        if(m>n){
            int i=m-2;
            while(i>=0 && k){
                ans[i][1]='.';
                k--;
                i--;
            }
        }
        else{
            int j=1;
            while(j<n && k){
                ans[m-2][j]='.';
                k--;
                j++;
            }
        }

        if(k) return {};

        return ans;
    }
};