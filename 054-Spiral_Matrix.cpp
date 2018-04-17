class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)return vector<int>{};
		int m = matrix.size()-1;
		int n = matrix[0].size() - 1;
		vector<int>res;
		for (int i = 0; (i <= n / 2)&&(i<=m/2); i++) {
			spiralmatrix(matrix, i, m, n, res);
		}
		return res;
	}
	void spiralmatrix(vector<vector<int>>& matrix, int start, int m, int n, vector<int> &res) {
		int endx = n - start;
		int endy = m - start;
		for (int i = start; i <= endx; i++)
			res.push_back(matrix[start][i]);
		if (endy > start) {
			for (int i = start + 1; i <= endy; i++)
				res.push_back(matrix[i][endx]);
		}
		if (endy > start&&endx > start) {
			for (int i = endx - 1; i >= start; i--)
				res.push_back(matrix[endy][i]);
		}
		if (endy > start&&endx > start&&endy > start + 1) {
			for (int i = endy - 1; i > start; i--)
				res.push_back(matrix[i][start]);
		}
	}
};
//虽然有大神代码，但是其实剑指offer更加简单易懂，而且容易操作，我爱剑指offer
