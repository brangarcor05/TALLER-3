#ifndef BST_H
#define BST_H

#include "Nodo.h"

class BST {
public:
    Nodo* raiz;

    BST();
    ~BST();

    void insertar(int valor);
    Nodo* buscar(int valor);
    void eliminar(int valor);
    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();

private:
    Nodo* insertarRecursivo(Nodo* nodo, int valor);
    Nodo* buscarRecursivo(Nodo* nodo, int valor);
    Nodo* eliminarRecursivo(Nodo* nodo, int valor);
    Nodo* minimoNodo(Nodo* nodo);
    void inorden(Nodo* nodo);
    void preorden(Nodo* nodo);
    void postorden(Nodo* nodo);
    void destruirRecursivo(Nodo* nodo);
};

#endif
