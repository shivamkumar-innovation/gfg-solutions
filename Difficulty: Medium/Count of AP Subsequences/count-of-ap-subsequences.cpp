class Solution {
public:
    vector<unordered_map<long long, long long>> dp;
    vector<int> a;

    long long f(int i, long long diff) {

        if (dp[i].count(diff))
            return dp[i][diff];

        long long ans = 0;

        for (int j = 0; j < i; j++) {

            if (1LL * a[i] - a[j] == diff) {

                ans += 1 + f(j, diff);

            }
        }

        return dp[i][diff] = ans;
    }

    int count(vector<int>& arr) {

        a = arr;

        int n = a.size();

        dp.assign(n, {});

        long long ans = 1 + n;

        for (int i = 0; i < n; i++) {

            unordered_set<long long> s;

            for (int j = 0; j < i; j++) {

                long long diff = 1LL * a[i] - a[j];

                if (s.insert(diff).second)
                    ans += f(i, diff);
            }
        }

        return ans;
    }
};