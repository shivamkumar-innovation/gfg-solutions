class Solution {
    public:
    

    pair<int,int> f(vector<pair<int,int>>&d, int i, int j) {
    
        int ans = 0;        
            ans=1+d[j].first;
        if(d[i].first<ans){
            d[i]={ans,j};
        }
        return d[i] ;
    }
     vector<int> getLIS(vector<int>& a) {
        
        int n=a.size();
        vector<pair<int,int>> d(n,make_pair(1,-1));
        int ans=1;
        int u=0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j<i; j++) {
                if(a[j]<a[i]){
                    pair<int,int>p;
                    p=f(d,i,j);
                    if(p.first>ans){
                        ans=p.first;
                        u=i;
                    }
                }
            }
        }
        vector<int>v(ans,0);
        int i=ans-1;
        while(i>=0){
            v[i]=a[u];
            i--;
            u=d[u].second;
        }

        return v;
    }
};