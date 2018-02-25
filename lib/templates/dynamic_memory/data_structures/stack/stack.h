#ifndef STACK_H
#define STACK_H

template<class T>
class Stack{

  private:  
    //Estructura NODO que guarda un valor y un apuntador al siguiente nodo de la pila
    struct Nodo{
      T val;
      Nodo* nxt;
      Nodo(){}
      Nodo(T val, Nodo* nxt) : val(val), nxt(nxt) {}
    };
    //Apuntador que contiene la referencia al tope de la pila
    Nodo* index;  
    //Elementos en la pila
    int sz;
  
  public:
    //Constructor
    Stack();
    //Push
    void push(T value);
    //Pop
    void pop();
    //Top
    T top();
    //Size
    int size();
};

#endif
