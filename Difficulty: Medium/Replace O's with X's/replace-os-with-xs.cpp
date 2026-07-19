class Solution {
	public:
	void f(vector<vector<char>> & a, int i, int j) {
		int n = a.size();
		int m = a[0].size();
		a[i][j] = '#';
		if (j + 1<m) {
			if (a[i][j + 1] == 'O' ) {
				f(a,  i, j + 1);
			}
		}
		if (j - 1 >= 0) {
			if (a[i][j - 1] == 'O') {
			
				f(a,  i, j - 1);
			}
		}
		if (i + 1<n) {
			if (a[i + 1][j] == 'O') {
			
				f(a, i + 1, j);
			}
		}
		if (i - 1 >= 0) {
			if (a[i - 1][j] == 'O' ) {
	
				f(a, i - 1, j);
			}
		}
	}
	void fill(vector<vector<char>> & a) {
		// Code here
		int n = a.size();
		int m = a[0].size();
		int j = 0;
		int i = 0;
		while (j<m) {
			if (a[0][j] == 'O') {
				f(a, 0, j);
			}
			j++;
		}
		j = 0;
		while (j<m) {
			if (a[n - 1][j] == 'O') {
				f(a, n - 1, j);
			}
			j++;
		}
		i = 0;
		while (i<n) {
			if (a[i][0] == 'O') {
				f(a, i, 0);
			}
			i++;
		}
		i = 0;
		while (i<n) {
			if (a[i][m - 1] == 'O') {
				f(a, i, m - 1);
			}
			i++;
		}
		i = 0;
		while (i<n) {
			j = 0;
			while (j<m) {
				if (a[i][j] == 'O')
					a[i][j] = 'X';
				else if (a[i][j] == '#')
					a[i][j] = 'O';
				j++;
			}
			i++;
		}
	}
};
