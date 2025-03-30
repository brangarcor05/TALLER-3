#include "ArbolBinarioAVL.h"
#include <iostream>
#include <queue>
using namespace std;

// Constructor por defecto, inicializa la raíz como puntero nulo
template <typename T>
ArbolBinarioAVL<T>::ArbolBinarioAVL() : raiz(nullptr) {}

// Calcula la altura de un nodo
template <typename T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T>* nodo) {
    return nodo ? nodo->getAltura() : 0;
}

// Calcula el factor de balance de un nodo
template <typename T>
int ArbolBinarioAVL<T>::factorBalance(NodoBinarioAVL<T>* nodo) {
    return altura(nodo->getHijoIzq()) - altura(nodo->getHijoDer());
}

// Actualiza la altura de un nodo
template <typename T>
void ArbolBinarioAVL<T>::actualizarAltura(NodoBinarioAVL<T>* nodo) {
    nodo->setAltura(1 + max(altura(nodo->getHijoIzq()), altura(nodo->getHijoDer())));
}

// Realiza un giro a la derecha en el nodo dado
template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>* padre) {
    NodoBinarioAVL<T>* nuevoPadre = padre->getHijoIzq();
    padre->setHijoIzq(nuevoPadre->getHijoDer());
    nuevoPadre->setHijoDer(padre);
    actualizarAltura(padre);
    actualizarAltura(nuevoPadre);
    return nuevoPadre;
}

// Realiza un giro a la izquierda en el nodo dado
template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>* padre) {
    NodoBinarioAVL<T>* nuevoPadre = padre->getHijoDer();
    padre->setHijoDer(nuevoPadre->getHijoIzq());
    nuevoPadre->setHijoIzq(padre);
    actualizarAltura(padre);
    actualizarAltura(nuevoPadre);
    return nuevoPadre;
}

// Balancea el nodo dado
template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::balancear(NodoBinarioAVL<T>* nodo) {
    actualizarAltura(nodo);
    int balance = factorBalance(nodo);

    // Rotaciones para balancear el árbol
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

// Inserta un valor de manera recursiva en el árbol
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

// Inserta un valor en el árbol
template <typename T>
void ArbolBinarioAVL<T>::insertar(T valor) {
    raiz ▋
