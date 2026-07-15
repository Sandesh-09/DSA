class Solution {
public:
long long mod=1e9+7;
    vector<int> f1(vector<int>& arr, int n){
        stack<int>s;
        vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                v[i]=n;
            }
            else{
                v[i]=s.top();
            }
            s.push(i);
        }
        return v;
    }
    vector<int> f2(vector<int>& arr, int n){
        stack<int>s;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                v[i]=-1;
            }
            else{
                v[i]=s.top();
            }
            s.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=f1(arr,n);
        vector<int>pse=f2(arr,n);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long contri=(left*right)%mod;
            contri=(contri*arr[i])%mod;
            ans=(ans+contri)%mod;
        }
        return ans;
    }
};