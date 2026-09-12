class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int dsum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int num=nums[i];
            while(num>0){
                dsum+=num%10;
                num=num/10;
            }
        }
        return abs(sum-dsum);
    }
};