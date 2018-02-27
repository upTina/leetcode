class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
		int left = 0, head = 0, max = 1, length=1;
		unordered_map<char, int> m;
		for (int i = 0; i < 26; i++)
			m['a' + 0] = 0;
		m[s[0]] = 1;
		for (int i = 1; i < s.size(); i++) {
			if (m[s[i]] == 0) {
				m[s[i]] = 1;
				length += 1;
				if (length > max) {
					max = length;
					head = left;
				}
			}else {
				for (int j = left; j < i; j++) {
					if (s[j] == s[i]) {
						length = length - j + left;
						left = j + 1;
						break;
					}else {
						m[s[j]] = 0;
					}
				}
			}
		}
		return max;
    }
};
//首先，本题和最大和子数组问题很像。最大和那个问题是如果当前子串加起来为负数，就从新开始加；而这个问题是如果遇到一个新元素是出现过的，那么就重新定位子串
//的新的起始位置；
//其次，上面我自己想的办法用了非常原生态的解法，思路很简单，写的很冗余；
//最后，看了别人非常高明的解法。建立一个hash表，hash表不光记录这个元素出现过没有，还记录了元素最近一次出现的位置，这样一旦有重复元素，就可以快速重新定
//定位子串新的起始位置。一次遍历即可解决问题。而且，由于字符都是asc码，所以hash表可以不使用unordered_map，而直接定义一个数组m[256],因为hash表有8位。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int m[256] = { 0 }, res = 0, left = 0;
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] == 0 || m[s[i]]-1 < left) {
				res = max(res, i - left + 1);
			}else {
				left = m[s[i]];
			}
			m[s[i]] = i+1;
		}
		return res;
    }
};
