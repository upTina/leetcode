class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
		vector<int> res{};
		while (i < m&&j < n) {
			if (nums1[i] <= nums2[j]) { 
				res.insert(res.end(), nums1[i]);
				i++;
			}else {
				res.insert(res.end(), nums2[j]);
				j++ ;
			}
		}
		if (i == m) {
			for (; j < n; j++)
				res.insert(res.end(), nums2[j]);
		}
		if (j == n) {
			for (; i < m; i++)
				res.insert(res.end(), nums1[i]);
		}
		nums1 = res;
    }
};
//上面是一般思路。但是由于题目已经告诉我们nums1的容量足够大，能够放下nums1+nums2所有元素，所以我们可以先放最大的元素，放到nums[m+n-1]这个位置，如下：
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
