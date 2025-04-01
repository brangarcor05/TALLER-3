#ifndef ARBOLROJONEGRO_H
#define ARBOLROJONEGRO_H

#include "Nodo.h"
#include <iostream>

class ArbolRojoNegro {
private:
    Nodo *raiz;

    void rotacionIzquierda(Nodo *x);
    void rotacionDerecha(Nodo *x);
    void corregirInsercion(Nodo *k);
    void insertar(int dato);

    void recorridoInorden(Nodo *nodo);
    void recorridoPreorden(Nodo *nodo);
    void recorridoPosorden(Nodo *nodo);

public:
    ArbolRojoNegro();
    void insertarPublico(int dato);
    void recorridoInordenPublico();
    void recorridoPreordenPublico();
    void recorridoPosordenPublico();
};

#endif // ARBOLROJONEGRO_H
