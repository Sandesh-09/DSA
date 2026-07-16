class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string ans;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()>num[i] && k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(!s.empty() && k>0){
             s.pop();
             k--;
        }
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        if(i==ans.size()) return "0";
        return ans.substr(i);
    }
};