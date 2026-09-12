class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            string n=s;
            reverse(n.begin(),n.end());
            if(n==s) return n;
        }
        return "";
    }
};