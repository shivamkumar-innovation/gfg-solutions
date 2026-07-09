class Solution {
public:
    int ans = 0;

    int f(string& a, string& s, vector<vector<int>>& d, int i, int j) {
        if (i == -1 || j == -1)
            return 0;

        if (d[i][j] != -1)
            return d[i][j];
            
            int l=0;
        if (a[i] == s[j])
            l = 1 + f(a, s, d, i - 1, j - 1);

            f(a, s, d, i - 1, j);
        f(a, s, d, i, j - 1);


        ans = max(ans, l);

        return d[i][j]=l;
    }

    int longCommSubstr(string a, string s) {
        vector<vector<int>> d(a.size(), vector<int>(s.size(), -1));

        f(a, s, d, a.size() - 1, s.size() - 1);

        return ans;
    }
};