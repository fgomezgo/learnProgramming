// Pila implementada usando memoria estatica en raw code
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++
#include "../../lib/static_memory/data_structures/stack/stack.cpp"

#define MAXN 100000

//Memoria estatica
int array[MAXN];

int main(){
  
  Stack pila;
  
  printf("Esto es una pila\n");
  //push  1
  //pop   2
  //top   3
  //size  4
  //end   5
  while(1){
    printf("Dime la operacion\n");
    int tmp;
    scanf("%d",&tmp);
    switch(tmp){
      case 1:
        int numero;
        scanf("%d",&numero);
        pila.push(array,numero);
      break;
      case 2:
        if(pila.size() >= 1)
          pila.pop();
        else
          printf("No te pases, estoy vacio, porque ella me abandono :-(\n");
      break;
      case 3:
        printf("%d\n",pila.top(array));
      break;
      case 4:
        printf("%d\n",pila.size());
      break;
      default:
        return 0;
      break;
    }
  }
  
  
  return 0;
}


