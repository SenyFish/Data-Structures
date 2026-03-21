#include<iostream>
using namespace std;
struct ListNode {
    int val;         
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next; //n1的值随着形参n0的变化而变化
    P->next = n1;
    n0->next = P;
};
/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode *n0) {
    if (n0->next == nullptr)
        return; //结束函数执行 
    // n0 -> P -> n1
    ListNode *P  = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    delete P;
} 
/* 访问链表中索引为 index 的节点 */
ListNode *access(ListNode *head, int index) { //这里的ListNode *access就代表返回值的类型是ListNode指针 
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next; //可以理解为n1=n2 此时head的值是n2的地址,依此类推 
    }
    return head; 
}
/* 在链表中查找值为 target 的首个节点 */
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) { 
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}
int main()
{
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    ListNode *P  = new ListNode(5);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    insert(n2,P); 
	remove(n2);
	ListNode *temp=access(n0,3); //访问节点
	//cout <<"节点的值是"<<temp->val;
    cout<<find(n0,3);//查找节点 
	 
    /*输出各个节点的值*/ 
   /* ListNode *current = n0; //把n0(链表开头)的地址赋值给current这个指针 
    while (current!= nullptr) {
        cout << current->val << " ";
        current = current->next; //把下一个节点的地址赋值给自己，也就是n0变n1 
    }
    cout << endl;*/
}


