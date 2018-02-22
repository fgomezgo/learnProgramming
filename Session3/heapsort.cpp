// Heapsort: Ordenamiento utilizando un heap
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++
#include <algorithm> 

#define MAXN 100000

//Declaracion de la estructura
struct Heap{
  //--Variables--//
  //int root;   
  int index; //Apuntar a la siguinte hoja vacia que mantenga el arbol completo (no degenerado)
  
  //--Constructor--//
  Heap(){
    index = 1;
  }
  //--Metodos o miembros--//
  void push(int *a, int numero){ 
    a[index] = numero; //Lo insertamos
    int tmp = index++;
    
    while(tmp != 1 && a[tmp/2] > a[tmp]){
      int aux = a[tmp/2];
      a[tmp/2] = a[tmp];
      a[tmp] = aux;
      //std::swap(a[tmp/2],a[tmp]);
      tmp /= 2;  
    }

  }
  void pop(int *a){
    a[1] = a[index-1];
    index--;
    int tmp = 1, tmp_hijo;
    while( !(tmp*2 >= index && tmp*2+1 >= index) ){
      //Tengo a mis 2 hijos
      if(tmp*2 < index && tmp*2+1 < index){
        if(a[tmp] < a[tmp*2] && a[tmp] < a[tmp*2+1]) 
          break;
        if(a[tmp*2] < a[tmp*2+1])
          tmp_hijo = tmp*2;
        else
          tmp_hijo = tmp*2+1;
      } else {
        if(a[tmp] < a[tmp*2])
          break;
        tmp_hijo = tmp*2;
      }
      std::swap(a[tmp],a[tmp_hijo]);
      tmp = tmp_hijo;
    
    }
  }
  int top(int *a){
    return a[1];
  }
  int size(int *a){
    return index-1;
  }
};


//Memoria estatica
int tree[MAXN];
int arr[MAXN];


int main(){
  
  printf("Esto es una heap\n");

  
  //Declaracion de la estructura
  Heap heap; //AQUI se llama el constructor
  
  
  int n;
  printf("Dame cuantos me vas a meter:\n");
  scanf("%d",&n);
  printf("Dame los numeritos:\n");
  for(int i = 0; i < n; ++i){
    scanf("%d",&arr[i]);
  }
  for(int i = 0; i < n; ++i){
    heap.push(tree,arr[i]);
  }
  for(int i = 0; i < n; ++i){
    printf("%d ",heap.top(tree));
    heap.pop(tree);
  } printf("\n");
  
  
  return 0;
}


