#include <iostream>
using namespace std;

struct TreeNode {
    int val;          // 节点值
    TreeNode *left;   // 左子节点指针
    TreeNode *right;  // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* Init(TreeNode *root,int n){
	if(n <= 0)
		return root; //最终返回值
	int x;
	cout<<"请输入节点的值"; cin>>x;
	
	if(x < root->val){
		root->left = new TreeNode(x);
		root->left = Init(root->left,--n);
	}
	else if(x > root->val){
		root->right = new TreeNode(x);
		root->right = Init(root->right,--n);	
	}
//	else
//		return nullptr;
	return root; //每一层的返回值
}
void Print(TreeNode *root){
	if(root == nullptr)
		return;
	cout<<root->val<<"-";
	Print(root->left);
	Print(root->right);
}
int main(){
	TreeNode *root = new TreeNode(10);
	root = Init(root,3);
//	cout<<root->val;
//	Print(root);  
	cout<<root->val<<endl<<root->left->val<<endl<<root->left->right->val<<endl<<root->left->right->right->val;
}
