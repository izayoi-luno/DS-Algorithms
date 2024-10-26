/*
Here is the scenario of using the stack to solve particular problems
ここからはスタックのある特定の問題での使用例である
*/
/*
reverse a string - reverse a linked list
文字列を反転させる｜連結リストを反転させる
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <stack> // standard template library - STL
using namespace std;

/*
also can write using class:

class Stack{
private:
    char A[101];
    int top;
public:
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
};
*/

struct Node{
    int val;
    Node* next;
};
Node* head = NULL;

void Reverse(char C[], int n){ // here C[] is equivalent to *C
    stack<char> S;
    for(int i=0; i<n; i++){ // here the loop is used for tranversing the string, not the stack
        S.push(C[i]);
    }
    for(int i=0; i<n; i++){
        C[i] = S.top();
        S.pop();
    }
    // two independent loops -> O(n)
}

void ReverseUseLL(){
    if(head == NULL) return;
    stack<Node*> S; // pay attention here the stack saves the POINTERS
    Node* temp = head;
    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL; // at last set the next link to be NULL
}

int main(){
    char C[51];
    cout << "Enter a string" << endl;
    gets(C);
    Reverse(C, strlen(C));
    cout << "Output = " << C << endl;
}