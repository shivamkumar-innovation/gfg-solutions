class Solution {
public:

    int f(vector<int>& p, int j) {
        if (j == p[j]) {
            return j;
        }
        return p[j] = f(p, p[j]);
    }

    void uni(vector<int>& p, vector<int>& r, int a, int b, int &cnt) {

        int x = f(p, a);
        int y = f(p, b);

        if (x == y) {
            return;
        }

        if (r[x] < r[y]) {
            p[x] = y;
        }
        else if (r[x] > r[y]) {
            p[y] = x;
        }
        else {
            p[y] = x;
            r[x]++;
        }

        cnt--;
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &a) {

        vector<int> p(n * m);
        vector<int> r(n * m, 0);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;

        int i = 0;
        while (i < n * m) {
            p[i] = i;
            i++;
        }

        int cnt = 0;
        i = 0;

        while (i < a.size()) {

            int x = a[i][0];
            int y = a[i][1];

            if (vis[x][y]) {
                ans.push_back(cnt);
                i++;
                continue;
            }

            vis[x][y] = 1;
            cnt++;

            int node = x * m + y;

            if (x - 1 >= 0 && vis[x - 1][y]) {
                uni(p, r, node, (x - 1) * m + y, cnt);
            }

            if (y + 1 < m && vis[x][y + 1]) {
                uni(p, r, node, x * m + y + 1, cnt);
            }

            if (x + 1 < n && vis[x + 1][y]) {
                uni(p, r, node, (x + 1) * m + y, cnt);
            }

            if (y - 1 >= 0 && vis[x][y - 1]) {
                uni(p, r, node, x * m + y - 1, cnt);
            }

            ans.push_back(cnt);
            i++;
        }

        return ans;
    }
};