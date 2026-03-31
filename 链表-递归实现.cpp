#include<iostream>
using namespace std;
/* 链表节点结构体 */
struct ListNode {
    int val;         // 节点值
    ListNode *next;  // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};
ListNode* Init(int n){ //n=要初始化的节点数量
	if(n<=0)
		return nullptr;
	int x;
	cout<<endl<<"请输入节点的值:";cin>>x;
	ListNode *head = new ListNode(x);
	head->next = Init(--n);
	return head;
}
void Print(ListNode *head){
	if(head==nullptr){
		cout<<"null"<<endl;
		return;	
	}
	cout<<head->val<<"->";
	Print(head->next);
}
void Find(ListNode *head,int val,bool &flag,int i=1){
	if(head==nullptr)
		return;
	if(head->val==val){
		cout<<endl<<"Find():"<<val<<"在链表中第"<<i<<"个节点处";
		flag = true;
	}
	Find(head->next,val,flag,++i);
}
ListNode* Del(ListNode *head,int val){
	if(head==nullptr)
		return nullptr;
	if(head->next->val==val){
		head->next = head->next->next; //将下下个节点的地址赋值给下个节点
		head->next = Del(head->next,val);
		return head;
	}
	if(head->val==val){ //如果要删除的就是头节点
		ListNode* current = head->next;
		delete head;
		current->next = Del(head->next,val);
		return current;		
	}
	head->next = Del(head->next,val);
	return head;
}
int Length(ListNode *head,int i=0){ //返回链表长度
	if(head==nullptr)
		return i;	
	return Length(head->next,++i);
}
void Access(ListNode *head,int index,int i=1){ //返回索引节点对应的值
	if(i==index){
		cout<<"Access():"<<"索引"<<i<<"对应的值为"<<head->val;
		return;
	}
	Access(head->next,index,++i); //i++：先返回旧值（当前值）,再自增,此时传入的i永远为0; ++i：i先自增，再返回自增后的值		
}
ListNode* Insert(ListNode *head,int index,int x,int i=0){ //index=要插入链表位置之前
	if(index<=0||head==nullptr){
		cout<<"Insert():"<<"索引不在该链表范围内"<<endl;
		return nullptr;
	}
	i++;
	if(index==1){
		ListNode *current = new ListNode(x);
		current->next = head;
		return current;
	}
	if(i==index-1){
		ListNode *current = new ListNode(x);
		current->next = head->next;
		head->next = current;
		return head;	
	}
	head->next = Insert(head->next,index,x,i);
	return head;
}
int main(){
	ListNode *head = Init(4);
//	head = Insert(head,6,5);
	Print(head);
//	cout<<"链表长度为:"<<Length(head);
//	Access(head,8);
//	bool flag=false;
//	Find(head,2,flag);
//	head = Del(head,6);
//	Print(head);
//	head = Access(head,3);
//	cout<<Length(head);
}