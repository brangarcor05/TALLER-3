#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

template <class T>
class NodoBinarioAVL {
    private:
        T dato;
        NodoBinarioAVL<T>* hijoIzq;
        NodoBinarioAVL<T>* hijoDer;

    public:
        NodoBinarioAVL();
        ~NodoBinarioAVL();
        
        T& getDato();
        void setDato(const T& val);
        
        NodoBinarioAVL<T>* getHijoIzq();
        NodoBinarioAVL<T>* getHijoDer();
        
        void setHijoIzq(NodoBinarioAVL<T>* izq);
        void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.tpp"  // Cambio de extensión si es necesario

#endif // NODOBINARIOAVL_H
