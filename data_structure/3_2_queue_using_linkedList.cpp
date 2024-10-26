/*
implementation of the ADT of queue-キュー-队列
by using linked list-連結リスト-链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next; 
};
Node* front = NULL;
Node* tail = NULL; // pay attention, in order to ensure that the time complexity is O(1), two pointers are used

void Enqueue(int x){
    Node* temp = new Node();
    temp->val = x;
    temp->next = NULL;
    if(front == NULL && tail == NULL){
        front = tail = temp;
        return;
    }
    tail->next = temp; // add a queue node
    tail = temp; // move the tail
}

void Dequeue(){
    Node* temp = front;
    if(front == NULL) return;
    else if(front == tail){
        front = tail = NULL;
    }
    else{
        front = front->next;
    }
    delete temp;
}

int Front(){
    if(front == NULL){
        cout << "Error: the queue is empty" << endl;
        return;
    }
    return front->val;
}

int main(){
    Enqueue(5);
    Enqueue(7);
    Enqueue(12);
    Dequeue();
    Enqueue(0);
    Dequeue();
    int fron = Front();
    cout << fron << endl;
}