#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 初始化链表，返回头节点
ListNode* Init(int x) { 
    if (x <= 0) {
        cout << "Init()参数错误" << endl;
        return nullptr;
    }
    
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    int tmp;
    
    for (int i = 1; i <= x; i++) {
        cout << "请输入节点:" << i << "的值: ";
        cin >> tmp;
        
        // 创建新节点
        ListNode* newNode = new ListNode(tmp);
        
        if (head == nullptr) {
            // 如果是第一个节点
            head = newNode;
            current = newNode;
        } else {
            // 添加到链表末尾
            current->next = newNode;
            current = newNode;
        }
    }
    return head; 
}

// 计算链表长度
int Length(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        current = current->next;
        length++;
    }
    return length; 
}

// 打印链表，使用迭代而非递归，避免栈溢出
void Print(ListNode* head) {
    if (head == nullptr) {
        cout << "nullptr" << endl;
        return;
    }
    
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << "->";
        } else {
            cout << endl;
        }
        current = current->next;
    }
}

// 在指定位置插入节点
bool Insert(ListNode* head, int position, int value) {
    if (head == nullptr) {
        cout << "链表为空" << endl;
        return false;
    }
    
    if (position <= 0 || position > Length(head)) {
        cout << "插入位置无效" << endl;
        return false;
    }
    
    ListNode* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    
    ListNode* newNode = new ListNode(value);
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

// 访问链表中索引为index的节点
ListNode* Access(ListNode* head, int index) {
    if (head == nullptr) {
        cout << "链表为空" << endl;
        return nullptr;
    }
    
    if (index <= 0) {
        cout << "Access()参数错误：索引必须为正数" << endl;
        return nullptr;
    }
    
    int length = Length(head);
    if (index > length) {
        cout << "Access()参数错误：索引超出链表长度" << endl;
        return nullptr;
    }
    
    ListNode* current = head;
    for (int i = 1; i < index; i++) {
        current = current->next;
    }
    return current;
}

// 在链表中查找值为target的节点，返回索引，未找到返回-1
int Search(ListNode* head, int target) {
    if (head == nullptr) {
        cout << "链表为空" << endl;
        return -1;
    }
    
    ListNode* current = head;
    int index = 1;
    
    while (current != nullptr) {
        if (current->val == target) {
            return index;
        }
        current = current->next;
        index++;
    }
    
    cout << "没找到值为" << target << "的节点" << endl;
    return -1;
}

// 释放链表内存
void FreeList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    ListNode* head = Init(3); // 初始化链表
    cout << "链表内容：";
    Print(head);
    
    int target = 1;
    cout << "查找值" << target << "的索引：" << Search(head, target) << endl;
    
    int position = 2, value = 99;
    if (Insert(head, position, value)) {
        cout << "在位置" << position << "插入值" << value << "后链表内容：";
        Print(head);
    }
    
    int index = 3;
    ListNode* node = Access(head, index);
    if (node != nullptr) {
        cout << "索引" << index << "处的节点值为：" << node->val << endl;
    }
    
    // 释放内存
    FreeList(head);
    return 0;
} 