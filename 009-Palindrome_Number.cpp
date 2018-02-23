bool isPalindrome(int x) {
        int original = x;
		    if (x < 0) return false;
		    long res = 0;
		    while (x != 0) {
			      res =res*10 + x % 10;
			      x = x / 10;
		    }
		    return (original == res) ? true : false;
}
####1题目中提到“with no extra space”，不太明白extra space是什么意思，但是定义一个变量也允许
####2.负数不是回文
