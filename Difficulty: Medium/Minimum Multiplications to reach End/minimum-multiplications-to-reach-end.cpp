class Solution {
	public:
	
	int minSteps(vector<int>& a, int s, int e) {
		vector<int>vi(1000, INT_MAX);
		priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> p;
		p.push({0, s});
		vi[s] = 0;
		
		while (!p.empty()) {
			
			auto b = p.top();
			p.pop();
			
			if (b.first > vi[b.second] || b.second==e)
				continue;
			int i = 0;
			while (i<a.size()) {
				int k = (b.second*a[i])%1000;
				if (b.first+1 < vi[k]) {
					vi[k] = b.first+1;
					p.push({b.first+1, k});
				}
				i++;
			}
		}
	return vi[e] == INT_MAX ? -1 : vi[e];
}
};
