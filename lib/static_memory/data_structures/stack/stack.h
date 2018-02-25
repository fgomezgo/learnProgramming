#ifndef STACK_H
#define STACK_H

class Stack{

  private:  
    //Indice de la pila que apunta al espacio de insercion de un nuevo elemento
    int index;   
  
  public:
    //Constructor
    Stack();
    //Push
    void push(int *a, int numero);
    //Pop
    void pop();
    //Top
    int top(int *a);
    //Size
    int size();
};

#endif
