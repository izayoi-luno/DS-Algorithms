#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// 9. 双向链表：
struct Node{
    int val;
    Node* next;
    Node* prev;
};
Node* head;
Node* GetNewNode(int data){
    Node* newNode = new Node(); // ***在这里再次重申在堆Heap中分配动态内存 如果选择构建Node型变量是局部变量 函数返回或执行结束后将会被收回 即使return地址也没用***
    newNode->val = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void InsertAtHead(int data){
    Node* temp = GetNewNode(data);
    if(head == NULL){
        head = temp; // 完整的写法其实是前面还有一句 temp->next = head; 但是由于这里head是指向NULL的 和temp所get到的初始节点的next相同 故省略
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void Print(){
    Node* temp = head;
    cout << "Forward: ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void ReversePrint(){
    Node* temp = head;
    while(temp->next != NULL){ // 注意循环终止条件不同
        temp = temp->next;
    }
    cout << "Reverse: ";
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main(){
    head = NULL;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    // 最后结果 Forward: 6 4 2 Reverse: 2 4 6
    return 0;
}