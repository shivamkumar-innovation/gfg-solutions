class Solution {
	public:
// 	bool b = 0;
	bool h(vector<int>& a, vector<vector<int>>& d, int n, int t) {
		if (t == 0) {
// 			b = 1;
			return 1;
		}
		
		if (n >= a.size() || t < 0)
			return 0;
			if(d[n][t]!=-1){
			    return d[n][t];
			}
		bool l= h(a, d,n + 1, t - a[n]);
		bool r =h(a, d,n + 1, t);
		
		return d[n][t] = l || r;;
	}
	bool isSubsetSum(vector<int>& a, int t) {
		// code here
		//   a
		vector<vector<int>> d(a.size(), vector<int>(t + 1, -1));
		
		return h(a, d, 0, t) ;
	}
};
