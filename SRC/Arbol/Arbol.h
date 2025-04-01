#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

template <typename T>
class Arbol {
private:
    Nodo<T>* raiz;

public:
    Arbol();  // Constructor por defecto
    Arbol(T val);  // Constructor con valor
    bool esVacio();  // Verificar si el árbol está vacío
    Nodo<T>* obtenerRaiz();  // Obtener la raíz
    void fijarRaiz(Nodo<T>* nraiz);  // Establecer la raíz
    bool insertarNodo(T padre, T n);  // Insertar nodo
    bool eliminarNodo(T n);  // Eliminar nodo
    Nodo<T>* buscarNodo(T val);  // Buscar nodo
    int altura();  // Obtener altura del árbol
    int tamano();  // Obtener tamaño del árbol
    void nivelOrden();  // Recorrido por nivel
};

#endif // ARBOL_H
