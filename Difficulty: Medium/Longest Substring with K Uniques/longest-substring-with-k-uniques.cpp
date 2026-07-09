class Solution {
	public:
	int longestKSubstr(string &a, int k) {
		// code here
		int i = 0;
		int j = 0;
		int x = 0;
		unordered_map<char, int>m;
		while (j<a.size()) {
			if (x<k) {
				if (!m.count(a[j])) {
					x++;
				}
				m[a[j]]++;
			}
			else if (x == k && m.count(a[j])) {
				m[a[j]]++;
			}
			else {
				break;
			}
			j++;
		}
		int ans =-1;
		if(x==k)
		 ans = j - i;
		while (j<a.size()) {
			if (m.size() == k && !m.count(a[j])) {
				ans = max(ans, j - i);
				while (i<j) {
					m[a[i]]--;
					if (m[a[i]] == 0) {
						m.erase(a[i]);
						i++;
						break;
					}
					i++;
				}
			}
			else  {
			    m[a[j]]++;
				j++;
				ans = max(ans, j - i);
			}
		}
		return ans;
	}
};
