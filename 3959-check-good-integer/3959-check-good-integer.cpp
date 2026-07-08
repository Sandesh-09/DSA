class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0,sq_sum=0;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            sq_sum+=digit*digit;
            n=n/10;
        }
        if(sq_sum-sum>=50) return true;
        return false;
    }
};