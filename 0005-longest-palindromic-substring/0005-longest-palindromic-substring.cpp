class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int l=i;
                int r=j;
                int c=0;
                 while(l<=r){
                    if(s[l]!=s[r]){
                        c=1;
                        break;
                    }
                    l++;
                    r--;
                 }
                 if(!c){
                    if(j-i+1>ans.size()){
                       ans=s.substr(i,j-i+1);
                    }
                 }
            }
        }
        return ans;
    }
};