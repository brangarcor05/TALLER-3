#include "ArbolBinarioAVL.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
ArbolBinarioAVL<T>::ArbolBinarioAVL() : raiz(nullptr) {}

template <typename T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T>* nodo) {
    return nodo ? nodo->getAltura() : 0;
}

template <typename T>
int ArbolBinarioAVL<T>::factorBalance(NodoBinarioAVL<T>* nodo) {
    return altura(nodo->getHijoIzq()) - altura(nodo->getHijoDer());
}

template <typename T>
void ArbolBinarioAVL<T>::actualizarAltura(NodoBinarioAVL<T>* nodo) {
    nodo->setAltura(1 + max(altura(nodo->getHijoIzq()), altura(nodo->getHijoDer())));
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>* padre) {
    NodoBinarioAVL<T>* nuevoPadre = padre->getHijoIzq();
    padre->setHijoIzq(nuevoPadre->getHijoDer());
    nuevoPadre->setHijoDer(padre);
    actualizarAltura(padre);
    actualizarAltura(nuevoPadre);
    return nuevoPadre;
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>* padre) {
    NodoBinarioAVL<T>* nuevoPadre = padre->getHijoDer();
    padre->setHijoDer(nuevoPadre->getHijoIzq());
    nuevoPadre->setHijoIzq(padre);
    actualizarAltura(padre);
    actualizarAltura(nuevoPadre);
    return nuevoPadre;
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::balancear(NodoBinarioAVL<T>* nodo) {
    actualizarAltura(nodo);
    int balance = factorBalance(nodo);

    if (balance > 1 && factorBalance(nodo->getHijoIzq()) >= 0)
        return giroDerecha(nodo);

    if (balance < -1 && factorBalance(nodo->getHijoDer()) <= 0)
        return giroIzquierda(nodo);

    if (balance > 1 && factorBalance(nodo->getHijoIzq()) < 0) {
        nodo->setHijoIzq(giroIzquierda(nodo->getHijoIzq()));
        return giroDerecha(nodo);
    }

    if (balance < -1 && factorBalance(nodo->getHijoDer()) > 0) {
        nodo->setHijoDer(giroDerecha(nodo->getHijoDer()));
        return giroIzquierda(nodo);
    }

    return nodo;
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::insertarRecursivo(NodoBinarioAVL<T>* nodo, T valor) {
    if (!nodo) return new NodoBinarioAVL<T>(valor);

    if (valor < nodo->getDato())
        nodo->setHijoIzq(insertarRecursivo(nodo->getHijoIzq(), valor));
    else if (valor > nodo->getDato())
        nodo->setHijoDer(insertarRecursivo(nodo->getHijoDer(), valor));
    else
        return nodo;

    return balancear(nodo);
}

template <typename T>
void ArbolBinarioAVL<T>::insertar(T valor) {
    raiz = insertarRecursivo(raiz, valor);
}

// Recorrido InOrden: Izquierda - Raíz - Derecha
template <typename T>
void ArbolBinarioAVL<T>::inOrden(NodoBinarioAVL<T>* nodo) {
    if (!nodo) return;
    inOrden(nodo->getHijoIzq());
    cout << nodo->getDato() << " ";
    inOrden(nodo->getHijoDer());
}

template <typename T>
void ArbolBinarioAVL<T>::imprimirInOrden() {
    inOrden(raiz);
    cout << endl;
}

// Recorrido PreOrden: Raíz - Izquierda - Derecha
template <typename T>
void ArbolBinarioAVL<T>::preOrden(NodoBinarioAVL<T>* nodo) {
    if (!nodo) return;
    cout << nodo->getDato() << " ";
    preOrden(nodo->getHijoIzq());
    preOrden(nodo->getHijoDer());
}

template <typename T>
void ArbolBinarioAVL<T>::imprimirPreOrden() {
    preOrden(raiz);
    cout << endl;
}

// Recorrido PostOrden: Izquierda - Derecha - Raíz
template <typename T>
void ArbolBinarioAVL<T>::postOrden(NodoBinarioAVL<T>* nodo) {
    if (!nodo) return;
    postOrden(nodo->getHijoIzq());
    postOrden(nodo->getHijoDer());
    cout << nodo->getDato() << " ";
}

template <typename T>
void ArbolBinarioAVL<T>::imprimirPostOrden() {
    postOrden(raiz);
    cout << endl;
}


// Evita errores de template
template class ArbolBinarioAVL<int>;
