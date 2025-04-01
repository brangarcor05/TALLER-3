#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H
template <typename T>
class NodoBinario {
private:
    T dato;
    NodoBinario* izq;
    NodoBinario* der;

public:
    NodoBinario(T valor) : dato(valor), izq(nullptr), der(nullptr) {}
    
    T obtenerDato() { return dato; }
    void fijarDato(T val) { dato = val; }

    NodoBinario* obtenerHijoIzq() { return izq; }
    NodoBinario* obtenerHijoDer() { return der; }

    void fijarHijoIzq(NodoBinario* izq) { this->izq = izq; }
    void fijarHijoDer(NodoBinario* der) { this->der = der; }

    friend class ArbolBinario<T>;
};

#endif
