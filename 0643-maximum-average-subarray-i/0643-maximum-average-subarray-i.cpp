class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        double ans=INT_MIN;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double avg=sum/k;
        ans=max(ans,avg);
        int l=0,r=k;
        while(r<n){
            sum+=nums[r];
            sum-=nums[l];
            ans=max(ans,sum/k);
            l++;
            r++;
        }
        return ans;
    }
};