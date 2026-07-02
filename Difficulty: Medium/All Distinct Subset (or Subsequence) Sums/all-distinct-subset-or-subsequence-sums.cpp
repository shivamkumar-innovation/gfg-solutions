class Solution {
	public:
// 	bool b = 0;
vector<int>v;
set<int>s;
// s.insert(0);
	bool h(vector<int>& a, vector<vector<int>>& d, int n, int t) {
// 		if (t == 0) {
// // 			b = 1;
// 			return 1;
// 		}
		
		if (n >= a.size()){
		    s.insert(t);
			return 1;
		}
			if(d[n][t]!=-1){
			    return d[n][t];
			}
		bool l= h(a, d,n + 1, t - a[n]);
		 bool r = h(a, d,n + 1, t);
		
		return d[n][t] =l||r;
	}
	vector<int> distinctSum(vector<int>& a) {
		// code here
		int t=accumulate(a.begin(),a.end(),0);
		vector<vector<int>> d(a.size(), vector<int>(t+1, -1));
		bool b=h(a, d, 0, t) ;
		auto it=s.begin();
		while(it!=s.end()){
		    v.push_back((*it));
		    it++;
		}
		return v;
	}
};
