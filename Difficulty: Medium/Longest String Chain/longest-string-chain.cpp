class Solution {
public:
    int f(unordered_map<string,int>& d, string &s) {

        int ans = 1;

        for (int i = 0; i < s.size(); i++) {

            string t = s;
            t.erase(i, 1);

            if (d.count(t))
                ans = max(ans, 1 + d[t]);
        }

        return d[s] = ans;
        
    }

    int longestStringChain(vector<string>& a) {

        sort(a.begin(), a.end(), [](string &c, string &d) {
            return c.size() < d.size();
        });

        unordered_map<string,int> d;

        int ans = 1;

        for (int i = 0; i < a.size(); i++) {
            ans = max(ans, f(d, a[i]));
        }

        return ans;
    }
};