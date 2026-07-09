class Solution {
public:
    const int INF = 1e9;

    int f(string &s1, string &s2, vector<vector<int>> &dp, int i, int j) {
        if (j == s2.size())
            return i - 1;

        if (i == s1.size())
            return INF;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INF;

        // Take current character if it matches
        if (s1[i] == s2[j])
            ans = f(s1, s2, dp, i + 1, j + 1);

        // Skip current character
        ans = min(ans, f(s1, s2, dp, i + 1, j));

        return dp[i][j] = ans;
    }

    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if (m == 0) return "";
        if (n == 0) return "";

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int bestLen = INF;
        int start = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[0]) {
                int end = f(s1, s2, dp, i, 0);

                if (end != INF && end - i + 1 < bestLen) {
                    bestLen = end - i + 1;
                    start = i;
                }
            }
        }

        if (start == -1)
            return "";

        return s1.substr(start, bestLen);
    }
};