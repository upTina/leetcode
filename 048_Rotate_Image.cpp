class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - 1 - j]);
			}
		}
	}
};
/*
这个题我一开始还在思考旋转前后对应数字坐标之间的映射关系，后来一通乱试之后发现，只要把矩阵先转置，然后再左右对称一下，就得到最后的结果了。
感觉像是一下子蒙对的。。。
*/
