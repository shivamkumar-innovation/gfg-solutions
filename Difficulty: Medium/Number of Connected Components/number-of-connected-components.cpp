class Solution {
public:
    int countConnected(int V, vector<vector<int>>& a) {

        vector<vector<int>> adj(V);

        int i = 0;
        while (i < a.size()) {
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
            i++;
        }

        queue<int> q;
        vector<int> vis(V, 0);

        int t = 0;
        i = 0;

        while (i < V) {
            t++;
            vis[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int b = q.front();
                q.pop();

                int j = 0;
                while (j < adj[b].size()) {
                    if (!vis[adj[b][j]]) {
                        vis[adj[b][j]] = 1;
                        q.push(adj[b][j]);
                    }
                    j++;
                }
            }

            while (i < V && vis[i] != 0) {
                i++;
            }
        }

        return t;
    }
};