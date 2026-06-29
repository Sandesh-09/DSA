class Solution {
public:

    int f(vector<int>& nums, int k){
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        int c=0;
        while(r<n){
            if(nums[r]%2==1) c++;
            while(c>k){
                if(nums[l]%2==1) c--;
                l++;
            }
            if(c<=k){
                ans+=r-l+1;
            }
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=f(nums,k);
        int b=f(nums,k-1);
        return a-b;
    }
};