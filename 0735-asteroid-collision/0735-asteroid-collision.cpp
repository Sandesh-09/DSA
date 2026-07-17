class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0)    s.push(asteroids[i]);
            else {
                while (!s.empty() && s.top()>0 && s.top() < abs(asteroids[i])) {
                    s.pop();
                }
                if (!s.empty() && s.top()>0 &&  s.top() == abs(asteroids[i])) {
                    s.pop();
                }
                else if(s.empty() || s.top()<0){
                    s.push(asteroids[i]);
                }
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};