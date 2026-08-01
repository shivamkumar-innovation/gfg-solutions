class Solution {
public:
    string findOrder(vector<string> &words) {

        vector<vector<int>> a(26);
        vector<int> present(26, 0);

        int i = 0;
        while (i < words.size()) {

            int j = 0;
            while (j < words[i].size()) {
                present[words[i][j] - 'a'] = 1;
                j++;
            }

            i++;
        }

        i = 0;

        while (i < words.size() - 1) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int j = 0;

            while (j < min(s1.size(), s2.size())) {

                if (s1[j] != s2[j]) {

                    a[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }

                j++;
            }

            if (j == min(s1.size(), s2.size()) && s1.size() > s2.size())
                return "";

            i++;
        }

        vector<int> vi(26, 0);

        i = 0;
        while (i < 26) {

            int j = 0;

            while (j < a[i].size()) {

                vi[a[i][j]]++;

                j++;
            }

            i++;
        }

        queue<int> q;

        i = 0;

        while (i < 26) {

            if (present[i] && vi[i] == 0) {
                q.push(i);
            }

            i++;
        }

        string ans = "";

        while (!q.empty()) {

            int x = q.front();
            q.pop();

            ans += char(x + 'a');

            int j = 0;

            while (j < a[x].size()) {

                vi[a[x][j]]--;

                if (vi[a[x][j]] == 0) {
                    q.push(a[x][j]);
                }

                j++;
            }
        }

        int cnt = 0;

        i = 0;

        while (i < 26) {

            if (present[i])
                cnt++;

            i++;
        }

        if (ans.size() != cnt)
            return "";

        return ans;
    }
};