#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

template <class T>
class Arbol {
public:
    Nodo<T>* raiz;
    Arbol();
    Arbol(T val);
    bool esVacio();
    Nodo<T>* obtenerRaiz();
    void fijarRaiz(Nodo<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    Nodo<T>* buscarNodo(T val);
    int altura();
    int tamano();
    void nivelOrden();
};

#include "Arbol.cpp"
#endif
