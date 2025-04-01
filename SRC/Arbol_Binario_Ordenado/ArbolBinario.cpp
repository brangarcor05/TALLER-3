#include "ArbolBinario.h"

template <typename T>
ArbolBinario<T>::ArbolBinario() : raiz(nullptr) {}

template <typename T>
ArbolBinario<T>::~ArbolBinario() {
    destruir(raiz);
}

template <typename T>
void ArbolBinario<T>::destruir(NodoBinario<T>* nodo) {
    if (nodo) {
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
    }
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
    throw std::runtime_error("Árbol vacío");
}

template <typename T>
void ArbolBinario<T>::insertar(T valor) {
    NodoBinario<T>* nuevo = new NodoBinario<T>(valor);
    if (!raiz) {
        raiz = nuevo;
        return;
    }

    NodoBinario<T>* actual = raiz;
    NodoBinario<T>* padre = nullptr;

    while (actual) {
        padre = actual;
        if (valor < actual->dato) {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }

    if (valor < padre->dato)
        padre->izq = nuevo;
    else
        padre->der = nuevo;
}

template <typename T>
bool ArbolBinario<T>::buscar(T valor) {
    NodoBinario<T>* actual = raiz;
    while (actual) {
        if (actual->dato == valor)
            return true;
        if (valor < actual->dato)
            actual = actual->izq;
        else
            actual = actual->der;
    }
    return false;
}

template <typename T>
void ArbolBinario<T>::preOrden(NodoBinario<T>* nodo) {
    if (nodo) {
        std::cout << nodo->dato << " ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

template <typename T>
void ArbolBinario<T>::inOrden(NodoBinario<T>* nodo) {
    if (nodo) {
        inOrden(nodo->izq);
        std::cout << nodo->dato << " ";
        inOrden(nodo->der);
    }
}

template <typename T>
void ArbolBinario<T>::posOrden(NodoBinario<T>* nodo) {
    if (nodo) {
        posOrden(nodo->izq);
        posOrden(nodo->der);
        std::cout << nodo->dato << " ";
    }
}

template <typename T>
void ArbolBinario<T>::preOrden() {
    preOrden(raiz);
    std::cout << std::endl;
}

template <typename T>
void ArbolBinario<T>::inOrden() {
    inOrden(raiz);
    std::cout << std::endl;
}

template <typename T>
void ArbolBinario<T>::posOrden() {
    posOrden(raiz);
    std::cout << std::endl;
}


