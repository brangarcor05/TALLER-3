#ifndef ARBOLBINARIOAVL_H
#define ARBOLBINARIOAVL_H

#include "NodoBinarioAVL.h"
#include <algorithm>

template <class T>
class ArbolBinarioAVL {
    protected:
        NodoBinarioAVL<T>* raiz;
    
    public:
        ArbolBinarioAVL();
        ~ArbolBinarioAVL();
        
        void setRaiz(NodoBinarioAVL<T>* raiz);
        NodoBinarioAVL<T>* getRaiz();
        bool esVacio();
        T& datoRaiz();
        
        int altura(NodoBinarioAVL<T>* nodo);
        int tamano(NodoBinarioAVL<T>* nodo);
        
        NodoBinarioAVL<T>* balancear(NodoBinarioAVL<T>* nodo);
        NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& nodo);
        NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& nodo);
        NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>*& nodo);
        NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>*& nodo);
        
        NodoBinarioAVL<T>* insertarRec(NodoBinarioAVL<T>* nodo, const T& val);
        bool insertar(T& val);
        
        NodoBinarioAVL<T>* eliminarRec(NodoBinarioAVL<T>* nodo, const T& val);
        bool eliminar(T& val);
        
        bool buscar(T& val);
        void preOrden(NodoBinarioAVL<T>* nodo);
        void inOrden(NodoBinarioAVL<T>* nodo);
        void posOrden(NodoBinarioAVL<T>* nodo);
        void nivelOrden(NodoBinarioAVL<T>* nodo);
};

#include "ArbolBinarioAVL.cpp"

#endif // ARBOLBINARIOAVL_H
