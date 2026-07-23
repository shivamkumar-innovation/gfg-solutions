class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &a) {
        
        int n = a.size();
        vector<int> ans;
        vector<int> v(n, 0);
        queue<int> q;
        
        q.push(0);
        v[0] = 1;
        
        while (!q.empty()) {
            int b = q.front();
            q.pop();
            
            ans.push_back(b);
            
            int i = 0;
            while (i < a[b].size()) {
                if (!v[a[b][i]]) {
                    v[a[b][i]] = 1;
                    q.push(a[b][i]);
                }
                i++;
            }
        }
        
        return ans;
    }
};