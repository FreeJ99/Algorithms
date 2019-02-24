#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct item{
  int key,data;
  int occupied,deleted;
}item;

item hTable[N];

item* createItem(int key,int data){

}

int hash(int x){
  return (x%N);
}

void insert(int key,int data){
  int idx = hash(key);
  int i=0;
  while(i<N && hTable[(idx+i*i)%N].occupied == 1)
    i++;

  if(i==N)
      return;

  hTable[(idx+i*i)%N].key = key;
  hTable[(idx+i*i)%N].data = data;
  hTable[(idx+i*i)%N].occupied = 1;
}

int find(int key){
  int idx = hash(key);
  int i = 0;
  while(i<N && hTable[(idx+i*i)%N].key!=key && (hTable[(idx+i*i)%N].occupied==1 || hTable[(idx+i*i)%N].deleted==1))
    i++;

  if(i==N || hTable[(idx+i*i)%N].occupied==0)
    return -1;

  return (idx+i*i)%N;
}

void delete(int key){
  int idx = hash(key);
  int i = 0;
  while(i<N && hTable[(idx+i*i)%N].key!=key && (hTable[(idx+i*i)%N].occupied==1 || hTable[(idx+i*i)%N].deleted==1))
    i++;

  if(i==N || hTable[(idx+i*i)%N].occupied==0)
    return;

  hTable[(idx+i*i)%N].occupied=0;
  hTable[(idx+i*i)%N].deleted=1;
}

void printTable(){
  int i;
  for(i=0;i<N;i++){
    printf("%d: (%d %d)\n",i,hTable[i].key,hTable[i].data);
  }
  printf("\n");
}

int main(){

  insert(1, 20);
  printTable();
  insert(1, 70);
  printTable();
  insert(22, 80);
  printTable();
  insert(4, 25);
  printTable();
  insert(61, 44);

  printTable();

  int x = 61;
  int a = find(x);
  if(a!=-1)
    printf("found (%d,%d)\n",x,hTable[a].data);
  else
    printf("%d hasn't been found\n",x);

  return 0;
}
