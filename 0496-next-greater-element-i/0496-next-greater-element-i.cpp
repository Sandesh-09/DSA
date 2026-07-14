class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {      
        int n = nums1.size();
        int m = nums2.size();

        stack<int> s;
        vector<int>ans(n);
        unordered_map<int, int> m1;
        
        for(int i=m-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                m1[nums2[i]]=-1;
            }
            else{
                m1[nums2[i]]=s.top();     
            }
            s.push(nums2[i]);
        }

        for(int i=0;i<n;i++){
            ans[i]=m1[nums1[i]];
        }
        return ans;
    }
};