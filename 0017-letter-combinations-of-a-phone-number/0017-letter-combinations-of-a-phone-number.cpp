class Solution {
public:
    void f(int i,string digits,vector<string>& v,string& str,vector<string>&ans){
        if(i==digits.size()){
            ans.push_back(str);
            return;
        }
        int c=digits[i]-'0';
        string s=v[c-2];
        for(auto x:s){
            str+=x;
            f(i+1,digits,v,str,ans);\
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>ans;
        string str;
        vector<string> v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,digits,v,str,ans);
        return ans;
    }
};