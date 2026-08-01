class Solution {
public:
    vector<int> g;

    void f(vector<vector<pair<int,int>>> &v, vector<int> &vis, int i) {

        vis[i] = 1;

        int j = 0;
        while (j < v[i].size()) {

            if (vis[v[i][j].first] == 0) {
                f(v, vis, v[i][j].first);
            }

            j++;
        }

        g.push_back(i);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &a) {

        vector<vector<pair<int,int>>> v(V);

        int i = 0;
        while (i < E) {

            int u = a[i][0];
            int x = a[i][1];
            int wt = a[i][2];

            v[u].push_back({x, wt});

            i++;
        }

        vector<int> vis(V, 0);

        i = 0;
        while (i < V) {
            if (vis[i] == 0)
                f(v, vis, i);
            i++;
        }

        reverse(g.begin(), g.end());

        vector<int> vi(V, INT_MAX);
        vi[0] = 0;

        i = 0;
        while (i < g.size()) {

            int node = g[i];

            if (vi[node] != INT_MAX) {

                int j = 0;

                while (j < v[node].size()) {

                    int x = v[node][j].first;
                    int wt = v[node][j].second;

                    if (vi[node] + wt < vi[x]) {
                        vi[x] = vi[node] + wt;
                    }

                    j++;
                }
            }

            i++;
        }

        i = 0;
        while (i < V) {

            if (vi[i] == INT_MAX)
                vi[i] = -1;

            i++;
        }

        return vi;
    }
};
