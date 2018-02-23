int romanToInt(string s) {
		unordered_map<char, int > list{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
		int sum = 0;
		int flag = 1;
		for (int i = 0; i < s.size() - 1; i++) {
			if (list[s[i]] >= list[s[i + 1]])
				flag = 1;
			else
				flag = -1;
			sum += list[s[i]] * flag;
		}
		sum += list[s[s.size() - 1]];
		return sum;
	}
  
  ###算法很简单，要学会unorder_map的使用，记住这个初始化方法
