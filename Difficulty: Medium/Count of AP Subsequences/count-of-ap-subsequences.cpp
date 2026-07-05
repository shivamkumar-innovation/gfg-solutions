class Solution {
public:
    vector<unordered_map<int, int>> d;

    long long f(vector<int>&a, int i, int j,int diff) {
        // if (dp[i].count(diff))
        //     return dp[i][diff];

        long long ans = 0;
        if(d[j].count(diff)==0){
            ans=1;
           
        }
        else{
            ans=1+d[j][diff];
        }

        return d[i][diff] = ans;
    }
int count(vector<int>& a) {


        int n = a.size();
     
        d.assign(n, {});

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j<i; j++) {

                int diff = a[i] - a[j];

                    ans = ans+f(a,i, j, diff);
            }
        }

        return ans+n+1;
    }
};