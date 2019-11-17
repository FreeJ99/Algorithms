#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    vector<int> adj;
}

void BFS(const vector<Node>& graph, int start){
    vector<bool> marked(graph.size());
    queue<int> nextQue;
    nextQue.push(start);

    while(!nextQue.empty()){
        int curr = nextQue.front();
        nextQue.pop();
        cout<< graph[curr].data << " ";
        for(int i=0;i<graph[curr].adj.size();i++){
            int next = graph[curr].adj[i];
            if(!marked[next]){
                marked[next] = true;
                nextQue.push(next);
            }
        }
    }

    cout<< endl;
}

int main(){
    vector<int> graph(5);
    graph[0].adj.push_back(1);
    graph[0].adj.push_back(2);
    graph[1].adj.push_back(3);
    graph[3].adj.push_back(0);
    graph[1].adj.push_back(2);
    graph[2].adj.push_back(3);

    BFS(graph, 0);

    return 0;
}