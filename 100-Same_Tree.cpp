class Solution {
public:
    string a = "";
	string b = "";
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == p) return true;
		if (p == NULL || q == NULL) return false;
		p_first_order(p);
		q_first_order(q);
		return a == b ? true : false;
	}
	void p_first_order(TreeNode* p) {
		a = a + to_string(p->val);
		if (p->left != NULL) p_first_order(p->left);
		if (p->left != NULL &&p->right != NULL) p_first_order(p->right);
		if (p->left == NULL && p->right != NULL) {
			a = a + 'n';
			p_first_order(p->right);
		}
	}
	void q_first_order(TreeNode* q) {
		b = b + to_string(q->val);
		if (q->left != NULL) q_first_order(q->left);
		if (q->left != NULL &&q->right != NULL) q_first_order(q->right);
		if (q->left == NULL && q->right != NULL) {
			b = b + 'n';
			q_first_order(q->right);
		}
	}
};
//受提干启发，用了一个非常复杂，但是很直观的方法，其实可以用递归的方法，比较两棵树是不是完全一样，就分别比较左子树和右子树是不是完全一样:
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL&&p == q) return true;
		if (p == NULL || q == NULL || p->val!=q->val) return false;
		return isSameTree(p->left, q->left) == true && isSameTree(p->right, q->right) == true;
	}
};
//这个方法的意思就是当当前节点的val不一样时，两棵树肯定不同；当val值总是一样时，就继续比较左子树和右子树，直到比较到空指针，空指针==空指针，此时返回true
