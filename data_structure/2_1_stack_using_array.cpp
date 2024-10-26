/*
implementation of the ADT of stack-スタック-栈
by using array-配列-数组
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_SIZE 101
using namespace std;

int A[MAX_SIZE];

int top = -1; // subscript of the largest address of array == the top of stack, equals to -1 when the stack is empty (initialization)
// 1. push operation:
void Push(int x){
    if(top == MAX_SIZE - 1){
        cout << "Error: stack overflow" << endl;
        return;
    }
    top++;
    A[top] = x; // here can write in one line also: A[++top] = x; which means the variable top is to be increased before assignment
}
// 2. pop operation
void Pop(){
    if(top == -1){
        cout << "Error: stack empty" << endl;
        return;
    }
    top--;
}
// 3. Top operation - to get the top element - LIFO
int Top(){
    return A[top];
}
// print operation - just to see the results
void Print(){
    cout << "Stack: ";
    for(int i = 0; i <= top; i++){
        cout << A[i] << " ";
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

