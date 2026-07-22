class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> & a) {
		// code here
		vector<vector<pair<int, int>> > d(V);
		
		for (int i = 0; i < a.size(); i++) {
			int u = a[i][0];
			int v = a[i][1];
			int wt = a[i][2];
			
			d[u].push_back({v, wt});
			d[v].push_back({u, wt});
		}
		
		priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> p;
		vector<int>v(V,0);
		int s=0;
		p.push({0,0,-1});
		v[0]=0;
		while(!p.empty()){
		    auto b=p.top();
		    p.pop();
		    if(v[b[1]]==0){
		        s=s+b[0];
		        v[b[1]]=1;
		        int j=0;
		        while(j<d[b[1]].size()){
		            p.push({d[b[1]][j].second,d[b[1]][j].first,b[1]});
		            j++;
		        }
		    }
		}
		
		return s;
		
	}
};
