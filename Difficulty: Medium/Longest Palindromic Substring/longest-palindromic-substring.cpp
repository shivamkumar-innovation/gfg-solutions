class Solution {
public:
    int ans = 1;
    int y = 0;

    bool f(string &a, vector<vector<int>> &d, int i, int j) {

        if (i >= j)
            return true;

        if (d[i][j] != -1)
            return d[i][j];

        if (a[i] != a[j])
            return d[i][j] = false;

        bool ok = f(a, d, i + 1, j - 1);

        if (ok && j - i + 1 > ans) {
            ans = j - i + 1;
            y = i;
        }

        return d[i][j] = ok;
    }

    string getLongestPal(string a) {

        int n = a.size();

        vector<vector<int>> d(n, vector<int>(n, -1));


        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >=i; j--) {
                f(a, d, i, j);
            }
        }

        return a.substr(y, ans);
    }
};