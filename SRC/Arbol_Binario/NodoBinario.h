#ifndef NODOBINARIO_H
#define NODOBINARIO_H

template <typename T>
class NodoBinario {
private:
    T dato;
    NodoBinario<T>* izq;
    NodoBinario<T>* der;

public:
    // Constructores
    NodoBinario(T valor);
    NodoBinario();

    // Getters y Setters
    T obtenerDato();
    void fijarDato(T val);
    
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    
    void fijarHijoIzq(NodoBinario<T>* izq);
    void fijarHijoDer(NodoBinario<T>* der);
};

#include "NodoBinario.cpp" // Implementación

#endif
