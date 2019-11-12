#include<stdio.h>
#include<vector>

using namespace std;

void _quickSort(vector<int> &a, int i, int j){
    int l = i, r = j;
    if(l >= r)
        return;
    int pivot = a[r];
    while(l<r){
        while(a[l] < pivot)
            l++;
        while(l<r && a[r] >= pivot)
            r--;
        swap(a[l], a[r]);
    }
    swap(a[l], a[j]);

    _quickSort(a, i, l-1);
    _quickSort(a, l+1, j);
}
void quickSort(vector<int>& a){
   _quickSort(a, 0, a.size()-1);
}

int main(){
    vector<int> a{2, 4, 1, 5, 3, 2, 6, 0, 5, 5};
    quickSort(a);
    for(int i=0;i<a.size();i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}