// Cola implementada usando memoria estatica con codigo estructurado
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++

#define MAXN 100000

//Declaracion de la estructura
struct Cola{
  //--Variables--//
  int head; //Apunta al primero en salir
  int tail; //Apunta al siguiente en entrar
  
  //--Constructor--//
  Cola(){
    head = 0;
    tail = 0;
  }
  //--Metodos o miembros--//
  void push(int *a, int numero){ 
    a[tail] = numero;
    if(tail == MAXN)
      tail = 0;
    else
      tail++;
    //tail = (tail+1)%MAXN;
  }
  void pop(int *a){
    if(head == MAXN)
      head = 0;
    else
      head++;
    //head = (head+1)%MAXN;
  }
  int top(int *a){
    return a[head];
  }
  int size(int *a){
    
    if(tail >= head){
      return tail-head;
    }
    else{
      return MAXN-(head-tail);
    }  
    // return ((tail-head)+MAXN)%MAXN;
    
    return 0;
  }
};


//Memoria estatica
int array[MAXN];

int main(){
  
  printf("Esto es una cola\n");
  //push  1
  //pop   2
  //top   3
  //size  4
  //end   5
  
  //Declaracion de la estructura
  Cola cola; //AQUI se llama el constructor
  
  
  while(1){
    printf("Dime la operacion\n");
    int tmp;
    scanf("%d",&tmp);
    switch(tmp){
      case 1:
        int numero;
        scanf("%d",&numero);
        cola.push(array,numero);
      break;
      case 2:
        if(cola.size(array) >= 1)
          cola.pop(array);
        else
          printf("No te pases, estoy vacio, porque ella me abandono :-(\n");
      break;
      case 3:
        printf("%d\n",cola.top(array));
      break;
      case 4:
        printf("%d\n",cola.size(array));
      break;
      default:
        return 0;
      break;
    }
  }
  
  
  return 0;
}


