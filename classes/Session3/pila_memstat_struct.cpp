// Pila implementada usando memoria estatica con programacion estructurada 
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++

#define MAXN 100000

//Declaracion de la estructura
struct Pila{
  //--Variables--//
  int index;   //indice de la pila
  
  //--Constructor--//
  Pila(){
    index = 0;
  }
  //--Metodos o miembros--//
  void push(int *a, int numero){ 
    a[index++] = numero;
  }
  void pop(int *a){
    index--; //index = index-1; 
  }
  int top(int *a){
    return a[index-1];
  }
  int size(int *a){
    return index;
  }
};


//Memoria estatica
int array[MAXN];

int main(){
  
  printf("Esto es una pila\n");
  //push  1
  //pop   2
  //top   3
  //size  4
  //end   5
  
  //Declaracion de la estructura
  Pila pila; //AQUI se llama el constructor
  
  
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
        if(pila.size(array) >= 1)
          pila.pop(array);
        else
          printf("No te pases, estoy vacio, porque ella me abandono :-(\n");
      break;
      case 3:
        printf("%d\n",pila.top(array));
      break;
      case 4:
        printf("%d\n",pila.size(array));
      break;
      default:
        return 0;
      break;
    }
  }
  
  
  return 0;
}


