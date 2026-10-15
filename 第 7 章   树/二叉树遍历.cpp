#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;          // 节点值
    TreeNode *left;   // 左子节点指针
    TreeNode *right;  // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/* 层序遍历 */
void levelOrder(TreeNode *root){
	if(root == nullptr){
		cout<<"根节点为空";
		return;
	}
	
	queue<TreeNode*> q1;
	q1.push(root);
	while(!q1.empty()){
		TreeNode *current = q1.front();
		cout<<current->val;
		q1.pop();
		if(current->left != nullptr)
			q1.push(current->left);
		if(current->right != nullptr)
			q1.push(current->right);    
	}                     
}
//前序遍历 “前”指的是根节点在前 根->左->右 
void preOrder(TreeNode *root){
	if(root == nullptr)
		return;
	cout<<root->val<<"————";
	preOrder(root->left); //打印左节点地址
	preOrder(root->right); //打印右节点地址
}

//中序遍历 左->根->右
void inOrder(TreeNode *root){
	if(root == nullptr)
		return;
	inOrder(root->left); //打印左节点地址
	cout<<root->val<<"————";
	inOrder(root->right); //打印右节点地址
}
		
int main ()
{
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
//	levelOrder(n1);
	inOrder(n1);
//	vector<int> v1;
//	v1 = levelOrder(n1);
//	for(int i=0;i < v1.size();i++)
//		cout<<v1[i]<<"—————";

}
 
