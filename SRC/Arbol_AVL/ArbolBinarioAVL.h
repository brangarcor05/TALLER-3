#ifndef ARBOL_BINARIO_AVL_H
#define ARBOL_BINARIO_AVL_H

#include "NodoBinarioAVL.h"

template <typename T>
class ArbolBinarioAVL {
private:
    NodoBinarioAVL<T>* raiz;

    int altura(NodoBinarioAVL<T>* nodo);
    int factorBalance(NodoBinarioAVL<T>* nodo);
    void actualizarAltura(NodoBinarioAVL<T>* nodo);
    
    NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>* padre);
    NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>* padre);
    NodoBinarioAVL<T>* balancear(NodoBinarioAVL<T>* nodo);
    
    NodoBinarioAVL<T>* insertarRecursivo(NodoBinarioAVL<T>* nodo, T valor);
    NodoBinarioAVL<T>* eliminarRecursivo(NodoBinarioAVL<T>* nodo, T valor);
    NodoBinarioAVL<T>* encontrarMinimo(NodoBinarioAVL<T>* nodo);
    
    void inOrden(NodoBinarioAVL<T>* nodo);
    void preOrden(NodoBinarioAVL<T>* nodo);
    void postOrden(NodoBinarioAVL<T>* nodo);

public:
    ArbolBinarioAVL();
    
    void insertar(T valor);
    void eliminar(T valor);
    void imprimirInOrden();
    void imprimirPreOrden();
    void imprimirPostOrden();
};

#include "ArbolBinarioAVL.cpp"

#endif
