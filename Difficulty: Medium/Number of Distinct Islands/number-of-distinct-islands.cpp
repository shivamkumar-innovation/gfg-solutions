class Solution {
	public:
	void f(vector<vector<char>> &a, int i, int j,
           int x, int y, vector<pair<int,int>> &v) {

        int n = a.size();
        int m = a[0].size();

        a[i][j] = '#';
        v.push_back({i - x, j - y});

        if (j + 1 < m) {
            if (a[i][j + 1] == 'L') {
                f(a, i, j + 1, x, y, v);
            }
        }

        if (j - 1 >= 0) {
            if (a[i][j - 1] == 'L') {
                f(a, i, j - 1, x, y, v);
            }
        }

        if (i + 1 < n) {
            if (a[i + 1][j] == 'L') {
                f(a, i + 1, j, x, y, v);
            }
        }

        if (i - 1 >= 0) {
            if (a[i - 1][j] == 'L') {
                f(a, i - 1, j, x, y, v);
            }
        }
    }
	int countDistinctIslands(vector<vector<char>> & a) {
		// Code here
		int i = 0;
		int n = a.size();
		int m = a[0].size();
		int c = 0;
		set<vector<pair<int,int>>> s;
		while (i<n) {
			int j = 0;
			while (j<m) {
				if (a[i][j] == 'L') {
				    vector<pair<int,int>> v;
                    f(a, i, j, i, j, v);
                    s.insert(v);
				}
				j++;
			}
			i++;
		}
		return s.size();
	}
};
