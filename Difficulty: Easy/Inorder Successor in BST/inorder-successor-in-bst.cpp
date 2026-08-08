class Solution {
public:
    Node* ans = NULL;

    bool find(Node* root, int x) {
        if (!root)
            return false;

        if (root->data == x)
            return true;

        if (root->data > x)
            return find(root->left, x);

        return find(root->right, x);
    }

    void ceil(Node* root, int x) {
        if (!root)
            return;

        if (root->data > x) {
            ans = root;
            ceil(root->left, x);
        }
        else {
            ceil(root->right, x);
        }
    }

    int inOrderSuccessor(Node *root, Node *k) {

        if (!find(root, k->data))
            return -1;

        ceil(root, k->data);

        return ans ? ans->data : -1;
    }
};