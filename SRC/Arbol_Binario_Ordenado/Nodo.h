#ifndef NODO_H
#define NODO_H

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int valor);
};

#endif
