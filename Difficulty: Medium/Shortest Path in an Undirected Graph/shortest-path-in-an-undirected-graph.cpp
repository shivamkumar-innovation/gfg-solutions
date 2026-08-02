class Solution {
public:

    vector<vector<int>> all;
    vector<int> cur;

    void dfs(int node, int src, unordered_map<int, vector<int>> &m) {

        cur.push_back(node);

        if (node == src) {

            vector<int> t = cur;
            reverse(t.begin(), t.end());
            all.push_back(t);

            cur.pop_back();
            return;
        }

        for (auto p : m[node]) {
            dfs(p, src, m);
        }

        cur.pop_back();
    }

    vector<int> shortestPath(int V, vector<vector<int>> &a, int s, int d) {

        priority_queue<pair<int,int>, vector<pair<int,int>>,
                       greater<pair<int,int>>> p;

        vector<vector<pair<int,int>>> v(V + 1);

        vector<int> vi(V + 1, INT_MAX);

        int i = 0;

        while (i < a.size()) {

            int u = a[i][0];
            int x = a[i][1];
            int wt = a[i][2];

            v[u].push_back({x, wt});
            v[x].push_back({u, wt});

            i++;
        }

        unordered_map<int, vector<int>> m;

        p.push({0, s});
        vi[s] = 0;

        while (!p.empty()) {

            auto b = p.top();
            p.pop();

            if (b.first > vi[b.second])
                continue;

            for (auto j : v[b.second]) {

                int node = j.first;
                int wt = j.second;

                int c = b.first + wt;

                if (c < vi[node]) {

                    vi[node] = c;

                    m[node].clear();
                    m[node].push_back(b.second);

                    p.push({c, node});
                }
                else if (c == vi[node]) {

                    m[node].push_back(b.second);
                }
            }
        }

        if (vi[d] == INT_MAX)
            return {-1};

        for (auto &x : m)
            sort(x.second.begin(), x.second.end());

        dfs(d, s, m);

        sort(all.begin(), all.end());

        return all[0];
    }
};