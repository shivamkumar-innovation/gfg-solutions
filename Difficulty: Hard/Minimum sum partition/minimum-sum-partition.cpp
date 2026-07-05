// class Solution {
//   public:
//     int minDifference(vector<int>& arr) {
//         // code here
        
//     }
// };

class Solution {
public:
    int minDifference(vector<int>& a) {
        int k = accumulate(a.begin(), a.end(), 0);
        int n=a.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        dp[0][a[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= k; t++) {

                bool l = dp[i - 1][t];
                bool r = false;

                if (a[i] <= t)
                    r = dp[i - 1][t - a[i]];

                dp[i][t] = l | r;
            }
        }
        int i = 0;
        int x = INT_MAX;
        while (i <= k) {
            if (dp[n - 1][i])
                x = min(x, abs(k - 2 * i));
                i++;
        }
        return x;
    }
};