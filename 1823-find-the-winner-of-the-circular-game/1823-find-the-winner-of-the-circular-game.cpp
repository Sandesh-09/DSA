class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int j=0;
        while(v.size()>1){
            for(int i=1;i<k;i++){
                j++;
                if(j==v.size()) {
                    j=0;
                }
            }
            v.erase(v.begin()+j);
            if(j==v.size()){
                j=0;
            }
        }
        return v[0];
    }
};