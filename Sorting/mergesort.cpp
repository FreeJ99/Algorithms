#include<stdio.h>
#include<vector>

using namespace std;

void merge(vector<int>& a, int l1, int n1, int l2, int n2){
    vector<int> c(n1 + n2);
    int i = 0, j = 0;
    while(i<n1 || j<n2){
        if(j==n2 || (i<n1 && a[l1+i]<a[l2+j])){
            c[i+j] = a[l1+i];
            i++;
        }
        else{
            c[i+j] = a[l2+j];
            j++;
        }
    }
    for(int i=l1;i<l2+n2;i++)
        a[i] = c[i-l1];
}
void _mergeSort(vector<int> &a, int l, int r){
    if(l == r)
        return;
    int m = (l+r)/2;
    _mergeSort(a, l, m);
    _mergeSort(a, m+1, r);
    merge(a, l, m-l+1, m+1, r-m);
}

void mergeSort(vector<int> &a){
    _mergeSort(a, 0, a.size()-1);
}

int main(){
    vector<int> a{2, 4, 1, 5, 3, 2, 6, 0, 5, 5};
    mergeSort(a);
    for(int i=0;i<a.size();i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}