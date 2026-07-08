class Solution {
public:
    int ans = 0;

    int f(string& a, string& s, vector<vector<int>>& d, int i, int j) {
        if (i == -1 || j == -1)
            return 0;

        if (d[i][j] != -1)
            return d[i][j];

        // f(a, s, d, i - 1, j);
        // f(a, s, d, i, j - 1);

        if (a[i] == s[j])
            d[i][j] = 1 + f(a, s, d, i - 1, j - 1);
        else
            d[i][j] = 0;
            f(a, s, d, i - 1, j);
        f(a, s, d, i, j - 1);


        ans = max(ans, d[i][j]);

        return d[i][j];
    }

    int longCommSubstr(string a, string s) {
        vector<vector<int>> d(a.size(), vector<int>(s.size(), -1));

        f(a, s, d, a.size() - 1, s.size() - 1);

        return ans;
    }
};