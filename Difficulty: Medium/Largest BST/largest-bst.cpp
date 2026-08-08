class Solution {
public:
    class Info {
    public:
        int mn, mx, sz;

        Info(int mn, int mx, int sz) {
            this->mn = mn;
            this->mx = mx;
            this->sz = sz;
        }
    };

    Info f(Node *root) {

        if (!root)
            return Info(INT_MAX, INT_MIN, 0);

        Info l = f(root->left);
        Info r = f(root->right);

        if (l.mx < root->data && root->data < r.mn) {

            return Info(
                min(root->data, l.mn),
                max(root->data, r.mx),
                l.sz + r.sz + 1
            );
        }

        return Info(
            INT_MIN,
            INT_MAX,
            max(l.sz, r.sz)
        );
    }

    int largestBst(Node *root) {
        Info x= f(root);
        return x.sz;
    }
};