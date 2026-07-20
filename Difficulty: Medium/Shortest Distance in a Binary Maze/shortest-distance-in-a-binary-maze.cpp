class Solution {
public:
    int shortestPath(vector<vector<int>> &a, vector<int> &s, vector<int> &d) {

        int n = a.size();
        int m = a[0].size();

        if (a[s[0]][s[1]] == 0 || a[d[0]][d[1]] == 0)
            return -1;

        vector<vector<int>> v(n, vector<int>(m, INT_MAX));

        queue<vector<int>> q;
        q.push({s[0], s[1]});
        v[s[0]][s[1]] = 0;

        while (!q.empty()) {

            auto t = q.front();
            q.pop();

            int i = t[0];
            int j = t[1];
            int k = v[i][j];

            if (i == d[0] && j == d[1]) {
                return v[i][j];
            }

            if (j + 1 < m) {
                if (a[i][j + 1] == 1 && v[i][j + 1] == INT_MAX) {
                    v[i][j + 1] = k + 1;
                    q.push({i, j + 1});
                }
            }

            if (j - 1 >= 0) {
                if (a[i][j - 1] == 1 && v[i][j - 1] == INT_MAX) {
                    v[i][j - 1] = k + 1;
                    q.push({i, j - 1});
                }
            }

            if (i + 1 < n) {
                if (a[i + 1][j] == 1 && v[i + 1][j] == INT_MAX) {
                    v[i + 1][j] = k + 1;
                    q.push({i + 1, j});
                }
            }

            if (i - 1 >= 0) {
                if (a[i - 1][j] == 1 && v[i - 1][j] == INT_MAX) {
                    v[i - 1][j] = k + 1;
                    q.push({i - 1, j});
                }
            }
        }

        return -1;
    }
};