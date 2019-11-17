#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Node{
    int data;
    vector<int> adj;
};

void DFS(const vector<Node>& graph, vector<bool>& marked, int curr){
    marked[curr] = true;
    cout<< graph[curr].data << " ";
    
    for(int i=0;i<graph[curr].adj.size();i++){
        int next = graph[curr].adj[i];
        if(!marked[next])
            DFS(graph, marked, next);
    }
}

void DFS(const vector<Node>& graph, int start){
    vector<bool> marked(graph.size());
    DFS(graph, marked, start);
    cout<< endl;
}

void nonRecDFS(const vector<Node>& graph, int start){
    stack<int> nodeStack;
    vector<bool> visited(graph.size());
    nodeStack.push(start);

    while(!nodeStack.empty()){
        int curr = nodeStack.top();
        nodeStack.pop();
        if(visited[curr])
            continue;
        cout<< graph[curr].data << " ";
        visited[curr] = true;
        for(int idx:graph[curr].adj)
            if(!visited[idx]){
                nodeStack.push(idx);
            }
    }
}

int main(){
    vector<Node> graph(5);
    
    for(int i=0;i<graph.size();i++)
        graph[i].data = i;

    graph[0].adj.push_back(1);
    graph[0].adj.push_back(2);
    graph[1].adj.push_back(3);
    graph[3].adj.push_back(0);
    graph[1].adj.push_back(2);
    graph[2].adj.push_back(3);

    DFS(graph, 0);
    nonRecDFS(graph, 0);

    return 0;
}