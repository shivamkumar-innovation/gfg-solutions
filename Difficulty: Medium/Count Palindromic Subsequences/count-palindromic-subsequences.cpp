class Solution {
public:
    int f(string& a,  vector<vector<int>>& d, int i,int j) {
        if(i>j){
            return 0;
        }
        if(d[i][j]!=-1) return d[i][j];
        int l=0;
        if(a[i]==a[j]){
           
            l=1;
        }
        else{
            l=-f(a,d,i+1,j-1);
        }
        int u=f(a,d,i,j-1);
        int r=f(a,d,i+1,j);
       return  d[i][j]=l+u+r;
    }
    int countPS(string a) {
         vector<vector<int>> d(a.size(),vector<int>(a.size(),-1));
        return f(a,d,0,a.size()-1);
    }
};
