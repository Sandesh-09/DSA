class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;

        for(string s:sentences){
            int n=s.size();
            int c=1;
            for(int i=0;i<n;i++){
                if(s[i]==' ') c++;
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};