class Solution {
  public:
    int lowerBound(vector<int>& a, int t) {
        // code here
        int i=0;
        int j=a.size()-1;
        
        int mid=(i+j)/2;
        int x=a[j];
        while(i<=j){
            mid=(i+j)/2;
            if(a[mid]<t){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;
    }
};
