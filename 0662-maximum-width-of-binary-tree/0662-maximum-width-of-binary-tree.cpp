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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty()){   
            long long size=q.size();
            int min_idx=q.front().second;
            long long first,last;

            for(int i=0;i<size;i++){
                TreeNode*cur=q.front().first;
                long long idx=q.front().second-min_idx;
                q.pop();

                if(i==0) first=idx;
                if(i==size-1) last=idx;
                
                if(cur->left!=NULL){
                    q.push({cur->left,2*idx});
                }
                if(cur->right!=NULL){
                    q.push({cur->right,2*idx+1});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};