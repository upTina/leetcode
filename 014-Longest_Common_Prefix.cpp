string longestCommonPrefix(vector<string>& strs) {
	string prefix;
		char a;
		if (strs.size() <= 0) return prefix;
		for (int i = 0; i < strs[0].size(); i++) {
			a = strs[0][i];
			for (int j = 0; j < strs.size(); j++) {
				if (i == strs[j].size()) return prefix;
				if (a != strs[j][i]) return prefix;
			}
			prefix += a;
		}
		return prefix;
}
//1.注意处理空串
