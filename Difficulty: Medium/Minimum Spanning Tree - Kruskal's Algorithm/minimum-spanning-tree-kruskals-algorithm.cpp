class Solution {
	public:
	int f(vector<int>&p, int j) {
		if (j == p[j]) {
			return j;
		}
		return p[j] = f(p, p[j]);
	}
	
	int kruskalsMST(int n, vector<vector<int>> &a) {
		// code here
		sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y) {
			return x[2] < y[2];
		});
		vector<int>p(n + 1);
		vector<int>r(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			p[i] = i;
		}
		int i = 0;
		int s = 0;
		while (i<a.size()) {
			int x = f(p, a[i][0]);
			int y = f(p, a[i][1]);
			if (x != y) {
				s = s + a[i][2];
				if (r[x]>r[y]) {
					p[y] = x;
				}
				else if (r[x]<r[y]) {
					p[x] = y;
				}
				else {
					p[y] = x;
					r[x]++;
				}
			}
			i++;
		}
		return s;
	}
};
