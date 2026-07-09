class Solution {
public:
    int countPS(string s) {

        int n = s.size();
        int ans = 0;

        for (int c = 0; c < n; c++) {
            int l = c, r = c;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= 2)
                    ans++;
                l--;
                r++;
            }
        }

        for (int c = 0; c < n - 1; c++) {
            int l = c, r = c + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};