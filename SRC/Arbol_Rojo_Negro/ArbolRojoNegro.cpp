#include "ArbolRojoNegro.h"

// Rotación a la izquierda
void ArbolRojoNegro::rotacionIzquierda(Nodo *x) {
    Nodo *y = x->derecha;
    x->derecha = y->izquierda;
    if (y->izquierda != nullptr) {
        y->izquierda->padre = x;
    }
    y->padre = x->padre;
    if (x->padre == nullptr) {
        raiz = y;
    } else if (x == x->padre->izquierda) {
        x->padre->izquierda = y;
    } else {
        x->padre->derecha = y;
    }
    y->izquierda = x;
    x->padre = y;
}

// Rotación a la derecha
void ArbolRojoNegro::rotacionDerecha(Nodo *x) {
    Nodo *y = x->izquierda;
    x->izquierda = y->derecha;
    if (y->derecha != nullptr) {
        y->derecha->padre = x;
    }
    y->padre = x->padre;
    if (x->padre == nullptr) {
        raiz = y;
    } else if (x == x->padre->derecha) {
        x->padre->derecha = y;
    } else {
        x->padre->izquierda = y;
    }
    y->derecha = x;
    x->padre = y;
}

// Corrección del árbol después de la inserción
void ArbolRojoNegro::corregirInsercion(Nodo *k) {
    while (k != raiz && k->padre->color == ROJO) {
        if (k->padre == k->padre->padre->izquierda) {
            Nodo *tio = k->padre->padre->derecha;
            if (tio != nullptr && tio->color == ROJO) {
                // Caso 1: El tío es rojo
                k->padre->color = NEGRO;
                tio->color = NEGRO;
                k->padre->padre->color = ROJO;
                k = k->padre->padre;
            } else {
                // Caso 2: El tío es negro o NULL
                if (k == k->padre->derecha) {
                    k = k->padre;
                    rotacionIzquierda(k);
                }
                k->padre->color = NEGRO;
                k->padre->padre->color = ROJO;
                rotacionDerecha(k->padre->padre);
            }
        } else {
            Nodo *tio = k->padre->padre->izquierda;
            if (tio != nullptr && tio->color == ROJO) {
                // Caso 1: El tío es rojo
                k->padre->color = NEGRO;
                tio->color = NEGRO;
                k->padre->padre->color = ROJO;
                k = k->padre->padre;
            } else {
                // Caso 2: El tío es negro o NULL
                if (k == k->padre->izquierda) {
                    k = k->padre;
                    rotacionDerecha(k);
                }
                k->padre->color = NEGRO;
                k->padre->padre->color = ROJO;
                rotacionIzquierda(k->padre->padre);
            }
        }
    }
    raiz->color = NEGRO;
}

// Inserción en el árbol
void ArbolRojoNegro::insertar(int dato) {
    Nodo *nuevoNodo = new Nodo(dato);
    if (raiz == nullptr) {
        raiz = nuevoNodo;
        raiz->color = NEGRO;
        return;
    }

    Nodo *padre = nullptr;
    Nodo *actual = raiz;
    while (actual != nullptr) {
        padre = actual;
        if (dato < actual->dato) {
            actual = actual->izquierda;
        } else {
            actual = actual->derecha;
        }
    }

    nuevoNodo->padre = padre;
    if (dato < padre->dato) {
        padre->izquierda = nuevoNodo;
    } else {
        padre->derecha = nuevoNodo;
    }

    corregirInsercion(nuevoNodo);
}

// Recorrido Inorden
void ArbolRojoNegro::recorridoInorden(Nodo *nodo) {
    if (nodo != nullptr) {
        recorridoInorden(nodo->izquierda);
        std::cout << nodo->dato << " (" << (nodo->color == ROJO ? "R" : "N") << ") ";
        recorridoInorden(nodo->derecha);
    }
}

// Recorrido Preorden
void ArbolRojoNegro::recorridoPreorden(Nodo *nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->dato << " (" << (nodo->color == ROJO ? "R" : "N") << ") ";
        recorridoPreorden(nodo->izquierda);
        recorridoPreorden(nodo->derecha);
    }
}

// Recorrido Posorden
void ArbolRojoNegro::recorridoPosorden(Nodo *nodo) {
    if (nodo != nullptr) {
        recorridoPosorden(nodo->izquierda);
        recorridoPosorden(nodo->derecha);
        std::cout << nodo->dato << " (" << (nodo->color == ROJO ? "R" : "N") << ") ";
    }
}

ArbolRojoNegro::ArbolRojoNegro() : raiz(nullptr) {}

void ArbolRojoNegro::insertarPublico(int dato) {
    insertar(dato);
}

void ArbolRojoNegro::recorridoInordenPublico() {
    recorridoInorden(raiz);
    std::cout << std::endl;
}

void ArbolRojoNegro::recorridoPreordenPublico() {
    recorridoPreorden(raiz);
    std::cout << std::endl;
}

void ArbolRojoNegro::recorridoPosordenPublico() {
    recorridoPosorden(raiz);
    std::cout << std::endl;
}
