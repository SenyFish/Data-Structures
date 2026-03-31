#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} //初始化链表 ListNode->val
}; 

ListNode* Init(int x) { //初始化函数
    int tmp;
    if (x <= 0) {cout<<"Init()参数错误";return nullptr;} // 如果长度为0或负数，直接返回
    ListNode *current = nullptr; 
	ListNode *head = current; 
    for (int i = 1; i <= x; i++) {
        cout << "请输入节点:" << i << "的值: ";
        cin >> tmp;
	    if(i==1) {
		    current=new ListNode(tmp);
			head=current;	
		}
        else{
  			current->next= new ListNode(tmp); 
        	current = current->next; // 移动到下一个节点
		}
    }
    return head; //最后返回头节点
}
int Length(ListNode* head) { //长度，返回长度
	int i=0;
	while(head!=nullptr){
 		head=head->next;
 		i++;
 	}
   return i; 
}
void Print(ListNode* head){ //输出
	if(head==nullptr){
		cout<<"nullptr"<<endl;
		return;
	} 
	cout<<head->val<<"->";
	return Print(head->next);
}
void Insert(ListNode *head,int n,int i){  //插入
	if(n>Length(head)){
		cout<<"超过最大值"<<endl;
		return;
	}
	ListNode *p=new ListNode(i);
	for(i=1;i<n;i++){
		head=head->next;
	}
 	p->next=head->next;
  	head->next=p;
}              
ListNode* Access(ListNode *head,int index){//访问链表中索引为 index 的节点
	if(index<1) {cout<<"Access()参数错误";return nullptr;}
	else
	{
		for(int i=1;i<index;i++){ //当index为1时，这个for循环语句将不会执行，即i<index为假
			head=head->next;
		}
		return head;
	}

}
int Search(ListNode *head,int target) {/* 在链表中查找值为 target 的节点 */
	int i=1;
	while(head!=nullptr){
		if(head->val==target) return i;
 		head=head->next;
 		i++;
 	}
 	cout<<"没找到";
 	return 0;
} 
struct Queue{ //基于链表
	ListNode *head=nullptr;
	ListNode *rear=nullptr;//尾节点
	Queue(int x){
		this->head=Init(x);//将头节点指针赋值
		this->rear=Access(this->head,Length(this->head));//将尾节点指针赋值，因为此处长度是链表总长度
	}
	void Push(int x){ //入队
		ListNode *P=new ListNode(x);
		this->rear->next=P;//此处需要将P节点的地址赋值给rear节点！ 
		rear=P;
		P->next=nullptr;
	}
	void Pop(){ //弹出
		ListNode *tmp=this->head;
		this->head=this->head->next;
		delete tmp;
	}
	bool Empty(){
		if(this->head==nullptr)
			return 0;
		else
			return 1;
	}
};
int main(){
	Queue q1(4);
//	cout<<q1.rear;
	Print(q1.head);
	q1.Push(6);
	Print(q1.head);
	q1.Pop();
	Print(q1.head);
	cout<<q1.rear->val;
} 
