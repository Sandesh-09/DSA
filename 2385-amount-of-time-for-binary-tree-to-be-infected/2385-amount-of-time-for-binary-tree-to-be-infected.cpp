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

    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL) return;
        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]=root;
        }
        findParent(root->left,parent);
        findParent(root->right,parent);
    }

    void findStartNode(TreeNode* root, int start,TreeNode* &st){
        if(root==NULL) return ;
        if(root->val==start){
            st=root;
            return;
        }
        findStartNode(root->left,start,st);
        findStartNode(root->right,start,st);
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        unordered_map<TreeNode*,TreeNode*>parent;
        findParent(root,parent);
        
        TreeNode*st;
        findStartNode(root,start,st);

        queue<TreeNode*>q;
        q.push(st);
        int ans=0;
        
        unordered_map<TreeNode*,int>vis;
        vis[st]=1;

        while(!q.empty()){
            int size=q.size();
            ans++;

            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();
                q.pop();
                
                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left]=1;
                }
                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right]=1;
                }
                if(parent[cur] && !vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]]=1;
                }
            }
            
        }
        return ans-1;
    }
};