/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  vector<vector<int>>v;
  void f(Node* &r, vector<int> &a) {
        a.push_back(r->data);

        if (!r->left && !r->right) {
            v.push_back(a);
            a.pop_back();
            return;
        }

        if (r->left)
            f(r->left, a);

        if (r->right)
            f(r->right, a);
             a.pop_back();
        
    }
    vector<vector<int>> paths(Node* r) {
        // code here
        
        if(r==nullptr){
            return v;
        }
        vector<int>a;
        f(r,a);
        return v;
    }
};