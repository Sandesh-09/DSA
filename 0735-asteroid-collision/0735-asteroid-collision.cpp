class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>ans;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(asteroids[i]<0 && !s.empty() && s.top()<abs(asteroids[i])){
                s.pop();
            }
            if(asteroids[i]<0 && !s.empty() && s.top()==abs(asteroids[i])){
                s.pop();
                continue;
            }
            if(asteroids[i]>0){
                s.push(asteroids[i]);
                continue;
            }
            if(s.empty()){
                ans.push_back(asteroids[i]);
            }
        }

        vector<int>v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        for(int i=v.size()-1;i>=0;i--){
            ans.push_back(v[i]);
        }
        return ans;
    }
};