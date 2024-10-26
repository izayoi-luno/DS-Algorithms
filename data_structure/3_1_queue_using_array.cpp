/*
implementation of the ADT of queue-キュー-队列
by using array-配列-数组
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N 10
using namespace std;

int A[N];
int front = 1;
int tail = -1;

bool IsEmpty(){
    if(front == -1 && tail == -1) return true;
    else return false;
}

void Enqueue(int x){
    // instead of using a simple array, utilizing LOOP ARRAY to avoid waste of memory
    if((tail+1) % N == front){ // is the current place is i, the next position is no longer i+1 but (i+1) % N
        cout << "Error: the queue is full" << endl;
        return;
    }
    else if(IsEmpty()){
        tail = 0;
        front = 0;
    }
    else tail = (tail+1) % N; // pay attention here also IT IS NOW A LOOP ARRAY!!!
    A[tail] = x;
}

void Dequeue(){
    if(IsEmpty()){
        cout << "Error: the queue is empty" << endl;
        return;
    }
    else if(front == tail){
        front = -1;
        tail = -1;
    }
    else{
        front = (front+1) % N;
    }
}

int Front(){
    if(IsEmpty()){
        cout << "Error: the queue is empty" << endl;
        return;
    }
    return A[front];
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