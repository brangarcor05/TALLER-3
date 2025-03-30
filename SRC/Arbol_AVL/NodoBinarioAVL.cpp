#include "NodoBinarioAVL.h"

// Implementación del constructor por defecto
template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL() : hijoIzq(nullptr), hijoDer(nullptr) {}

// Implementación del destructor por defecto
template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL() = default;

// Implementación del método getDato
template <class T>
T& NodoBinarioAVL<T>::getDato() {
    return dato;
}

// Implementación del método setDato
template <class T>
void NodoBinarioAVL<T>::setDato(const T& val) {
    dato = val;
}

// Implementación del método getHijoIzq
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() {
    return hijoIzq;
}

// Implementación del método getHijoDer
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() {
    return hijoDer;
}

// Implementación del método setHijoIzq
template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq) {
    hijoIzq = izq;
}

// Implementación del método setHijoDer
template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der) {
    hijoDer = der;
}

// Implementación del método getAltura
template <class T>
int NodoBinarioAVL<T>::getAltura() {
    return this->altura;
}

// Implementación del método setAltura
template <class T>
void NodoBinarioAVL<T>::setAltura(int h) {
    this->altura = h;
}
