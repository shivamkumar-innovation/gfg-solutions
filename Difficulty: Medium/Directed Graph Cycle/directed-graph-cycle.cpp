class Solution {
public:
    bool f(vector<vector<int>> &a, vector<int> &vi, vector<int> &var, int i) {
        vi[i] = 1;
        var[i] = 1;

        bool x = 0;
        int j = 0;

        while (j < a[i].size()) {
            if (vi[a[i][j]] == 0) {
                x = f(a, vi, var, a[i][j]);
            }
            else if (var[a[i][j]] == 1) {
                return true;
            }

            if (x) {
                return true;
            }

            j++;
        }

        var[i] = 0;
        return false;
    }

    bool isCyclic(int n, vector<vector<int>> &v) {
        vector<vector<int>> a(n);

        for (auto &edge : v) {
            int u = edge[0];
            int w = edge[1];
            a[u].push_back(w);
        }

        vector<int> vi(n, 0);
        vector<int> var(n, 0);

        int i = 0;
        while (i < n) {
            if (vi[i] == 0) {
                if (f(a, vi, var, i)) {
                    return true;
                }
            }
            i++;
        }

        return false;
    }
};