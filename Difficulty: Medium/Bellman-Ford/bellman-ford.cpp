class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& a, int s) {
        // Code here
        vector<int>v(n,100000000);
        v[s]=0;
        int i=1;
        while(i<n){
            int j=0;
            while(j<a.size()){
                if(v[a[j][0]] != 100000000 && v[a[j][0]]+a[j][2]<v[a[j][1]]){
                    v[a[j][1]]=v[a[j][0]]+a[j][2];
                }
                j++;
            }
            i++;
        }
        int j=0;
            while(j<a.size()){
                if(v[a[j][0]] != 100000000 && v[a[j][0]]+a[j][2]<v[a[j][1]]){
                    return {-1};
                }
                j++;
            }
        return v;
    }
};
