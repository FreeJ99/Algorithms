#include<iostream>
#include<stdlib.h>

using namespace std;
struct Node{
    Node* next;
    int data;
    Node(int data):data(data){}
};

Node* createNode(int d){
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->data = d;
    newN->next = NULL;
    return newN;
}

void addNode(Node** head, int d){
    Node* newN = createNode(d);
    if((*head) == NULL){
        *head = newN;
        return;
    }
    Node* currN = *head;     
    while(currN->next != NULL){
        currN = currN->next;
    }
    currN->next = newN;
}

bool containsNode(Node** head, int d){
    Node* currN = *head;
    while(currN != NULL){
        if(currN->data == d)
            return true;
        currN = currN->next;
    }
    return false;
}

void deleteNode(Node** head, int d){
    if((*head)->data == d){
        Node* target = *head;
        *head = (*head)->next;
        free(target);
        return;
    }
    Node* currN = *head;
    while(currN->next != NULL && (currN->next)->data != d){
        currN = currN->next;
    }
    if(currN->next != NULL){
        Node* target = currN->next;
        currN->next = (currN->next)->next;
        free(target);
    }
}

void printList(Node** head){
    Node* currN = *head;
    while(currN != NULL){
        cout<< currN->data << " ";
        currN = currN->next;
    }
    cout<< endl;
}

int main(){
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
 
    printList(&head);
    cout<< containsNode(&head, 1) << endl << containsNode(&head, 0) << endl;
    deleteNode(&head, 1);
    printList(&head);

    return 0;
}