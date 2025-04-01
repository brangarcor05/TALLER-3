#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoBinario.h"
#include <iostream>
#include <algorithm> // Para la función max()

template <typename T>
class ArbolBinario {
public:
    ArbolBinario();
    ~ArbolBinario();

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

private:
    NodoBinario<T>* raiz;
    
    // Métodos privados para ayuda en recorridos y operaciones
    void insertarRecursivo(NodoBinario<T>* nodo, T valor);
    NodoBinario<T>* buscarRecursivo(NodoBinario<T>* nodo, T valor);
    NodoBinario<T>* eliminarRecursivo(NodoBinario<T>* nodo, T valor);
    void preOrdenRecursivo(NodoBinario<T>* nodo);
    void inOrdenRecursivo(NodoBinario<T>* nodo);
    void posOrdenRecursivo(NodoBinario<T>* nodo);
    NodoBinario<T>* encontrarMinimo(NodoBinario<T>* nodo);
    void liberarMemoria(NodoBinario<T>* nodo);
    int calcularAltura(NodoBinario<T>* nodo);
    int calcularTamano(NodoBinario<T>* nodo);
};

// Constructor
template <typename T>
ArbolBinario<T>::ArbolBinario() : raiz(nullptr) {}

template <typename T>
ArbolBinario<T>::~ArbolBinario() {
    liberarMemoria(raiz);
}

template <typename T>
NodoBinario<T>* ArbolBinario<T>::getRaiz() {
    return raiz;
}

template <typename T>
bool ArbolBinario<T>::esVacio() {
    return raiz == nullptr;
}

template <typename T>
T ArbolBinario<T>::datoRaiz() {
    if (raiz) return raiz->dato;
    throw std::runtime_error("El árbol está vacío");
}

template <typename T>
int ArbolBinario<T>::altura() {
    return calcularAltura(raiz);
}

template <typename T>
int ArbolBinario<T>::tamano() {
    return calcularTamano(raiz);
}

template <typename T>
void ArbolBinario<T>::insertar(T valor) {
    if (!raiz) {
        raiz = new NodoBinario<T>(valor);
    } else {
        insertarRecursivo(raiz, valor);
    }
}

template <typename T>
void ArbolBinario<T>::insertarRecursivo(NodoBinario<T>* nodo, T valor) {
    if (valor < nodo->dato) {
        if (nodo->izquierdo) {
            insertarRecursivo(nodo->izquierdo, valor);
        } else {
            nodo->izquierdo = new NodoBinario<T>(valor);
        }
    } else {
        if (nodo->derecho) {
            insertarRecursivo(nodo->derecho, valor);
        } else {
            nodo->derecho = new NodoBinario<T>(valor);
        }
    }
}

template <typename T>
NodoBinario<T>* ArbolBinario<T>::buscar(T valor) {
    return buscarRecursivo(raiz, valor);
}

template <typename T>
NodoBinario<T>* ArbolBinario<T>::buscarRecursivo(NodoBinario<T>* nodo, T valor) {
    if (!nodo) return nullptr;
    if (nodo->dato == valor) return nodo;
    if (valor < nodo->dato) return buscarRecursivo(nodo->izquierdo, valor);
    return buscarRecursivo(nodo->derecho, valor);
}

template <typename T>
NodoBinario<T>* ArbolBinario<T>::buscarE(T valor) {
    NodoBinario<T>* nodo = raiz;
    while (nodo) {
        if (nodo->dato == valor) return nodo;
        if (valor < nodo->dato) nodo = nodo->izquierdo;
        else nodo = nodo->derecho;
    }
    return nullptr;
}

template <typename T>
void ArbolBinario<T>::eliminar(T valor) {
    raiz = eliminarRecursivo(raiz, valor);
}

template <typename T>
NodoBinario<T>* ArbolBinario<T>::eliminarRecursivo(NodoBinario<T>* nodo, T valor) {
    if (!nodo) return nodo;

    if (valor < nodo->dato) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, valor);
    } else if (valor > nodo->dato) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, valor);
    } else {
        if (!nodo->izquierdo) {
            NodoBinario<T>* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (!nodo->derecho) {
            NodoBinario<T>* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }

        NodoBinario<T>* temp = encontrarMinimo(nodo->derecho);
        nodo->dato = temp->dato;
        nodo->derecho = eliminarRecursivo(nodo->derecho, temp->dato);
    }
    return nodo;
}

template <typename T>
NodoBinario<T>* ArbolBinario<T>::encontrarMinimo(NodoBinario<T>* nodo) {
    NodoBinario<T>* actual = nodo;
    while (actual && actual->izquierdo) {
        actual = actual->izquierdo;
    }
    return actual;
}

template <typename T>
void ArbolBinario<T>::preOrden() {
    preOrdenRecursivo(raiz);
    std::cout << std::endl;
}

template <typename T>
void ArbolBinario<T>::preOrdenRecursivo(NodoBinario<T>* nodo) {
    if (!nodo) return;
    std::cout << nodo->dato << " ";
    preOrdenRecursivo(nodo->izquierdo);
    preOrdenRecursivo(nodo->derecho);
}

template <typename T>
void ArbolBinario<T>::inOrden() {
    inOrdenRecursivo(raiz);
    std::cout << std::endl;
}

template <typename T>
void ArbolBinario<T>::inOrdenRecursivo(NodoBinario<T>* nodo) {
    if (!nodo) return;
    inOrdenRecursivo(nodo->izquierdo);
    std::cout << nodo->dato << " ";
    inOrdenRecursivo(nodo->derecho);
}

template <typename T>
void ArbolBinario<T>::posOrden() {
    posOrdenRecursivo(raiz);
    std::cout << std::endl;
}

template <typename T>
void ArbolBinario<T>::posOrdenRecursivo(NodoBinario<T>* nodo) {
    if (!nodo) return;
    posOrdenRecursivo(nodo->izquierdo);
    posOrdenRecursivo(nodo->derecho);
    std::cout << nodo->dato << " ";
}

template <typename T>
int ArbolBinario<T>::calcularAltura(NodoBinario<T>* nodo) {
    if (!nodo) return 0;
    return 1 + std::max(calcularAltura(nodo->izquierdo), calcularAltura(nodo->derecho));
}

template <typename T>
int ArbolBinario<T>::calcularTamano(NodoBinario<T>* nodo) {
    if (!nodo) return 0;
    return 1 + calcularTamano(nodo->izquierdo) + calcularTamano(nodo->derecho);
}

template <typename T>
void ArbolBinario<T>::liberarMemoria(NodoBinario<T>* nodo) {
    if (!nodo) return;
    liberarMemoria(nodo->izquierdo);
    liberarMemoria(nodo->derecho);
    delete nodo;
}

#endif
