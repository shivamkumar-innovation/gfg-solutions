class Solution {
	public:
	void floydWarshall(vector<vector<int>> &a) {
		int n = a.size();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (a[j][i] != 1e8 && a[i][k] != 1e8 && a[j][i] + a[i][k] < a[j][k]) {
						
						a[j][k] = a[j][i] + a[i][k];
					}
				}
			}
		}
	}
};
