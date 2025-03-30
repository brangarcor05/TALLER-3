#include "NodoBinarioAVL.h"

// Constructor que inicializa el nodo con un valor y establece sus hijos y altura
template <typename T>
NodoBinarioAVL<T>::NodoBinarioAVL(T valor) 
    : dato(valor), hijoIzq(nullptr), hijoDer(nullptr), altura(1) {}

// Obtiene el dato almacenado en el nodo
template <typename T>
T NodoBinarioAVL<T>::getDato() { return dato; }

// Fija el dato del nodo
template <typename T>
void NodoBinarioAVL<T>::setDato(T valor) { dato = valor; }

// Obtiene el hijo izquierdo del nodo
template <typename T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() { return hijoIzq; }

// Fija el hijo izquierdo del nodo
template <typename T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL* nodo) { hijoIzq = nodo; }

// Obtiene el hijo derecho del nodo
template <typename T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() { return hijoDer; }

// Fija el hijo derecho del nodo
template <typename T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL* nodo) { hijoDer = nodo; }

// Obtiene la altura del nodo
template <typename T>
int NodoBinarioAVL<T>::getAltura() { return altura; }

// Fija la altura del nodo
template <typename T>
void NodoBinarioAVL<T>::setAltura(int h) { altura = h; }

// Para evitar problemas con plantillas, es necesario incluir la implementación en el header o en un .cpp
template class NodoBinarioAVL<int>; // Puedes agregar más tipos según necesites
