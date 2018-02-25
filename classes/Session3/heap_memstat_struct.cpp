// Heap implementado usando memoria estatica con programacion estructurada
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
    
    while(tmp != 1 && a[tmp/2] < a[tmp]){
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
    while( !(tmp*2 >= index) ){                               //Mientras tmp NO sea una hoja (si el hijo izq no existe, el derecho tampoco)
      if(tmp*2+1 < index){                                    //Si tmp tiene a sus 2 hijos (si el hijo der existe, el izquierdo tambien)
        if(a[tmp] > a[tmp*2] && a[tmp] > a[tmp*2+1]) break;   //Si tmp es mayor a sus 2 hijos, se detiene
        if(a[tmp*2] > a[tmp*2+1])
          tmp_hijo = tmp*2;
        else
          tmp_hijo = tmp*2+1;
      } else {                                                //Si tmp tiene unicamente al hijo izquierdo
        if(a[tmp] > a[tmp*2]) break;                          //Si tmp es mayor que su hijo izq, se detiene
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
int array[MAXN];

int main(){
  
  printf("Esto es una heap\n");
  //push  1
  //pop   2
  //top   3
  //size  4
  //end   5
  
  //Declaracion de la estructura
  Heap heap; //AQUI se llama el constructor
  
  
  while(1){
    printf("Dime la operacion\n");
    int tmp;
    scanf("%d",&tmp);
    switch(tmp){
      case 1:
        int numero;
        scanf("%d",&numero);
        heap.push(array,numero);
      break;
      case 2:
        if(heap.size(array) >= 1)
          heap.pop(array);
        else
          printf("No te pases, estoy vacio, porque ella me abandono :-(\n");
      break;
      case 3:
        printf("%d\n",heap.top(array));
      break;
      case 4:
        printf("%d\n",heap.size(array));
      break;
      default:
        return 0;
      break;
    }
  }
  
  
  return 0;
}


