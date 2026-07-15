class Solution {
public:
    vector<int> find_nse(vector<int>& arr, int n){
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
    vector<int> find_pse(vector<int>& arr, int n){
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

    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=find_nse(arr,n);
        vector<int>pse=find_pse(arr,n);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long contri=(left*right);
            contri=(contri*arr[i]);
            ans=(ans+contri);
        }
        return ans;
    }
    
    vector<int> find_nge(vector<int>& arr, int n){
        stack<int>s;
        vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<arr[i]){
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
    vector<int> find_pge(vector<int>& arr, int n){
        stack<int>s;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<=arr[i]){
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
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int>nge=find_nge(arr,n);
        vector<int>pge=find_pge(arr,n);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            long long contri=(left*right);
            contri=(contri*arr[i]);
            ans=(ans+contri);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};