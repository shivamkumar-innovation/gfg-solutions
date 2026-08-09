/* Structure of tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
public:
    int i;

    Node* f(vector<int>& post, int low, int high) {
        if (i < 0 || post[i] < low || post[i] > high)
            return NULL;

        Node* r = new Node(post[i--]);

        r->right = f(post, r->data, high);
        r->left = f(post, low, r->data);

        return r;
    }

    Node* constructTree(vector<int>& post) {
        i = post.size() - 1;

        return f(post, INT_MIN, INT_MAX);
    }
};