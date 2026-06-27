class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;
        int l=0,r=0;
        int ans=0;
        vector<int>v(256,0);
        while(r<n){
            while(v[s[r]]==1){
                v[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            v[s[r]]++;
            r++;
        }
        return ans;
    }
};