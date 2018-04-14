class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int n = board.size();
		int flag;
		vector<vector<bool>> rowflag(n, vector<bool>(n, false));
		vector<vector<bool>> colflag(n, vector<bool>(n, false));
		vector<vector<bool>> cellflag(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != '.') {
					flag = board[i][j] - '1';
					if (rowflag[i][flag] || colflag[flag][j] || cellflag[i/3*3+j/3][flag]) return false;
					rowflag[i][flag] = true;
					colflag[flag][j] = true;
					cellflag[i / 3 * 3 + j / 3][flag] = true;
				}
			}
		}
		return true;
	}
};
//就直接求。。。
//我发现，辅助空间用的越多，时间就用的越少。而时间是主要的指标，所以放心用辅助内存吧！
