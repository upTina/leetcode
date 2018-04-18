# 1.这是什么？
&emsp;&emsp;这个代码库是我练习leetcode时写的代码的一个集合。今天是2018年4月18日 14:13:55，我大概做了剑指offer上所有的题，应该有66道题目和他们的变体，一共80道题左右。后来leecode又做了一些题目，目前为止一共也做了66道，从正式开始刷题到现在一共大概140道。刚开始做这些题目的时候，抓耳挠腮，没有思路。每做一道题都感觉这是一道新题，需要有全新的解法，每次都需要查阅被人的方法和代码。这个过程也很有一番变化。一开始看别人的方法，看半天看不懂；后来看别人的代码，看了一会儿看出了思路；现在呢，可能可以独立解答题目了。在这个过程当中，从一开始的不会做，到现在的居然有了一些心得体会，我觉得这个变化也很奇妙。在做完每道题之后，我都会写一些这道题的技巧和感悟。但是现在感觉有了一些通用的思路和想法，所以就整理到这里，方便自己记录心得，更希望以后能做到温故而知新。下面的思路目前看来可能很散乱，有时间有需要的话，我还会再次整理。
# 2.一些感悟
+ 如果给出了一个有序或者基本有序的数组、矩阵或者存储数据的东西，然后在里面寻找什么，那么基本上都可以用二分查找法来进行求解。
+ 如果一个题目需要节省时间，那么一般都需要我们使用一些辅助内存，用空间换时间，这个辅助内存往往很可能是哈希表。而有的时候可能我们只能使用常数项的辅助空间，这个时候：我们可以利用题目给出的数组本身，可能需要一边在数组里查找数据，一方面把查找的结果存储到这个数组里面的特定位置。
+ 那些“重复”或者“不重复”的问题，基本都需要哈希表的出现。哈希表的构造也有技巧。
  + 首先unordered_map是一个c++定义好的哈希表。
  + 有时候不需要这么麻烦，比如只有字符a-z的时候，我们直接用一个有26个元素的int型数组就能替代，一个字符变量a对应的数组下标就是a-‘a’。
  + 如果很多字符的话，就用一个包含256个元素的int型替代，因为字符（不包括汉字）都是8位无符号整型，所以对应的数字就是0-255。
  + 有的时候哈希表可能对应多个值，我们可以用unordered_map来定义哈希表，然后对应的value为vector形式，这样有新的对应就可以直接push_back。
+ 如果一个问题，很明显可以用递归来计算，而每次递归都可以把总问题分解为很明显的子问题，那么递归往往会很花时间，我们需要用动态规划来求解。
+ 如果有的问题规模为n，我们需要遍历数据，而这种遍历的for循环层数可能是随着n的不同而不同的，那么我们往往需要使用递归的方法，每次递归遍历一下，递归的for循环就不需要我们一层一层手写了。
+ 在用递归遍历所有可能的结果时，如果我们已经知道什么情况下需要递归，什么情况下不需要递归，即我们知道递归的结果一定是错误的时候，我们可以在递归的入口加入一些判定条件，没必要递归就不进入递归。那么此时的递归，就变成了回溯法。
+ 遇到树的问题，一般情况下也许都需要使用递归。而我们只需要考虑三个部分，根节点，左子树，右子树。
to be continued...
