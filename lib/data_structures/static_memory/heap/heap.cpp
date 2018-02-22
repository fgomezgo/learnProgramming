#include <algorithm>
#include "heap.h"

//Constructor
Heap::Heap(){
  index = 1;
}
//Push
void Heap::push(int *a, int numero){
  a[index] = numero; //El numero se inserta en a
  int tmp = index++; //Index apunta al siguiente nodo vacio
  
  while(tmp != 1 && a[tmp/2] < a[tmp]){   //Mientras tmp no sea la raiz y su valor en a sea mayor que el de su padre
    std::swap(a[tmp/2],a[tmp]);           //Se intercambia el valor de tmp con su padre
    tmp /= 2;                             //Sube al padre
  }
}
//Pop
void Heap::pop(int *a){
  a[1] = a[index-1];                                        //El valor en el ultimo nodo insertado remplaza a la raiz
  index--;                                                  //El arbol se reduce un nodo
  int tmp = 1, tmp_hijo;
  
  while( !(tmp*2 >= index) ){                               //Mientras tmp NO sea una hoja (si el hijo izq no existe, el derecho tampoco)
    if(tmp*2+1 < index){                                    //Si tmp tiene a sus 2 hijos (si el hijo der existe, el izquierdo tambien)
      if(a[tmp] > a[tmp*2] && a[tmp] > a[tmp*2+1]) break;   //Si tmp es mayor a sus 2 hijos, se detiene
      if(a[tmp*2] > a[tmp*2+1])                             //tmp_hijo toma el valor del hijo que tenga el mayor valor
        tmp_hijo = tmp*2;
      else
        tmp_hijo = tmp*2+1;
    } else {                                                //Si tmp tiene unicamente al hijo izquierdo
      if(a[tmp] > a[tmp*2]) break;                          //Si tmp es mayor que su hijo izq, se detiene
      tmp_hijo = tmp*2;
    }
    std::swap(a[tmp],a[tmp_hijo]);                          //Se intercambia el valor de tmp con su hijo
    tmp = tmp_hijo;                                         //Baja al hijo
  }
}
//Top
int Heap::top(int *a){
  return a[1];
}
//Size
int Heap::size(){
  return index-1;
}
