// class Solution {
//   public:
//     int perfectSum(vector<int>& arr, int target) {
//         // code here
            
//     }
// };

class Solution {
	public:
// 	bool b = 0;
// int c=0
	int h(vector<int>& a, vector<vector<int>>& d, int n, int t) {
// 		if (t == 0) {
// // 			b = 1;
            
// 			return 1;
// 		}
		
		if (n >= a.size() ){
		if(t==0) return 1;
			return 0;
		}
			if(d[n][t]!=-1){
			    return d[n][t];
			}
			int l=0;
			if(t>=a[n])
		l= h(a, d,n + 1, t - a[n]);
		int r =h(a, d,n + 1, t);
		return d[n][t] = l + r;
	}
	int perfectSum(vector<int>& a, int t) {
		// code here
		//   a
		//if(t==0) return 1;
		vector<vector<int>> d(a.size(), vector<int>(t + 1, -1));
// 		if(t==0){
// 		    return 1+ h(a, d, 0, t);
// 		}
		return h(a, d, 0, t) ;
	}
};
