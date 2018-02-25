#include "stack.h"

//Constructor
Stack::Stack(){
  index = 0;
}
//Push
void Stack::push(int *a, int numero){ 
  a[index++] = numero;
}
//Pop
void Stack::pop(){
  index--; 
}
//Top
int Stack::top(int *a){
  return a[index-1];
}
//Size
int Stack::size(){
  return index;
}
