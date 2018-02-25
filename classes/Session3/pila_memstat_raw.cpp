// Pila implementada usando memoria estatica en raw code
#include<cstdio> //lectura escritura en C
#include<iostream> //lectura escritura en C++

#define MAXN 100000

//Memoria estatica
int array[MAXN];
//indice de la pila
int index = 0;

//Pila
//funciones
void push(int numero){ 
//No pros
  array[index] = numero;
  index++;
//Pros
//  array[index++] = numero;
}

void pop(){
  index--; //index = index-1; 
}

int top(){
  return array[index-1];
}

int size(){
  return index;
}



int main(){
  
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
        push(numero);
      break;
      case 2:
        if(size() >= 1)
          pop();
        else
          printf("No te pases, estoy vacio, porque ella me abandono :-(\n");
      break;
      case 3:
        printf("%d\n",top());
      break;
      case 4:
        printf("%d\n",size());
      break;
      default:
        return 0;
      break;
    }
  }
  
  
  return 0;
}


