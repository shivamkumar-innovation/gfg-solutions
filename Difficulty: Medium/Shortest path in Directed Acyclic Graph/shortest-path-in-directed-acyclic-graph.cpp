class Solution {
	public:
	vector<int> shortestPath(int V, int E, vector<vector<int>> & a) {
		priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>> > p;
		
		vector<vector<pair<int, int>> > v(V);
		
		vector<int> vi(V, INT_MAX);
		
		int i = 0;
		while (i < a.size()) {
			int u = a[i][0];
			int x = a[i][1];
			int wt = a[i][2];
			
			v[u].push_back({x, wt});
			i++;
		}
		
		p.push({0, 0});
		vi[0] = 0;
		
		while (!p.empty()) {
			
			auto b = p.top();
			p.pop();
			
			if (b.first > vi[b.second])
				continue;
			
			for (auto j : v[b.second]) {
				
				int node = j.first;
				int wt = j.second;
				
				int c = b.first + wt;
				
				if (c < vi[node]) {
					vi[node] = c;
					p.push({c, node});
				}
			}
		}
		 i = 1;
		while (i<V) {
			if (vi[i] == INT_MAX) {
				vi[i] = -1;
			}
			i++;
		}
		return vi;
	}
};
