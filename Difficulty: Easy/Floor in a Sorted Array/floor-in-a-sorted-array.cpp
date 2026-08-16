class Solution {
  public:
    int findFloor(vector<int>& a, int t) {
        // code here
        int i=0;
        int j=a.size()-1;

        int mid=(i+j)/2;
        while(i<=j){
            mid=(i+j)/2;
            if(a[mid]>t){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};
