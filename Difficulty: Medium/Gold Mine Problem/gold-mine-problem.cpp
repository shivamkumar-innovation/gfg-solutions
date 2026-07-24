class Solution {
	public:
	int f(vector<vector<int>> & a, vector<vector<int>> & d, int i, int j) {
		int n = a.size();
		int m = a[0].size();
		
		if (i < 0 || i >= n)
			return 0;
		
		if (j == m - 1)
			return a[i][j];
		
		if (d[i][j] != -1)
			return d[i][j];
		
		int p = f(a, d, i - 1, j + 1);
		int q = f(a, d, i, j + 1);
		int r = f(a, d, i + 1, j + 1);
		
		return d[i][j] = a[i][j] + max({p, q, r});
	}
	
	int maxGold(vector<vector<int>> & a) {
		int n = a.size();
		int m = a[0].size();
		
		vector<vector<int>> d(n, vector<int>(m, -1));
		
		int ans = 0;
		
		int i = 0;
		while (i < n) {
			ans = max(ans, f(a, d, i, 0));
			i++;
		}
		
		return ans;
	}
};
