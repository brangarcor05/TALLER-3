#include "Arbol.h"


template <class T>
Arbol<T>::Arbol() : raiz(nullptr) {}

template <class T>
Arbol<T>::Arbol(T val) {
    raiz = new Nodo<T>(val);
}

template <class T>
bool Arbol<T>::esVacio() {
    return raiz == nullptr;
}

template <class T>
Nodo<T>* Arbol<T>::obtenerRaiz() {
    return raiz;
}

template <class T>
void Arbol<T>::fijarRaiz(Nodo<T>* nraiz) {
    raiz = nraiz;
}

template <class T>
bool Arbol<T>::insertarNodo(T padre, T n) {
    if (!raiz) return false;
    queue<Nodo<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        if (actual->dato == padre) {
            actual->adicionarDesc(n);
            return true;
        }
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    return false;
}

template <class T>
bool Arbol<T>::eliminarNodo(T n) {
    if (!raiz) return false;
    if (raiz->dato == n) {
        delete raiz;
        raiz = nullptr;
        return true;
    }
    queue<Nodo<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        if (actual->eliminarDesc(n)) return true;
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    return false;
}

template <class T>
Nodo<T>* Arbol<T>::buscarNodo(T val) {
    if (!raiz) return nullptr;
    queue<Nodo<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        if (actual->dato == val) return actual;
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    return nullptr;
}

template <class T>
int Arbol<T>::altura() {
    return raiz ? raiz->altura() : -1;
}

template <class T>
int Arbol<T>::tamano() {
    return raiz ? raiz->tamano() : 0;
}

template <class T>
void Arbol<T>::nivelOrden() {
    if (raiz) raiz->nivelOrden();
}
