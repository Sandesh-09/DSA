class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0,d=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                d++;
                ans=max(ans,d);
            }
            else if(s[i]==')'){
                d--;
            }
        }
        return ans;
    }
};