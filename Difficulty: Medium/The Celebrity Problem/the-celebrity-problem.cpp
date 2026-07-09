class Solution {
  public:
    int celebrity(vector<vector<int>>& a) {
        // code here
        int i=0;
        while(i<a.size()){
            int j=0;
            while(j<a[0].size()){
                if(a[i][j]==0 && a[j][i]==1){
                }
                else if(i==j){
                    
                }
                else break;
                j++;
            }
            if(j==a[0].size()) return i;
            i++;
        }
        return -1;
    }
};