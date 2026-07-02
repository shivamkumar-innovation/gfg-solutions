// class Solution {
//   public:
//     int maxChocolate(vector<vector<int>>& grid) {
//         // code here
        
//     }
// };



class Solution {
  public:
  int f(vector<vector<int>>& a,  vector<vector<vector<int>>>& d, int i,int j,int m){
      if(j<=-1 || m<=-1 || j>=a[0].size() || m>=a[0].size()){
          return -1;
      }
      if(a.size()-1==i){
          if(j==m){
              return a[i][j];
          }
          return a[i][j]+a[i][m];
      }
      if(d[i][j][m]!=-1){
          return d[i][j][m];
      }
    //   long long r=INT_MAX;
    //       r=f(a,d,i+1,l)+1LL*a[i][l];
    int fi=INT_MIN;
    for(int y=j-1;y<=j+1;y++){
    for(int x=m-1;x<=m+1;x++){
        if(j==m)
        fi = max(fi, f(a,d,i+1,y,x) + a[i][j]);
        else{
            fi = max(fi, f(a,d,i+1,y,x) +a[i][m]+ a[i][j]);
        }
    }
    }

       return d[i][j][m]=fi;
  }
  
    int maxChocolate(vector<vector<int>>& a) {
        // if(a.size()==1) return a[0][0];
        vector<vector<vector<int>>> d(
            a.size(), vector<vector<int>>(a[0].size(), vector<int>(a[0].size(), -1)));
        //int i=0;
        return f(a,d,0,0,a[0].size()-1);
        
    }
};