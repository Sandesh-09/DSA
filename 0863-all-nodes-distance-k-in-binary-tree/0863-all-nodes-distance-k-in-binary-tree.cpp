/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> adj(501);
        build(root, adj);
        
        queue<int> q;
        vector<int> vis(501, 0);

        q.push(target->val);
        vis[target->val] = 1;

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            if (dist == k)
                break;

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

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};