class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		string s;
		for (int i = 0; i < strs.size(); i++) {
			s = strs[i];
			sort(s.begin(), s.end());
			m[s].push_back(strs[i]);
		}
		vector<vector<string>> res;
		for (auto iter = m.begin(); iter != m.end(); iter++)
			res.push_back(iter->second);
		return res;
	}
};
/*
每个字符，总得来说是固定的几个字母变换顺序得到的。所以我们可以把这几个字母当做key，然后把字符放在哈希表中。可是做到这里我出问题了，怎么才能把这些字母当做
键值呢。
原来可以把字母进行排序，那么相同的几个字母排完序以后肯定也一样，那就可以存到哈希表里了。
在这里还有哈希表的一个用法，那就是一个键对应一个string组成的vector。m[s]对应的就是s所对应的vector，我们就可以直接把m[s]当做一个vector来进行后续操作
这里还是对关联容器不熟悉。
*/
