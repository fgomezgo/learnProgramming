#ifndef HEAP_H
#define HEAP_H

class Heap{

  private: 
      //Indice que apunta a la siguinte hoja vacia que mantenga el arbol completo (no degenerado)
      int index;         
  
  public:
      //Constructor
      Heap();
      //Push
      void push(int *a, int numero);
      //Pop
      void pop(int *a);
      //Top: Return MAX_ELEM
      int top(int *a);
      //Size
      int size();
};

#endif
