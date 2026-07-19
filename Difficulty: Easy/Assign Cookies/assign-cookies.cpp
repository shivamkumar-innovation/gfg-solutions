class Solution {
  public:
  
    int maxChildren(vector<int> &a, vector<int> &b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0;
        int j=0;
        int c=0;
        while(i<b.size()){
            if(j<a.size() && a[j]<=b[i]){
                c++;
                j++;
            }
            i++;
        }
        return c;
    }
};