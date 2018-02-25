// Heapsort: Ordenamiento utilizando un heap
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++
#include "../lib/data_structures/static_memory/heap/heap.cpp"  //AQUI se manda llamar la clase heap.cpp

#define MAXN 100000

//Memoria estatica
int tree[MAXN];
int arr[MAXN];


int main(){
  
  printf("Esto es una heapsort\n");
  Heap heap;  //AQUI se declara el objeto proveniente de la libreria heap.cpp
  
  int n;
  printf("Cantidad de numeros:\n");
  scanf("%d",&n);
  printf("Dame los numeros:\n");
  for(int i = 0; i < n; ++i){
    scanf("%d",&arr[i]);
  }
  for(int i = 0; i < n; ++i){
    heap.push(tree,arr[i]);
  }
  printf("El arreglo ordenado es:\n");
  for(int i = 0; i < n; ++i){
    printf("%d ",heap.top(tree));
    heap.pop(tree);
  } printf("\n");
  
  
  return 0;
}


