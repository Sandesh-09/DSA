class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>v;
        v.push_back(0);
        for(auto x:nums){
            sum+=x;
            v.push_back(sum);
        }

        for(int i=0;i<n;i++){
            int left=v[i];
            int right=sum-left-nums[i];
            if(left==right) return i;
        }
        return -1;
    }
};