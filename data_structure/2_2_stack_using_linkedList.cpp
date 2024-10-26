/*
here is the implementation of the ADT stack-スタック-栈 using linked list approach
because add/delte operation at a linked list tail is obtaining O(n)
the better way is to view the head node (not the "head" pointer) of the linked list-連結リスト-链表 as the stack top  
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* top = NULL;
// 1. Push operation
void Push(int x){
    Node* temp = new Node();
    temp->val = x;
    temp->next = top;
    top = temp;
}
// 2. Pop operation
void Pop(){
    if(top == NULL){
        cout << "Error: the stack is empty" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}
// 3. Top obtaining operation
int Top(){
    return top->val;
}
void Print(){
    Node* temp = top;
    if(top == NULL) return;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Push(2); Print();
    Push(5); Print();
    Push(8); Print();
    Pop(); Print();
    Push(15); Print();
    return 0;
}