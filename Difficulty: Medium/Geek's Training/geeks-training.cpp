class Solution {
  public:
  int f(vector<vector<int>>& a, vector<vector<int>>& d, int i,int l){
      if(a.size()==i){
          return 0;
      }
      if(d[i][l]!=0){
          return d[i][l];
      }
      int r=0;
      if(l!=0){
          r=f(a,d,i+1,0)+a[i][0];
      }
      int fi=0;
      if(l!=1){
          fi=f(a,d,i+1,1)+a[i][1];
      }
      int le=0;
      if(l!=2){
          le=f(a,d,i+1,2)+a[i][2];
      }
    //   d[i][l]=max(le,max(r,fi));
      return d[i][l]=max(le,max(r,fi));
  }
  
    int maximumPoints(vector<vector<int>>& a) {
        if(a.size()==1) return *max_element(a[0].begin(),a[0].end());
        vector<vector<int>>v(a.size(), vector<int>(3, 0));
        int i=0;
        int m=0;
        while(i<3){
            v[0][i]=a[0][i];
            m=max(a[0][i] +f(a,v,1,i),m);
            i++;
        }
        return m;
        //return max(f(a,d,0,0),max(f(a,d,0,1),f(a,d,0,2))
    }
};