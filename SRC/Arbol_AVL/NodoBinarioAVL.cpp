#include "NodoBinarioAVL.h"

template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL() : hijoIzq(nullptr), hijoDer(nullptr) {}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL() = default;

template <class T>
T& NodoBinarioAVL<T>::getDato() {
    return dato;
}

template <class T>
void NodoBinarioAVL<T>::setDato(const T& val) {
    dato = val;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() {
    return hijoIzq;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() {
    return hijoDer;
}

template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq) {
    hijoIzq = izq;
}

template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der) {
    hijoDer = der;
}

template <class T>
int NodoBinarioAVL<T>::getAltura() {
    return this->altura;
}

template <class T>
void NodoBinarioAVL<T>::setAltura(int h) {
    this->altura = h;
}
