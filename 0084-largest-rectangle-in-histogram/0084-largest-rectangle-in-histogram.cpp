class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                int el=heights[s.top()];
                s.pop();
                int nse=i;
                int pse=s.empty()?-1:s.top();
                ans=max(ans,el*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
                int el=heights[s.top()];
                s.pop();
                int nse=n;
                int pse=s.empty()?-1:s.top();
                ans=max(ans,el*(nse-pse-1));
            }
        return ans;
    }
};