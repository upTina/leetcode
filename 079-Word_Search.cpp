class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (m == 0) return false;
		int n = board[0].size();
		vector<vector<bool>> haspass(m, vector<bool>(n, false));
		bool res = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (backtracking(board, haspass, i, j, 0, word)) return true;
			}
		}
		return res;
	}
	bool backtracking(vector<vector<char>>&board, vector<vector<bool>>& haspassed, int i, int j, int cur, string word) {
		if (cur == word.size()) return true;
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || haspassed[i][j] || board[i][j] != word[cur]) return false;
		haspassed[i][j] = true;
		bool res = backtracking(board, haspassed, i + 1, j, cur + 1, word) ||
			backtracking(board, haspassed, i - 1, j, cur + 1, word) ||
			backtracking(board, haspassed, i, j + 1, cur + 1, word) ||
			backtracking(board, haspassed, i, j - 1, cur + 1, word);
		haspassed[i][j] = false;
		return res;
	}
};
//自己写的程序超时了，然后看了一眼大神的。思路都差不多，但是不同的地方在于，我传递给下一层递归函数的参数太多。可能因为这个原因，递归函数得不断的建立
//栈、释放栈，所以导致程序超时。回溯法中应该只传递最最必要的参数
//这个题剑指offer上有，但是现在做的时候还是只有思路但是写的不好。所以程序这种东西一定要既会且熟练
