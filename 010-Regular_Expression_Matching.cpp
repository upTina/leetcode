//下面为leeccode解法：
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() == 1) {
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		}
		if (p[1] != '*') {
			if (s.empty()) return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};
//下面为《剑指offer》上面的解法：
class Solution {
public:
    bool match(char* str, char* pattern){
        if(*str=='\0'&&*str==*pattern)
            return true;
        if(*(pattern+1)=='*'){
            if(*pattern==*str||*pattern=='.'&&*str!='\0'){
                return match(str+1,pattern+2)||match(str+1,pattern)||match(str,pattern+2);
            }else{
                return match(str,pattern+2);
            }
        }else{
            if(*pattern==*str||*pattern=='.'&&*str!='\0')
                return match(str+1,pattern+1);
            else 
                return false;
        }
        return false;
    }
};
/*
以leeccode为主进行讨论:
这道题目，逻辑很复杂，考虑的情况很多。由于给的字符串是string类型，不能通过当前是否是'\0'来判断是否是结尾，所以需要判断string里面的个数具体是
多少，所以每次到字符串结尾都需要调用.size()，增加了讨论的繁琐程度。
也许是因为上面的原因，剑指offer的解法，明显比leecode上的解法快了很多很多。对于下面的测试用例来说：
"aaaaaaaaaaaaab"
"a*a*a*a*a*a*a*a*a*a*c"
剑指offer可能比leecode快了4倍左右。
由于时间上的问题，leecode的解法就更为巧妙一点，但也更难懂一点。
具体来说，如果待匹配字符串是“aaab”，而pattern是“a*a*a*c”的情况，在每次有*的地方，都会进入三个不同的递归调用入口，即我们要再次把(aab,a*a*a*c),
(aaab,a*a*c),(aab,a*a*c)送进iaMatch函数再次判断，这样的*越多，我们的程序速度就越慢。（为什么剑指offer的方法很快？？？）
那么leecode上面这个解法是怎么解决的呢？他是把其中一个递归拆成循环，然后再进行递归调用
while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;
			s = s.substr(1);
}
当可能存在三个入口的时候，我们直接匹配(aaab,a*a*c)，即相当于直接去掉模式中的第一个*号部分来进行匹配。如果不匹配，则s去掉首字母，这相当于，用a*这个模式
消掉了一个a，然后再次进行匹配。直到最后变成了(b,a*a*a*c),这种情况下是不存在三个入口的情况的。我们直接匹配(b,a*a*c)，这个字符对进行下一次函数后，
最终会再次以（b，a*c）的形式再次递归调用，然后再次以（b,c）的形式，递归调用，最后返回false；
*/








