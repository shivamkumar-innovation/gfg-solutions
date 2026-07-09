class Solution {
public:
    const int INF = 1e9;

    int f(string &a, string &s, vector<vector<int>> &d, int i, int j) {

        if (j == s.size())
            return i - 1;

        if (i == a.size())
            return INF;

        if (d[i][j] != -1)
            return d[i][j];

        int l = INF;

        if (a[i] == s[j])
            l = f(a, s, d, i + 1, j + 1);

        int r=f(a, s, d, i + 1, j);

        return d[i][j] = min(r,l);
    }

    string minWindow(string a, string s) {

        int n = a.size();
        int m = s.size();

        if (m == 0) return "";
        if (n == 0) return "";

        vector<vector<int>> d(n, vector<int>(m, -1));

        int len = INF;
        int id = -1;

        for (int i = 0; i < n; i++) {

            if (a[i] != s[0])
                continue;

            int r = f(a, s, d, i, 0);

            if (r == INF)
                continue;

            if (r - i + 1 < len) {
                len = r - i + 1;
                id = i;
            }
        }

        if (id == -1)
            return "";

        return a.substr(id, len);
    }
};
