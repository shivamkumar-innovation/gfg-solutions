class Solution {
  public:
  
    void f(vector<vector<int>>& a, vector<int>& v, vector<int>& ans, int b) {
        v[b] = 1;
        ans.push_back(b);
        
        int i = 0;
        while (i < a[b].size()) {
            if (!v[a[b][i]]) {
                f(a, v, ans, a[b][i]);
            }
            i++;
        }
    }
  
    vector<int> dfs(vector<vector<int>>& a) {
        
        int n = a.size();
        vector<int> v(n, 0);
        vector<int> ans;
        
        f(a, v, ans, 0);
        
        return ans;
    }
};