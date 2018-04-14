class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res=0;
		if (prices.size() < 2)
			return res;
		for (int i = 1; i < prices.size(); i++)
			if (prices[i] > prices[i - 1])
				res += prices[i] - prices[i - 1];
		return res;
	}
};
//这个题主要是理解题意，理解了题目以后其实很简单。就是每天都可以买进买出，但是不能买好几次，买1次就相当于拥有了。既然这样，只要股票明天涨价，我今天就可以
//奇货可居，买上来屯着，那利润自然是明天的价钱减去今天的价钱了
