class Solution {
    public: 
    void f(vector<int>&d, int i, int j) {
    
        int ans = 0;        
            ans=1+d[j];
        
        d[i]=max(ans,d[i]);
        // return d[i] ;
    }
    
    void h(vector<int>&d, int i, int j){
        
    }    
    int longestBitonicSequence(int n, vector<int> &a) {
        vector<int> d(n,0);
        //int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j<i; j++) {
                if(a[j]<a[i])
                    f(d,i,j);
            }
        }
        
         vector<int> dp(n,0);
        //int ans = 1;

        for (int i = n-1; i>=0; i--) {
            for (int j = n-1; j>i; j--) {
                if(a[j]<a[i])
                    f(dp,i,j);
            }
        }
        int ans=0;
        int i=0;
        while(i<n){
            if(d[i]!=0 && dp[i]!=0)
            ans=max(ans,d[i]+dp[i]+1);
            i++;
        }

        return ans;
    }
};
