#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;//上一个节点
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* Init(int x) { //初始化
    int tmp;
    if (x <= 0) {
        cout << "Init()参数错误" << endl;
        return nullptr; // 如果长度小于等于0，返回空指针
    }

    ListNode *current = nullptr;
    ListNode *head = nullptr;
    for (int i = 1; i <= x; i++) {
        cout << "请输入第" << i << "个节点的值: ";
        cin >> tmp;
        if (i == 1) {
            head = new ListNode(tmp);
			head->prev = nullptr;
			current = head;    
        }
        else {
            current->next = new ListNode(tmp); //第一次循环过后，current现在还是head
            ListNode *tmp = current;
            current = current->next; // 移动到下一个节点
//            current->prev = ;
        }
    }
    return head; 
}

ListNode* head = Init(3);

int Length(ListNode* head=head) { // 获取链表长度
    int i = 0;
    while (head != nullptr) {
        head = head->next;
        i++;
    }
    return i; 
}

void Print(ListNode* head=head) { // 打印链表
    if (head == nullptr) {
        cout << "nullptr" << endl;
        return;
    } 
    cout << head->val << "->";
    return Print(head->next);
}

void Insert(int n, int i,ListNode *head=head) {  // 插入节点
    if (n > Length(head)) {
        cout << "插入位置超出范围" << endl;
        return;
    }
    ListNode *p = new ListNode(i);
    for (int j = 1; j < n; j++) {
        head = head->next;
    }
    p->next = head->next;
    head->next = p;
}              

ListNode* Access(int index,ListNode *head=head) {  // 访问链表中索引为index的节点
    if (index < 1) {
        cout << "Access()参数错误" << endl;
        return nullptr;
    }
    else {
        for (int i = 1; i < index; i++) {
            head = head->next;
        }
        return head;
    }
}

int Search(int target,ListNode *head=head) {  // 查找节点
    int i = 1;
    while (head != nullptr) {
        if (head->val == target) return i;
        head = head->next;
        i++;
    }
    cout << "未找到目标值" << endl;
    return -1;  // 返回-1表示未找到
}

int main() {
     // 初始化链表
    Print();
    cout << Search(1) << endl;
    // cout << Access(head, 0)->val; // 访问第0个节点是非法的，会导致访问错误
    // Insert(head, 4, 99);
    // Print(head);
}

