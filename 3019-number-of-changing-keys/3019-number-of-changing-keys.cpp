class Solution {
public:
    int countKeyChanges(string s) {
        int n=s.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(tolower(s[i])!=tolower(s[i-1])) c++;
        }
        return c;
    }
};