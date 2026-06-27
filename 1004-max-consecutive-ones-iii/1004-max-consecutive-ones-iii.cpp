class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        int c=0,idx=-1;
        while(r<n){
            if(nums[r]==0){
                c++;
            }
            while(c>k){
                if(nums[l]==0) c--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};