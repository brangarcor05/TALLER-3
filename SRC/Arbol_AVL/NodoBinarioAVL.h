#ifndef NODO_BINARIO_AVL_H
#define NODO_BINARIO_AVL_H

template <typename T>
class NodoBinarioAVL {
private:
    T dato;
    NodoBinarioAVL* hijoIzq;
    NodoBinarioAVL* hijoDer;
    int altura;

public:
    NodoBinarioAVL(T valor);

    // Getters y Setters
    T getDato();
    void setDato(T valor);
    
    NodoBinarioAVL* getHijoIzq();
    void setHijoIzq(NodoBinarioAVL* nodo);
    
    NodoBinarioAVL* getHijoDer();
    void setHijoDer(NodoBinarioAVL* nodo);
    
    int getAltura();
    void setAltura(int h);
};

// Implementación en el archivo .cpp
#include "NodoBinarioAVL.cpp"
#endif // NODOBINARIOAVL_H
