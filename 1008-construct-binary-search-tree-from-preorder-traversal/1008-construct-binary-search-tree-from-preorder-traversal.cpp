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

    TreeNode* f(vector<int>& preorder,int prestart, int preend, vector<int>&inorder, int instart, int inend,unordered_map<int,int>&m){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=m[preorder[prestart]];
        int numsleft=inroot-instart;
        root->left=f(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,m);
        root->right=f(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,m);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }

        return f(preorder,0,n-1,inorder,0,n-1,m);
    }
};