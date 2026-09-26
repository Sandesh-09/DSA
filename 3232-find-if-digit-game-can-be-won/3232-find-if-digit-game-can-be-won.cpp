class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0;
        
        for(int i=0;i<n;i++){
            int num=nums[i];
            int c=0;
            while(num>0){
                c++;
                num=num/10;
            }
            if(c==1) b+=nums[i];
            else{
                a+=nums[i];
            }
        }
        if(b>a) return true;
        else if(a>b) return true;
        return false;
    }
};