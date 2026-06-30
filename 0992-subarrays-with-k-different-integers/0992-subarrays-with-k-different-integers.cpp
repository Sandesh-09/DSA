class Solution {
public:
    int f(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        int l = 0, r = 0;
        unordered_map<int, int> m;

        while (r < n) {
            m[nums[r]]++;

            while (m.size() > k) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }
            
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = f(nums, k);
        int b = f(nums, k - 1);
        return a - b;
    }
};