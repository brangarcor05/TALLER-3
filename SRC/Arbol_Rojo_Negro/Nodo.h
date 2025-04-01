#ifndef NODO_H
#define NODO_H

enum Color {ROJO, NEGRO};

class Nodo {
public:
    int dato;
    Nodo *izquierda, *derecha, *padre;
    Color color;

    Nodo(int dato);
};

#endif // NODO_H
