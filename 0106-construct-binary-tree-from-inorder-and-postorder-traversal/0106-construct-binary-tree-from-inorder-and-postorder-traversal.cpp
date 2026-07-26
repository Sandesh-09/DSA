/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* f(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int,int>&m){

        if(poststart>postend || instart>inend) return NULL;

        TreeNode*root= new TreeNode(postorder[postend]);

        int inroot=m[root->val];
        int numsleft=inroot-instart;

        root->left=f(inorder,instart,inroot-1,postorder,poststart,poststart+numsleft-1,m);
        
        root->right=f(inorder,inroot+1,inend,postorder,poststart+numsleft,postend-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=f(inorder,0,n-1,postorder,0,n-1,m);
        return root;
    }
};