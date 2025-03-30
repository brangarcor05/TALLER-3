#ifndef ARBOLBINARIOAVL_H
#define ARBOLBINARIOAVL_H

#include "NodoBinarioAVL.h"
#include <iostream>
using namespace std;

class ArbolAVL {
public:
    Nodo* raiz;
    
    ArbolAVL();
    void insertar(int clave);
    void eliminar(int clave);
    bool buscar(int clave);
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();

private:
    int obtenerAltura(Nodo* nodo);
    int obtenerBalance(Nodo* nodo);
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    Nodo* insertar(Nodo* nodo, int clave);
    Nodo* encontrarMinimo(Nodo* nodo);
    Nodo* eliminar(Nodo* nodo, int clave);
    Nodo* buscar(Nodo* nodo, int clave);
    void recorridoInorden(Nodo* nodo);
    void recorridoPreorden(Nodo* nodo);
    void recorridoPostorden(Nodo* nodo);
};

#include "ArbolBinarioAVL.cpp"

#endif // ARBOLBINARIOAVL_Hw
