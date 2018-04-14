class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>res;
		backtrack(res,"", 0, 0, n);
		return res;
	}
	void backtrack(vector<string>&res,string str,int left, int right, int max) {
		if (str.size() == max * 2) {
			res.push_back(str);
			return;
		}
		if (left < max) 
			backtrack(res, str + '(', left + 1, right, max);
		if (right < left)
			backtrack(res, str + ')', left, right + 1, max);
	}
};

/*
典型的回溯法解题思路。最近在思考回溯问题的时候，知道需要用回溯，总是感觉答案呼之欲出，但却想不出来解决方案。leetcode论坛上有个哥们有同样的困惑
kunlaotou commented 2 months ago:
I know this problem will use backtracking, but I can't write the code. How do you come up with the code? How should I practice, do anyone tell me
有位大佬做出了回复
baby_groot commented 2 months ago
@kunlaotou To be able to come up with a good solution to a backtracking problem, a very good grasp on recursion is required.
I like to think of it this way,
Recursion is nothing but all the possible situations that arise in a problem.
Backtracking is very similar to recursion, but you should know which case(s) will not be a part of the solution.

Bonus,
Having a good knowledge of recursion will also help you come up with DP solutions.
Let me know your thoughts and how you plan to proceed.
对我很有帮助。其实回溯就是一种递归，一种对解空间的深度搜索。所以baby_groot说递归只不过是所有的解的集合。
而回溯和递归很像，但是使用回溯法的时候你需要知道所有这些解那个解是真正的解，哪个不是真正的解。
如果这个题，不加if(left<max)和if(right<left)的话，这样的递归其实就是对解的暴力遍历。而加上这些条件，这就是我们期待的回溯：遍历所有正确的情况。
*/
