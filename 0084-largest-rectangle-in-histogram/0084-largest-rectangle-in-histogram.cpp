class Solution {
public:
    vector<int> find_nse(vector<int>& heights){
        int n=heights.size();
        stack<int>s;
        vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
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
    vector<int> find_pse(vector<int>& heights){
        int n=heights.size();
        stack<int>s;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        vector<int>nse=find_nse(heights);
        vector<int>pse=find_pse(heights);

        for(int i=0;i<n;i++){
            int right=nse[i]-i;
            int left=i-pse[i];
            int area=heights[i]*(right+left-1);
            ans=max(ans,area);
        }
        return ans;
    }
};