class Solution {
	public:
	vector<string>v;
	void f(vector<vector<int>> & a, int i, int j, string s) {
		int n = a.size();
		int m =n;
		if(i==j && j==n-1){
		    v.push_back(s);
		}
		a[i][j]=0;
		if (j + 1<m) {
			if (a[i][j + 1] == 1) {
				f(a, i, j + 1, s+'R');
			}
		}
		if (j - 1 >= 0) {
			if (a[i][j - 1] == 1) {
				
				f(a, i, j - 1, s+'L');
			}
		}
		if (i + 1<n) {
			if (a[i + 1][j] == 1) {
				
				f(a, i + 1, j, s+'D');
			}
		}
		if (i - 1 >= 0) {
			if (a[i - 1][j] == 1) {
				
				f(a, i - 1, j, s+'U');
			}
		}
		a[i][j]=1;
	}
	vector<string> ratInMaze(vector<vector<int>> & a) {
	    if(a[0][0]==1)
		f(a,0,0,"");
		sort(v.begin(),v.end());
		return v;
		
	}
};
