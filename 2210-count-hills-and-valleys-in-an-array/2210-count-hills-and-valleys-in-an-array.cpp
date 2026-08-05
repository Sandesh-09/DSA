class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int i=0,c=0;
        for(int j=1;j<n-1;j++){            
            if(nums[j]>nums[i] && nums[j]>nums[j+1]) c++;
            else if(nums[j]<nums[i] && nums[j]<nums[j+1]){
                c++;
            } 
            else if(nums[j]==nums[j+1]){
                continue;
            }
            i=j;
        }
        return c;
    }
};