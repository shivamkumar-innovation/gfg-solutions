class Solution {
	public:
	// bool b=0;
	int f(vector<int>&a, vector<vector<int>> &d, int t, int k, int i, int di) {
		// if(b) return 1;
		
		if (i == a.size()) {
			if (t - k == di) {
				// b=true;
				return 1;
			}
			return 0;
		}
		if (d[i][t] != -1)
			return d[i][t];
			int l=0;
			if(t-a[i]-(k+a[i])>=di)
		l = f(a, d, t - a[i], k + a[i], i + 1, di);
		int r = f(a, d, t, k, i + 1, di);
		
		return d[i][t] = l + r;
		
	}
	int countPartitions(vector<int>& a, int di) {
		// code here
		if (a.size() == 0)
			return 0;
		int t = accumulate(a.begin(), a.end(), 0);
		vector<vector<int>> v(a.size(), vector<int>(t + 1, -1));
		int k = 0;
		return f(a, v, t, k, 0, di);
		
	}
};
