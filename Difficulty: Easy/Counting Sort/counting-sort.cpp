class Solution {
  public:
    string countSort(string s) {
        // code here
        vector<int>v(26,0);
        int i=0;
        while(i<s.size()){
            int x=s[i]-'a';
            v[x]++;
            i++;
        }
        int j=0;
        i=0;
        while(j<26){
            if(v[j]!=0){
                s[i]='a'+j;
                i++;
                v[j]--;
            }
            else{
                j++;
            }
        }
        return s;
    }
};