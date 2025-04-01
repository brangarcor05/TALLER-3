#include "Arbol.h"

template <typename T>
Arbol<T>::Arbol() : raiz(nullptr) {}

template <typename T>
Arbol<T>::Arbol(T val) {
    raiz = new Nodo<T>(val);
}

template <typename T>
bool Arbol<T>::esVacio() {
    return raiz == nullptr;
}

template <typename T>
Nodo<T>* Arbol<T>::obtenerRaiz() {
    return raiz;
}

template <typename T>
void Arbol<T>::fijarRaiz(Nodo<T>* nraiz) {
    raiz = nraiz;
}

template <typename T>
bool Arbol<T>::insertarNodo(T padre, T n) {
    Nodo<T>* nodoPadre = buscarNodo(padre);
    if (nodoPadre) {
        nodoPadre->adicionarDesc(n);
        return true;
    }
    return false;
}

template <typename T>
bool Arbol<T>::eliminarNodo(T n) {
    if (raiz->obtenerDato() == n) {
        delete raiz;
        raiz = nullptr;
        return true;
    }
    return raiz->eliminarDesc(n);
}

template <typename T>
Nodo<T>* Arbol<T>::buscarNodo(T val) {
    if (raiz->obtenerDato() == val) {
        return raiz;
    }
    return raiz->buscarDesc(val);
}

template <typename T>
int Arbol<T>::altura() {
    return raiz->altura();
}

template <typename T>
int Arbol<T>::tamano() {
    return raiz->tamano();
}

template <typename T>
void Arbol<T>::nivelOrden() {
    raiz->nivelOrden();
}

// Explicitar la instanciación de plantillas para tipos que se usen
template class Arbol<int>;
template class Arbol<float>;
