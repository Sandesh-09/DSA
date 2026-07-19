class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans=0;
        if(n==1) return s;
        ans=s+(1LL*(n/2)*m)-((n/2)-1);
        return ans;
    }
};