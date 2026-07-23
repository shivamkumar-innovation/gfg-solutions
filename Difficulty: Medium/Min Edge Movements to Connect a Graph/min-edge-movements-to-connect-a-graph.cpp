class Solution {
	public:
	int minEdgesReq(int n, vector<vector<int>> &a) {
		// Adjacency list
		vector<vector<int>> adj(n);
		
		int i = 0;
		while (i < a.size()) {
			adj[a[i][0]].push_back(a[i][1]);
			adj[a[i][1]].push_back(a[i][0]);
			i++;
		}
		
		queue<int> q;
		vector<int> vis(n, 0);
		
		int t = 0;
		i = 0;
		
		while (i < n) {
			
			if (vis[i]) {
				i++;
				continue;
			}
			
			t++;
			vis[i] = 1;
			q.push(i);
			
			while (!q.empty()) {
				int b = q.front();
				q.pop();
				
				int j = 0;
				while (j < adj[b].size()) {
					if (!vis[adj[b][j]]) {
						vis[adj[b][j]] = 1;
						q.push(adj[b][j]);
					}
					j++;
				}
			}
			
			while (i < n && vis[i]) {
				i++;
			}
		}
		
		if (t == 1)
			return 0;
		
		i = 0;
		while (i < n) {
			vis[i] = 0;
			i++;
		}
		
		int k = 0;
		i = 0;
		
		while (i < n) {
			
			if (vis[i]) {
				i++;
				continue;
			}
			
			vis[i] = 1;
			
			queue<pair<int, int>> s;
			s.push({i, -1});
			
			while (!s.empty()) {
				auto b = s.front();
				s.pop();
				
				int j = 0;
				while (j < adj[b.first].size()) {
					
					if (!vis[adj[b.first][j]]) {
						vis[adj[b.first][j]] = 1;
						s.push({adj[b.first][j], b.first});
					}
					else if (b.second != adj[b.first][j]) {
						k++;
					}
					
					j++;
				}
			}
			
			while (i < n && vis[i]) {
				i++;
			}
		}
		k /= 2;
		
		t--;
		
		if (k >= t)
			return t;
		
		return - 1;
		
	}
};
