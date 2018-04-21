class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		stack<TreeNode*>st;
		TreeNode* p = root;
		TreeNode * last = nullptr;
		while (p || !st.empty()) {
			if (p) {
				st.push(p);
				p = p->left;
			}
			else {
				p = st.top();
				if (p->right&&p->right != last) {
					p = p->right;
				}
				else {
					res.push_back(p->val);
					last = p;
					p = nullptr;
					st.pop();
				}
			}
		}
		return res;
	}
};
//二叉树的后序遍历，也是活用栈的性质。但是有个问题，必须得是从右子树回退到根节点的时候，才能开始输出根节点。所以这里需要用一个last指针记录上次输出的是
//哪个节点。回退到根节点时做一下判断，如果上次输出的是节点就是右子树，那么就直接输出跟节点，并用last记录根节点；上次输出的是左子树，那就不输出根节点，
//而是把右子树的内容按照顺序压入栈中
