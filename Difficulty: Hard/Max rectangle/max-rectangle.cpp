class Solution {
public:
    int x = 0;

    int f(vector<vector<int>>& a, int i) {

        int n = a[i].size();

        vector<int> ans(n);
        stack<int> st;

        // Next Smaller
        for (int j = n - 1; j >= 0; j--) {

            while (!st.empty() && a[i][st.top()] >= a[i][j])
                st.pop();

            if (st.empty())
                ans[j] = n;
            else
                ans[j] = st.top();

            st.push(j);
        }

        while (!st.empty())
            st.pop();

        vector<int> an(n);

        // Previous Smaller
        for (int j = 0; j < n; j++) {

            while (!st.empty() && a[i][st.top()] >= a[i][j])
                st.pop();

            if (st.empty())
                an[j] = -1;
            else
                an[j] = st.top();

            st.push(j);
        }

        int m = 0;

        for (int j = 0; j < n; j++) {

            int width = ans[j] - an[j] - 1;
            int area = width * a[i][j];

            m = max(m, area);
        }

        return m;
    }

    int maxArea(vector<vector<int>>& a) {

        x = f(a, 0);

        int i = 1;

        while (i < a.size()) {

            int j = 0;

            while (j < a[0].size()) {

                if (a[i][j] != 0)
                    a[i][j] += a[i - 1][j];
                else
                    a[i][j] = 0;

                j++;
            }

            x = max(x, f(a, i));

            i++;
        }

        return x;
    }
};