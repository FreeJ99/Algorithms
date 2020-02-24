#define MAXN 32
#include<iostream>

int numComponents;

struct Node{
    int parent;
    int rank;
};

Node DSU[MAXN];
void MakeSet(int x){
    DSU[x].parent = x;
    DSU[x].rank = 1;
}

int find(int x){
    if(DSU[x].parent == x)
        return x;
    else{
        DSU[x].parent = find(DSU[x].parent);
        return DSU[x].parent;
    }
}

void Union(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py)
        return;
    
    numComponents--;
    if(DSU[px].rank >= DSU[py].rank){
        DSU[py].parent = px;
    }
    else{
        DSU[px].parent = py;
    }
}

int main()
{
    numComponents = 4;
   
    MakeSet(0);
    MakeSet(1);
    MakeSet(2);
    MakeSet(3);
    
    Union(0, 1);
    Union(1, 0);
    Union(1, 2);
    Union(0, 2);
    
    printf("%d\n",numComponents);
    for(int i=0;i<4;i++)
        printf("%d ", find(i));

    return 0;
}