#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

struct Nodo {
    int clave;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(int k) : clave(k), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

#endif // NODOBINARIOAVL_H
