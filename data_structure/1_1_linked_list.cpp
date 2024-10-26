/*
linked list-連結リスト-链表
*/
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

// 0. 链表用结构体定义：
struct Node{
    int val;
    Node* next;
};
/* 全局变量 因此所有的Insert函数都不用返回值
如果是在main函数里声明的head则需要每个Insert函数返回值 因为此时head变成了局部变量
所以这里写的是全局变量版本 实际上局部变量版本实现效果相同*/
Node* head; 
// 1. Insert_1 尾部加链表：
void Insert_1(int data){ 
    Node* temp = new Node(); // 分配动态内存 相当于C中的malloc函数
    temp->val = data;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else{
        Node* temp1 = head; // 指针相等==指的地方相同
        // 遍历链表：
        while(temp1->next!=NULL){ 
            // 打印也是同样的道理 循环条件有些许不同
            temp1 = temp1->next;
        }
        temp1->next = temp; // 更新链表末尾
    }
}
// 2. Insert_2 头部加链表：
void Insert_2(int data){
    Node* temp = new Node();
    temp->val = data;
    temp->next = head;
    head = temp; // 更新head的值
} 
// 3. Insert_3 任意部位加链表：
void Insert_3(int data, int pos){
    Node* temp1 = new Node();
    temp1->val = data;
    temp1->next = NULL;
    if(pos == 1){
        // 如果在第一个位置加 相当于Insert_2：
        temp1->next = head;
        head = temp1;
        return; // return 这条语句非常重要
    }
    Node* temp2 = head; // 此时不需要再动态分配内存了
    for(int i=0; i<pos-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
// 4. 删除一个链表节点：
void Delete(int pos){
    Node* temp1 = head;
    if(pos = 1){
        head = temp1->next;
        delete temp1;
        return;
    }
    for(int i=0; i<pos-2; i++) 
        temp1 = temp1->next;
    Node* temp2 = temp1->next;
    temp1->next = temp2->next; // 修复链表
    delete temp2; // 释放内存 C使用free(temp2);
}
// 5. 反转一个链表-迭代：
void Reverse(){
    Node *current, *prev, *next;
    current = head;
    prev = NULL; // 前一个节点 也就是反转后的后一个节点 最开始是让第一个节点next指向NULL 所以初始化为NULL
    // 通过遍历的方式将每一个节点的next指针转向 而不是改变该地址的节点里的值
    while(current != NULL){
        next = current->next; // 为了防止直接反转每一个节点 先把节点原来的下一节点保存
        current->next = prev; // 反转节点
        prev = current;
        current = next; // 依次移位
    }
    head = prev; // 在最后一步 current和next都指向NULL而prev指向最后一个节点 所以调整head通过赋prev的值
}
// 6. 打印链表-遍历：
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
// 7. 打印链表-递归：
void Print_r(Node* p){
    if(p = NULL){
        cout << endl;
        return;
    } // 递归退出的条件
    cout << p->val << " ";
    Print_r(p->next); // 将自己的下一节点递归进去
}
// 7.1. 反向打印链表-递归 不改变链表的结构：
void Print_r2(Node* p){
    if(p = NULL){
        cout << endl;
        return;
    }
    Print_r2(p->next);
    cout << p->val << " "; // 将递归写在打印之前即可实现
}
// 8. 反转一个链表-递归：
void Reverse_r(Node* p){
    if(p->next == NULL){
        head = p;
        return;
    } // 递归退出条件 递归到最后一个节点时把它赋值给head
    Reverse_r(p->next);
    // 根据递归推出条件 以下语句均是p指向倒数第二个节点及以前节点会执行的
    Node* q = p->next;
    q->next = p;
    p->next = NULL; // 递归不用担心链接断掉 因为p的值存在递归树里面 并且每次返回执行的p值都不相同
}
int main(){
    head = NULL;
    int n, data;
    cout << "how many numbers?" << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "please enter the number(s)" << endl;
        cin >> data;
        Insert_1(data);
        Print();
    }
    return 0;
}
