#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

struct Node{
    bool leaf;
    unordered_map<char, Node*> chd;
    Node(): leaf(false){}
};

void insert(Node* root, string s, int idx){
    if(idx == s.size()){
        root->leaf = true;
    }
    else{
        if(root->chd[s[idx]] == NULL)
            root->chd[s[idx]] = new Node();
        insert(root->chd[s[idx]], s, idx+1);
    }
}

bool find(Node* root, string s, int idx){
    if(idx == s.size()){
        return root->leaf;
    }
    if(root->chd[s[idx]] == NULL)
        return false;
    return find(root->chd[s[idx]], s, idx+1);
}

int main(){
    Node* trie = new Node();
    insert(trie, "abc", 0);
    insert(trie, "abd", 0);
    insert(trie, "def", 0);
    insert(trie, "dag", 0);

    cout<< find(trie, "abc", 0) << endl;
    cout<< find(trie, "abd", 0) << endl;
    cout<< find(trie, "def", 0) << endl;
    cout<< find(trie, "dag", 0) << endl;
    cout<< find(trie, "abv", 0) << endl;
    cout<< find(trie, "art", 0) << endl;
    return 0;
}