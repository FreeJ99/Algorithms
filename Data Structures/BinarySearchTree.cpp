#include<iostream>
#include<limits>

using namespace std;

struct Node{
            int data;
            Node* left;
            Node* right;
            Node(int data):data(data){
                left = nullptr;
                right = nullptr;
            }
        };

class BST{
    private:
        Node* root;

        Node* add(Node* curr, int d){
            if(curr == nullptr)
                return new Node(d);
            if(d <= curr->data){
                curr->left = add(curr->left, d);
            }
            else{
                curr->right = add(curr->right, d);
            }
            return curr;
        }

        Node* deleteSmallest(Node* curr, int &x){
            if(curr == nullptr)
                return nullptr;
            if(curr->left == nullptr){
                x = curr->data;
                Node* ret = curr->right;
                delete(curr);
                return ret;
            }
            curr->left = deleteSmallest(curr->left, x);
            return curr;
        }

        Node* deleteNode(Node* curr, int d){
            if(curr == nullptr)
                return nullptr;
            if(d < curr->data){
                curr->left = deleteNode(curr->left, d);
            }
            else if(d > curr->data){
                curr->right = deleteNode(curr->right, d);
            }
            else{
                if(curr->right == nullptr){
                    Node* left = curr->left;
                    delete(curr);
                    return left;
                }
                int x;
                curr->right = deleteSmallest(curr->right, x);
                curr->data = x;
            }
            return curr;
        }

        void clear(Node* curr){
            if(curr == nullptr)
                return;
            clear(curr->left);
            clear(curr->right);
            delete(curr);
        }

        void printTree(Node* curr){
            if(curr == nullptr)
                return;
            printTree(curr->left);
            cout<< curr->data << " ";
            printTree(curr->right);
        }

        bool check(Node* curr, int& minV, int& maxV){
            if(curr == nullptr){
                //cout << "Null" << endl;
                maxV = numeric_limits<int>::min();
                minV = numeric_limits<int>::max();
                return true;
            }
            //cout<< "Curretnt " << curr->data << endl;
            
            int minL, maxL;
            if(!check(curr->left, minL, maxL))
                return false;

            int minR, maxR;
            if(!check(curr->right, minR, maxR))
                return false;

            if((maxL > curr->data) || (minR < curr->data))
                return false;

            maxV = max(curr->data, maxR);
            minV = min(curr->data, minL);

            return true;
        }

    public:
        BST():root(nullptr){}
        
        void add(int d){
            root = add(root, d);
        }

        void deleteNode(int d){
            root = deleteNode(root, d);
        }

        void clear(){
            clear(root);
            root = nullptr;
        }

        void printTree(){
            printTree(root);
            cout<< endl;
        }
};

int main(){
    BST a;
    a.add(2);
    a.add(4);
    a.add(3);
    a.add(5);
    a.add(1);
    
    a.printTree();
    a.deleteNode(5);
    a.printTree();
    a.deleteNode(2);
    a.printTree();
    a.deleteNode(1);
    a.printTree();
    a.add(9);
    a.add(0);
    a.printTree();

    a.clear();
    a.printTree();

    return 0;
}