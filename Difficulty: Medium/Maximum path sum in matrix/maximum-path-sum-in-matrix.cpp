class Solution {
  public:
  int f(vector<vector<int>>& a, vector<vector<int>>& d, int i,int l){
    if(l==-1 || l==a[0].size()){
        return 0;
    }
      if(a.size()==i){
          return 0;
      }
      if(d[i][l]!=-1000000){
          return d[i][l];
      }
      long long r=0;
          r=f(a,d,i+1,l)+1LL*a[i][l];
      
      long long fi=0;
      
          fi=f(a,d,i+1,l-1)+1LL*a[i][l];
    
      long long le=0;
    
          le=f(a,d,i+1,l+1)+1LL*a[i][l];
    
    //   d[i][l]=max(le,max(r,fi));
      return d[i][l]=(int)max(le,max(r,fi));
  }
  
    int maximumPath(vector<vector<int>>& a) {
        if(a.size()==1) return *max_element(a[0].begin(),a[0].end());
        vector<vector<int>>v(a.size(), vector<int>(a[0].size(), -1000000));
        int i=0;
        int m=0;
        while(i<a[0].size()){
            m=max(f(a,v,0,i),m);
            i++;
        }
        return m;
        //return max(f(a,d,0,0),max(f(a,d,0,1),f(a,d,0,2))
    }
};