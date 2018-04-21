//二叉树中序遍历，非递归
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		TreeNode* p;
		stack<TreeNode*> st;
		p = root;
		while (p || !st.empty()) {
			while (p) {
				st.push(p);
				p = p->left;
			}
			p = st.top();
			res.push_back(p->val);
			st.pop();
			p = p->right;
		}
		return res;
	}
};
//二叉树的标准的中序遍历。非递归。基本都是用栈，区别在于先把谁压入栈中。如果是先序遍历，那就先把根节点压入栈中，然后从栈中取出元素，然后把取出的元素的
//左右节点再次按照正确的顺序压入栈中
//如果是中序遍历，那么就不断把左孩子节点压入栈中，然后再从栈中取出元素，然后再把取出元素的右孩子节点压入栈中。
//如果是后序遍历呢？


//二叉树先序遍历，非递归
public void preOrderWithoutRecursion(TreeNode T){ //前序遍历非递归算法  
          
        TreeNode p;  
        Stack<TreeNode> stack = new Stack<TreeNode>();  
        stack.push(T);             //先将根节点压进栈中  
        while(T!=null&&!stack.empty()){  
            p = stack.pop();        //弹出栈顶的节点赋给p  
            System.out.println(p.data);  //用输出来代替对节点的处理  
            if(p.rchild!=null){             
                stack.push(p.rchild);      //如果弹出节点的右孩子不为空则压入栈  
            }                           //注意，这里的重点是一定要先将右孩子压入栈，再将左孩子压入  
            if(p.lchild!=null){  
                stack.push(p.lchild);     //如果弹出节点的左孩子不为空则压入栈  
            }         
        }     
          
    } 
    
//二叉树后序遍历，非递归 
void PostOrder(TreeNode *root) {
    TreeNode *p = root, *r = NULL;
    stack<TreeNode*> s;
    while (p || !s.empty()) {
        if (p) {//走到最左边
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            if (p->right && p->right != r)//右子树存在，未被访问
                p = p->right;
            else {
                s.pop();
                visit(p->val);
                r = p;//记录最近访问过的节点
                p = NULL;//节点访问完后，重置p指针
            }
        }//else
    }//while
}
