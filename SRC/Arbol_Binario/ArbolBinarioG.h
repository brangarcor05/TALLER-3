#ifndef ARBOLBINARIOG_H
#define ARBOLBINARIOG_H

#include "NodoBinario.h"

template <typename T>
class ArbolBinarioG {
private:
    NodoBinario<T>* raiz;

    // Métodos auxiliares para recursión
    void preOrden(NodoBinario<T>* nodo);
    void inOrden(NodoBinario<T>* nodo);
    void posOrden(NodoBinario<T>* nodo);
    int altura(NodoBinario<T>* nodo);
    int tamano(NodoBinario<T>* nodo);
    NodoBinario<T>* insertar(NodoBinario<T>* nodo, T valor);
    NodoBinario<T>* eliminar(NodoBinario<T>* nodo, T valor);
    NodoBinario<T>* buscarMin(NodoBinario<T>* nodo);

public:
    // Constructor
    ArbolBinarioG();

    // Métodos principales
    NodoBinario<T>* getRaiz();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    void insertar(T valor);
    void eliminar(T valor);
    NodoBinario<T>* buscar(T valor);
    NodoBinario<T>* buscarE(T valor);
    
    // Recorridos
    void preOrden();
    void inOrden();
    void posOrden();
};

#include "ArbolBinarioG.cpp" // Implementación

#endif
