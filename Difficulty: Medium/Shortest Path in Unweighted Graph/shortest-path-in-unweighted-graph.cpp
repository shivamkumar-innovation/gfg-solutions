class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &v, int s, int d) {
        
        vector<vector<int>> a(V);

    for (auto &edge : v) {
        a[edge[0]].push_back(edge[1]);
        a[edge[1]].push_back(edge[0]);
    }
     vector<int>vi(V,INT_MAX);
     queue<int>q;
     vi[s]=0;
     q.push(s);
     while(!q.empty()){
         int x=q.front();
         q.pop();
         if(x==d){
             continue;
         }
         int j=0;
         while(j<a[x].size()){
             if(vi[a[x][j]]>1+vi[x]){
                 vi[a[x][j]]=1+vi[x];
                 q.push(a[x][j]);
             }
             j++;
         }
     }
     return vi[d]==INT_MAX?-1:vi[d];
    }
};
