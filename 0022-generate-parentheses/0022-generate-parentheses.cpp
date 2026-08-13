class Solution {
public:

    bool check(string s){
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
               if(!st.empty()) st.pop();
               else{
                return false;
               }
            }
        }
        if(st.empty()) return true;
        return false;
    }

    void f(int i,string str,vector<string>& ans){
        if(i==0){
            if(check(str)==true){
                ans.push_back(str);      
            }
            return;
        }
        f(i-1,str+'(',ans);
        f(i-1,str+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(2*n,"",ans);
        return ans;
    }
};