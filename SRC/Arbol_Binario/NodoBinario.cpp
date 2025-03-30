#include "NodoBinario.h"

// Constructor con dato
template <typename T>
NodoBinario<T>::NodoBinario(T valor) : dato(valor), izq(nullptr), der(nullptr) {}

// Constructor vacío
template <typename T>
NodoBinario<T>::NodoBinario() : izq(nullptr), der(nullptr) {}

// Getters
template <typename T>
T NodoBinario<T>::obtenerDato() {
    return dato;
}

template <typename T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    return izq;
}

template <typename T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
    return der;
}

// Setters
template <typename T>
void NodoBinario<T>::fijarDato(T val) {
    dato = val;
}

template <typename T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq) {
    this->izq = izq;
}

template <typename T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der) {
    this->der = der;
}
