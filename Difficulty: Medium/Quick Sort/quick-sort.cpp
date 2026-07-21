class Solution {
	public:
	void quickSort(vector<int>& v, int i, int j) {
		// code here
		if (i<j) {
			int x = partition(v, i, j);
			quickSort(v, i, x - 1);
			quickSort(v, x + 1, j);
		}
	}
	
	int partition(vector<int>& v, int i, int j) {
		// code here
		int id = j;
		while (j>i) {
			if (v[j] >= v[i]) {
				swap(v[j], v[id]);
				id--;
			}
			j--;
		}
		swap(v[i], v[id]);
		return id;
	}
};
