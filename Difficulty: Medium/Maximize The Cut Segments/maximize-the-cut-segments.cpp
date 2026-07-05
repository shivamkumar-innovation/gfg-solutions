// class Solution {
//   public:
//     int maximizeCuts(int n, int x, int y, int z) {
//         // code here
        
//     }
// };

class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& d, int i, int b, int t) {
        if (b == t) return 0;
        if (i == a.size()) return INT_MIN;

        if (d[i][t] != -1) return d[i][t];

        int l = INT_MIN;
        if (t + a[i] <= b) {
            int x = f(a, d, i, b, t + a[i]);
            if (x != INT_MIN)
                l = 1 + x;
        }

        int r = INT_MIN;
        int x = f(a, d, i + 1, b, t);
        if (x != INT_MIN)
            r = x;

        return d[i][t] = max(l, r);
    }

   int maximizeCuts(int b, int x, int y, int z) {
        

        vector<int>v;
        set<int>s;
        s.insert(x);
        s.insert(z);
        s.insert(y);
        auto it=s.begin();
        while(it!=s.end()){
            v.push_back((*it));
            it++;
        }
        
        vector<vector<int>> d(v.size(), vector<int>(b + 1, -1));

        int ans = f(v, d, 0, b, 0);

        return (ans == INT_MIN) ? 0 : ans;
    }
};