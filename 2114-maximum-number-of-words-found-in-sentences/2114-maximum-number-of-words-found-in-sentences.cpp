class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;
        for(string s: sentences){
            stringstream ss(s);
            string word;
            int c=0;

            while(ss>>word){
                c++;
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};