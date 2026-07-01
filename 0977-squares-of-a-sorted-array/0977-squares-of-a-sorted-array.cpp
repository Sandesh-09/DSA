class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
           int sq=nums[i]*nums[i];
           nums[i]=sq;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};