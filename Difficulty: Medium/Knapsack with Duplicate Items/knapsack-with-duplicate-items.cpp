class Solution {
public:
    int f(vector<int>& a,vector<int>& v, vector<vector<int>>& d, int i, int b, int t) {
        if (i == a.size() ) return 0;
        //if (b == t) return ;
        // if (i == a.size()) return 0;

        if (d[i][t] != -1) return d[i][t];

        int l = 0;
        if (t + a[i] <= b) {
                l = v[i] + f(a,v, d, i, b, t + a[i]);;
        }

        //int r = INT_MIN;
        int r = f(a,v, d, i + 1, b, t);
           // r = x;

        return d[i][t] = max(l, r);
    }

   int knapSack(vector<int>& v, vector<int>& a, int b){
        
        vector<vector<int>> d(a.size(), vector<int>(b + 1, -1));

        int ans = f(a,v, d, 0, b, 0);

        return ans;
    }
};