class Solution {
	public:
	
	void f(vector<vector<int>> &d, int i, stack<int> &s, vector<int> &v) {
		
		v[i] = 1;
		
		int j = 0;
		while (j < d[i].size()) {
			if (v[d[i][j]] == 0) {
				f(d, d[i][j], s, v);
			}
			j++;
		}
		
		s.push(i);
	}
	void h(vector<vector<int>> &d, int i, vector<int> &v){
	   v[i] = 1;
		
		int j = 0;
		while (j < d[i].size()) {
			if (v[d[i][j]] == 0) {
				h(d, d[i][j], v);
			}
			j++;
		}
	}
	
	int kosaraju(int V, vector<vector<int>> &a) {
		
		vector<vector<int>> d(V);
		
		int i = 0;
		while (i < a.size()) {
			d[a[i][0]].push_back(a[i][1]);
			i++;
		}
		
		stack<int> s;
		vector<int> v(V, 0);
		
		i = 0;
		while (i < V) {
			if (v[i] == 0) {
				f(d, i, s, v);
			}
			i++;
		}
		
		vector<vector<int>> rev(V);
		
		i = 0;
		while (i < a.size()) {
			rev[a[i][1]].push_back(a[i][0]);
			i++;
		}
		
		fill(v.begin(), v.end(), 0);
		
		i=0;
		int x=0;
		while(!s.empty()){
		    if(v[s.top()]==0){
		        h(rev,s.top(),v);
		        x++;
		    }
		    s.pop();
		}
		return x;
	}
};
