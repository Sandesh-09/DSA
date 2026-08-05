class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, int& c,
             vector<int>& comp) {
        vis[i] = 1;
        comp.push_back(i);
        c++;
        for (auto x : adj[i]) {
            if (!vis[x]) {
                dfs(x, adj, vis, c, comp);
            }
        }
    }

    bool check(vector<vector<int>>& adj, vector<int>& comp, int& c) {
        for (int j = 0; j < comp.size(); j++) {
            if (adj[comp[j]].size() != c - 1) {
                return false;
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            int c = 0;
            vector<int> comp;
            if (!vis[i]) {
                dfs(i, adj, vis, c, comp);
                if (check(adj, comp, c))
                    ans++;
            }
        }

        return ans;
    }
};