#include<iostream>
#include<vector>

using namespace std;

class Heap{
    private:
        vector<int> a;

        void climb(int idx){
            while(idx > 0){
                if(a[idx] <= a[(idx-1)/2])
                    break;
                swap(a[idx], a[(idx-1)/2]);
                idx = (idx-1)/2;
            }
        }

        void descend(int idx){
            while(true){
                int bigger = 2*idx + 1;
                if(a[2*idx+2] > a[2*idx+1]){
                    bigger = 2*idx + 2;
                }
                if((bigger > a.size()) || (a[idx] >= a[bigger]))
                    break;
                swap(a[idx], a[bigger]);
                idx = bigger;
            }
        }

        void printVector(){
            for(auto x: a){
                cout<< x << " "; 
            }
            cout<< endl;
        }

    public:
        void push(int d){
            a.push_back(d);
            climb(a.size()-1);
        }

        void pop(){
            a[0] = a[a.size()-1];
            a.pop_back();
            descend(0);
        }

        int top(){
            return a[0];
        }

        bool empty(){
            return (a.size() == 0);
        }
};

int main(){
    Heap hp;

    hp.push(3);
    hp.push(1);
    hp.push(2);
    hp.push(5);
    hp.push(4);

    while(!hp.empty()){
        cout<< hp.top() << endl;
        hp.pop();
    }
    return 0;
}