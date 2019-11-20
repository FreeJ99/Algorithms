#include<iostream>

using namespace std;

struct Node{
    Node* next;
    int data;
};

Node* createNode(int d){
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->next = NULL;
    newN->data = d;
    return newN;
}

void push(Node** head, int d){
    Node* newN = createNode(d);
    newN->next = *head;
    *head = newN;
}

int top(Node** head){
    return (*head)->data;
}

void pop(Node** head){
    if(*head == NULL)
        return;
    Node* target = *head;
    *head = (*head)->next;
    free(target);
}

bool empty(Node** head){
    if(*head == NULL)
        return true;
    return false;
}

int main(){
    Node* myStack = NULL;
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    while(!empty(&myStack)){
        cout<< top(&myStack) << endl;
        pop(&myStack);
    }

    return 0;
}