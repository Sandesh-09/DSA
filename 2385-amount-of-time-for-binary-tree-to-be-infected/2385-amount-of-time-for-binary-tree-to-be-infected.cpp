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
void build(TreeNode* root, vector<vector<int>>& adj) {
        if (root == NULL)
            return;

        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            build(root->left, adj);
        }

        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            build(root->right, adj);
        }
    }
    
    // void f(TreeNode* root, int start,TreeNode*st){
    //     if(root==NULL) return ;
    //     if(root->val==start){
    //         st=root;
    //         return;
    //     }
    //     f(root->left,start,st);
    //     f(root->right,start,st);
    // }
    
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(1e5+1);
        build(root, adj);

        // TreeNode*st;
        // f(root,start,st);

        queue<int> q;
        vector<int> vis(1e5+1, 0);

        q.push(start);
        vis[start] = 1;

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {
                    if (!vis[nbr]) {
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }

            dist++;
        }

        
        return dist-1;
    }
};