#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "NodoBinario.h"
#include <iostream>

template <typename T>
class ArbolBinario {
private:
    NodoBinario<T>* raiz;
    void preOrden(NodoBinario<T>* nodo);
    void inOrden(NodoBinario<T>* nodo);
    void posOrden(NodoBinario<T>* nodo);
    void destruir(NodoBinario<T>* nodo);
    
public:
    ArbolBinario();
    ~ArbolBinario();

    NodoBinario<T>* getRaiz();
    bool esVacio();
    T datoRaiz();
    
    void insertar(T valor);
    bool buscar(T valor);
    void eliminar(T valor);

    void preOrden();
    void inOrden();
    void posOrden();
};

#endif
