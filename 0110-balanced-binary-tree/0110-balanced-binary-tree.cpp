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
    int f(TreeNode* root) {
        if (root == NULL)    return 0;

        int left = f(root->left);
        int right = f(root->right);

        if(left==-1 || right==-1) return -1;
        if (abs(left - right) > 1)    return -1;
        
        return 1 + max(f(root->left), f(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)    return true;
        return f(root)!=-1;
    }
};