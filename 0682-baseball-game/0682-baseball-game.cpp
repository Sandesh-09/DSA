class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>v;
        int n=operations.size();
        for(int i=0;i<n;i++){
            if(operations[i]=="C"){
                v.pop_back();
            }
            else if(operations[i]=="D"){
                v.push_back(2*v.back());
            }
            else if(operations[i]=="+"){
                int m=v.size();
                v.push_back(v[m-1]+v[m-2]);
            }
            else{
                v.push_back(stoi(operations[i]));
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
        return ans;
    }
};