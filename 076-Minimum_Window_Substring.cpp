class Solution {
public:
	string minWindow(string s, string t) {
		if (t.size() > s.size()) return "";
		string res = "";
		int left = 0;
		int minLength = s.size()+1;
		int count = 0;
		unordered_map<char,int> m;
		for (int i = 0; i < t.size(); i++) {
			if (m.find(t[i]) != m.end()) m[t[i]]++;
			else m[t[i]] = 1;
		}
		for (int right = 0; right < s.size(); right++) {
			if (m.find(s[right]) != m.end()) {
				m[s[right]]--;
				if (m[s[right]] >= 0) ++count;
				while (count == t.size()) {
					if (right - left + 1 < minLength) {
						minLength = right - left + 1;
						res = s.substr(left, minLength);
					}
					if (m.find(s[left]) != m.end()) {
						m[s[left]]++;
						if (m[s[left]] > 0) --count;
					}
					++left;
				}
			}
		}
		return res;
	}
};
/*
这个题目比较难。需要用一个哈希表m存下来我们需要包括的不同字母的个数，这个哈希表的意义为：

我们现在要凑够T里面的字符串的数量，还差多少个字母。

然后从左往右遍历s。在这个过程中，我们需要记录当前存储的子串的起点left，当前子串里包含的有效字母总数count。
如果遇到一个我们需要的字母，那么哈希表对应位置--。当做完自减操作之后，哈希表里对应的数据大于等于0时，说明此时遇到的这个字母确实是我们所需要的，我们
目前的子串长度就可以++count。如果做完自减操作之后对应为负数，说明这个字母的数量已经够了，现在多出来了。这个时候子串长度不需要++count。
每次遇到一个需要的字母之后，如果count和t的数量一致，说明此时存储的子串已经包含了需要的所有字母。那么就可以进一步操作。
如果当前子串长度小于历史最短子串，那么就替换掉历史最小。
子串的left++，开始寻找新的子串。这个操作中，left对应的位置如果是不需要的字母，那么left直接++。如果是需要的字母，那么就让m对应数据++。如果m对应的数据
加完之后仍然为0，或者负，说明这个字母子串里面有很多，少了一个也仍然能组成符合要求的子串。那么我们继续让left++；如果m对应的数据为正，说明我们现在少了这
个字母以后，子串当中开始缺少这个字母了，也就是说子串不能再满足要求了，那么count--。left不再++。然后我们以这个位置为新的left位置，继续寻找合适的rigth
*/
