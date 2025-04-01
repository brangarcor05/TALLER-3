#ifndef NODOBINARIO_H
#define NODOBINARIO_H

template <typename T>
struct NodoBinario {
    T dato;
    NodoBinario* izquierdo;
    NodoBinario* derecho;

    NodoBinario(T valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
};

#endif
