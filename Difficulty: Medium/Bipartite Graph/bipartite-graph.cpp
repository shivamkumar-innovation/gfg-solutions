class Solution {
	public:
	bool isBipartite(int n, vector<vector<int>> &v) {
		vector<vector<int>> a(n);
		
		for (auto &edge : v) {
			int u = edge[0];
			int v = edge[1];
			a[u].push_back(v); 
			a[v].push_back(u);
		}
		
		vector<int>vi(n,-1);
		
		queue<int>q;
		q.push(0);
		vi[0]=0;
		while(!q.empty()){
		    int b=q.front();
		    q.pop();
		    int j=0;
		    while(j<a[b].size()){
		        if(vi[a[b][j]]==-1){
		            vi[a[b][j]]=!vi[b];
		            q.push(a[b][j]);
		        }
		        else if(vi[a[b][j]]==vi[b]){
		            return false;
		        }
		        j++;
		    }
		}
		return true;
	}
};
