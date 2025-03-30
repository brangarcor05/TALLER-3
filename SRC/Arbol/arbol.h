#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

// Definición de la plantilla de clase Arbol
template <class T>
class Arbol {
public:
    Nodo<T>* raiz;  // Puntero a la raíz del árbol

    // Constructor por defecto
    Arbol();

    // Constructor que inicializa el árbol con un valor
    Arbol(T val);

    // Verifica si el árbol está vacío
    bool esVacio();

    // Obtiene la raíz del árbol
    Nodo<T>* obtenerRaiz();

    // Fija la raíz del árbol
    void fijarRaiz(Nodo<T>* nraiz);

    // Inserta un nodo en el árbol
    bool insertarNodo(T padre, T n);

    // Elimina un nodo del árbol
    bool eliminarNodo(T n);

    // Busca un nodo en el árbol
    Nodo<T>* buscarNodo(T val);

    // Obtiene la altura del árbol
    int altura();

    // Obtiene el tamaño del árbol
    int tamano();

    // Imprime el árbol en orden de nivel
    void nivelOrden();
};

#include "Arbol.cpp"
#endif
