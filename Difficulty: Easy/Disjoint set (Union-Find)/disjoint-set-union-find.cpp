class Solution {
	public:
	vector<int>v;
	int f(vector<int>&p, int j) {
		if (j == p[j]) {
			return j;
		}
		return p[j] = f(p, p[j]);
	}
	
	vector<int> DSU(int n, vector<vector<int>> & q) {
		vector<int>p(n + 1);
		for (int i = 0; i <= n; i++) {
			p[i] = i;
		}
		int i = 0;
		while (i<q.size()) {
			if (q[i][0] == 2) {
				v.push_back(f(p, q[i][1]));
			}
			else {
			    int x = f(p, q[i][1]);
			    int y=f(p,q[i][2]);
				p[x]=y;
			}
			i++;
		}
		return v;
	}
};
