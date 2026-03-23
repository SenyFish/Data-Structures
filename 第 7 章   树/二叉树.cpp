#include <iostream>
using namespace std;

struct TreeNode {
    int val;          // 节点值
    TreeNode *left;   // 左子节点指针
    TreeNode *right;  // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//TreeNode* Init(int x){//输入要初始化的长度
//	if(x<=0)
//		retrun nullptr;//输入
//	TreeNode *left=nullptr;
//	TreeNode *right=left;
//	for(i=1;i<=x;i++){
//		TreeNode *
//	}
//	
//}
void Insert(TreeNode *head,int val,char flag_head,char flag_current){
	if(head==nullptr){
		cout<<"head is null";
		return;
	}
	TreeNode* current=new TreeNode(val);
	if(flag_head=='L'&&flag_current=='R'){ //如果要插入到头节点的左节点
		TreeNode* tmp = head->left;//获取原本左节点的指针并暂存
		head->left = current;
		current->right = tmp;
	}
	else if(flag_head=='R'&&flag_current=='L'){
		TreeNode* tmp = head->right;
		head->right = current;
		current->left = tmp;
	}
	else if(flag_head=='R'&&flag_current=='R'){
		TreeNode* tmp=head->right;
		head->right = current;
		current->right = tmp;
	}
	else if(flag_head=='L'&&flag_current=='L'){
		TreeNode* tmp=head->left;
		head->left = current;
		current->left = tmp;
	}	
	else 
	{
		delete current;
		cout<<"null";
	};
}
int main(){
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;
	n3->right=n7;
	Insert(n1,9,'L','R');
	return 0;
}