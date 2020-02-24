#include<iostream>
#include<limits>

#define MAXN 1024
#define MAXST 1024*2
#define MID ((l+r)/2)

using namespace std;

int n;
int niz[MAXN];
int segTree[MAXN];

void InitTree(int idx, int l, int r){
    if(l == r){
        segTree[idx] = niz[l];
        return;
    }

    InitTree(2*idx, l, MID);
    InitTree(2*idx+1, MID+1, r);

    segTree[idx] = min(segTree[2*idx], segTree[2*idx + 1]);
}

void Update(int idx, int l, int r, int nizIdx, int val){
    if(nizIdx < l || nizIdx > r)
        return;
    if(l == r){
        segTree[idx] = val;
        return;
    }

    Update(2*idx, l, MID, nizIdx, val);
    Update(2*idx+1, MID+1, r, nizIdx, val);

    segTree[idx] = min(segTree[2*idx], segTree[2*idx+1]);
}

int Query(int idx, int l, int r, int qL, int qR){
    if(l >= qL && r <= qR)
        return segTree[idx];
    if(l >= qR || r <= qL)
        return numeric_limits<int>::max();
    
    return min(Query(2*idx, l, MID, qL, qR), Query(2*idx+1, MID+1, r, qL, qR));
}

int main()
{
    n = 6;
    niz[1] = 4;
    niz[2] = 2;
    niz[3] = 5;
    niz[4] = 1;
    niz[5] = 6;
    niz[6] = 3;
    
    InitTree(1, 1, n);
    printf("%d\n",Query(1, 1, n, 1, 3));
    printf("%d\n",Query(1, 1, n, 4, 6));

    Update(1, 1, n, 4, 10);
    Update(1, 1, n, 5, 0);
    printf("%d\n",Query(1, 1, n, 4, 6));

    return 0;
}