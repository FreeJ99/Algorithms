#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct item{
  int key,data;
  struct item* next;
}item;

item* hTable[N];

item* createItem(int key,int data){
  item* newItem = (item*)malloc(sizeof(item));
  newItem->key = key;
  newItem->data = data;
  newItem->next = NULL;
}

int hash(int x){
  return (x%N);
}

void insert(int key,int data){
  int idx=hash(key);

  item** curItem = &(hTable[idx]);

  while((*curItem)!=NULL)
    curItem = &((*curItem)->next);

  (*curItem) = createItem(key,data);
}

item* find(int key){
  int idx = hash(key);

  item* curItem = hTable[idx];
  while(curItem != NULL && curItem->key != key)
    curItem = curItem->next;

  return curItem;
}

void printTable(){
  for(int i=0;i<N;i++){
    printf("%d: ",i);
    item* curItem = hTable[i];
    while(curItem!=NULL){
      printf("(%d, %d) ",curItem->key,curItem->data);
      curItem = curItem->next;
    }

    printf("\n");
  }
}

int main(){

  insert(1, 20);
  insert(12, 70);
  insert(22, 80);
  insert(4, 25);
  insert(52, 44);
  insert(44, 32);
  insert(7, 11);
  insert(53, 78);
  insert(17, 97);

  printTable();

  int x = 18;
  item* a = find(x);
  if(a!=NULL)
    printf("found (%d,%d)\n",x,a->data);
  else
    printf("%d hasn't been found\n",x);

  return 0;
}
