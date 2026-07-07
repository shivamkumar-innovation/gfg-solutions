class Solution {
  public:
  int f(vector<int> &a,vector<vector<int>> &d,int i, int j){
      if(i==j || i>j) return 0;
      if(d[i][j]!=-1) return d[i][j];
      int l=INT_MAX;
      int k=i;
      while(k<j){
          l=min(l,a[i-1]*a[k]*a[j]+f(a,d,i,k)+f(a,d,k+1,j));
          k++;
      }
      return d[i][j]=l;
  }
    int matrixMultiplication(vector<int> &a) {
        vector<vector<int>>d(a.size(),vector<int>(a.size(),-1));
        return f(a,d,1,a.size()-1);
    }
};