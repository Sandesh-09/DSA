class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int ans=0;
        int l=0,r=0;
        unordered_map<int,int>m;
        while(r<n){
            if(m.find(fruits[r])==m.end() && m.size()==2){
                int c=fruits[l];
                while(m[c]>0){
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0){
                        m.erase(fruits[l]);
                        l++;
                        break;
                    }
                    l++;
                }      
            }
            ans=max(ans,r-l+1);
            m[fruits[r]]++;
            r++;
        }
        return ans;
    }
};