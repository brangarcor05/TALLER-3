#include "NodoBinarioAVL.h"

template <typename T>
NodoBinarioAVL<T>::NodoBinarioAVL(T valor) 
    : dato(valor), hijoIzq(nullptr), hijoDer(nullptr), altura(1) {}

template <typename T>
T NodoBinarioAVL<T>::getDato() { return dato; }

template <typename T>
void NodoBinarioAVL<T>::setDato(T valor) { dato = valor; }

template <typename T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() { return hijoIzq; }

template <typename T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL* nodo) { hijoIzq = nodo; }

template <typename T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() { return hijoDer; }

template <typename T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL* nodo) { hijoDer = nodo; }

template <typename T>
int NodoBinarioAVL<T>::getAltura() { return altura; }

template <typename T>
void NodoBinarioAVL<T>::setAltura(int h) { altura = h; }

// Para evitar problemas con plantillas, es necesario incluir la implementación en el header o en un .cpp
template class NodoBinarioAVL<int>; // Puedes agregar más tipos según necesites
