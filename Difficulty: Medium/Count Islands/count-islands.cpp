class Solution {
	public:
	void f(vector<vector<char>> & a, int i, int j) {
		int n = a.size();
		int m = a[0].size();
		a[i][j] = '#';
		if (j + 1<m) {
			if (a[i][j + 1] == 'L') {
				f(a, i, j + 1);
			}
		}
		if (j - 1 >= 0) {
			if (a[i][j - 1] == 'L') {
				
				f(a, i, j - 1);
			}
		}
		if (i + 1<n) {
			if (a[i + 1][j] == 'L') {
				
				f(a, i + 1, j);
			}
		}
		if (i - 1 >= 0) {
			if (a[i - 1][j] == 'L') {
				
				f(a, i - 1, j);
			}
		}
		if (i - 1 >= 0 && j - 1 >= 0) {
			if (a[i - 1][j - 1] == 'L') {
				f(a, i - 1, j - 1);
			}
		}
		
		if (i - 1 >= 0 && j + 1<m) {
			if (a[i - 1][j + 1] == 'L') {
				f(a, i - 1, j + 1);
			}
		}
		
		if (i + 1<n && j - 1 >= 0) {
			if (a[i + 1][j - 1] == 'L') {
				f(a, i + 1, j - 1);
			}
		}
		
		if (i + 1<n && j + 1<m) {
			if (a[i + 1][j + 1] == 'L') {
				f(a, i + 1, j + 1);
			}
		}
	}
	int countIslands(vector<vector<char>> & a) {
		// Code here
		int i = 0;
		int n = a.size();
		int m = a[0].size();
		int c = 0;
		while (i<n) {
			int j = 0;
			while (j<m) {
				if (a[i][j] == 'L') {
					c++;
					f(a, i, j);
				}
				j++;
			}
			i++;
		}
		return c;
	}
};
