/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    map<int,map<int, multiset<int>>>m;

    void f(TreeNode* root, int i, int j) {
        if (root == NULL) {
            return;
        }
        m[j][i].insert(root->val);

        f(root->left,i+1, j - 1);
        f(root->right,i+1, j + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        f(root,0,0);

        for (auto x : m) {
            vector<int> temp;
            for (auto y : x.second) {
                for(auto val:y.second){
                   temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};