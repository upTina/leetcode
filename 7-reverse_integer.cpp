int reverse(int x) {
    long ans = 0;
		while (x!=0) {
			  ans = ans * 10 + x % 10;
		    if (ans>INT_MAX  || ans<INT_MIN ) return 0;
			  x /= 10;
		}
        return ans;
 }
 ###1.if判断放在循环里面比较节省时间，因为如果中途就已经溢出的话，就不需要在接着往下算了
 
