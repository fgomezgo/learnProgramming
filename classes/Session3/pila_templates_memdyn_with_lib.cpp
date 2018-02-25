// Pila implementada usando memoria dinamica en un template
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++
#include "../../lib/templates/dynamic_memory/data_structures/stack/stack.cpp"

struct Par{
  int fst, snd;
  Par(){}
};

int main(){
    
  //Memoria dinamica con template  
  Stack <Par> pila;
  
  printf("Esto es una pila\n");
  //push  1
  //pop   2
  //top   3
  //size  4
  //end   5
  Par a;
  while(1){
    printf("Dime la operacion\n");
    int tmp;
    scanf("%d",&tmp);
    switch(tmp){
      case 1:
        scanf("%d %d",&a.fst,&a.snd);
        pila.push(a);
      break;
      case 2:
        if(pila.size() >= 1)
          pila.pop();
        else
          printf("No te pases, estoy vacio, porque ella me abandono :-(\n");
      break;
      case 3:
        a = pila.top();
        printf("%d %d\n",a.fst,a.snd);
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


