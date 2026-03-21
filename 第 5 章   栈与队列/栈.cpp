#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* Init(int x) { 
    int tmp;
    if (x <= 0) {cout<<"Init()参数错误";return nullptr;} // 如果长度为0或负数，直接返回
	
    ListNode *current = nullptr;
	ListNode *head=current;
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
    return head; 
}
int Length(ListNode* head) { //长度
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
ListNode* Access(ListNode *head,int index){/* 访问链表中索引为 index 的节点 */
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

} 
/* 链表实现的栈 */
struct LinkedListStack {
	ListNode *head=nullptr;
	LinkedListStack(int num){
		this->head = Init(num);
	};
	void push(int num){  //入栈 
		ListNode *current=new ListNode(num);
		current->next=this->head;
		this->head=current;
	};
	void pop(){ //出栈 
		this->head=head->next;	//原头节点已经断开连接，但内存还存在，此处为节省时间没有释放内存 
	}
};
int main() {
	LinkedListStack Stack(4);
	Print(Stack.head);
	Stack.push(9); 
	Print(Stack.head);
	Stack.pop();
	Print(Stack.head);
//	ListNode* head = Init(3); // 初始化链表
//	cout<<Search(head,1);
//	cout<<Access(head,0)->val; //访问未定义行为，但为了节省时间没有处理
// 	Insert(head,4,99);
//	Print(head);
}

