class Solution {
public:
    vector<int> g;

    void f(vector<vector<int>> &a, vector<int> &vi, int i) {

        vi[i] = 1;
        int j = 0;

        while (j < a[i].size()) {

            if (vi[a[i][j]] == 0) {
                 f(a, vi, a[i][j]);
            }
            j++;
        }

        g.push_back(i);
       return ;
    }

    vector<int> topoSort(int n,vector<vector<int>> &v) {
        vector<vector<int>> a(n);

        for (auto &edge : v) {
            int u = edge[0];
            int w = edge[1];
            a[u].push_back(w);
        }
        vector<int> vi(n, 0);
        int i = 0;

        while (i < n) {
            if (vi[i] == 0) {
                f(a, vi, i);
            }
            i++;
        }

        reverse(g.begin(), g.end());

        return g;
    }
};