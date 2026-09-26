class Solution {
public:
    int subtractProductAndSum(int n) {
        int a = 0, b = 1;
        while (n > 0) {
            int d = n % 10;
            a += d;
            b *= d;
            n = n / 10;
        }
        return b - a;
    }
};