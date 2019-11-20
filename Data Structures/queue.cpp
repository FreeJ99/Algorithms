#include<iostream>

using namespace std;

class queue{
    private:
        struct Node{
            Node* next;
            int data;
        };
        Node* front;
        Node* back;
        
        Node* createNode(int d){
            Node* newN = (Node*)malloc(sizeof(Node));
            newN->next = NULL;
            newN->data = d;
            return newN;
        }

    public:
        queue(){
            front = NULL;
            back = NULL;
        }

        void push(int d){
            Node* newN = createNode(d);
            if(back != NULL)
                back->next = newN;
            back = newN;
            if(front == NULL)
                front = newN;
        }
        
        void pop(){
            Node* target = front;
            front = front->next;
            if(front == NULL)
                back = NULL;
            free(target);
        }

        int mFront(){
            return front->data;
        }

        bool empty(){
            return (front == NULL);
        }
};

int main(){
    queue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    while(!myQueue.empty()){
        cout<< myQueue.mFront() << endl;
        myQueue.pop();
    }

    myQueue.push(4);
    myQueue.push(5);

    while(!myQueue.empty()){
        cout<< myQueue.mFront() << endl;
        myQueue.pop();
    }

    return 0;
}