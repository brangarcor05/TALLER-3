#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

// Estructura que representa un nodo de un árbol AVL
struct Nodo {
    int clave;                // Valor clave del nodo
    Nodo* izquierda;          // Puntero al hijo izquierdo
    Nodo* derecha;            // Puntero al hijo derecho
    int altura;               // Altura del nodo en el árbol

    // Constructor que inicializa el nodo con una clave y establece los hijos y la altura
    Nodo(int k) : clave(k), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

#endif // NODOBINARIOAVL_H
