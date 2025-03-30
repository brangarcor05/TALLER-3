#include "Arbol.h"

// Constructor por defecto, inicializa la raíz como un puntero nulo
template <class T>
Arbol<T>::Arbol() : raiz(nullptr) {}

// Constructor que inicializa el árbol con un nodo raíz con valor val
template <class T>
Arbol<T>::Arbol(T val) {
    raiz = new Nodo<T>(val);
}

// Verifica si el árbol es vacío (si la raíz es nula)
template <class T>
bool Arbol<T>::esVacio() {
    return raiz == nullptr;
}

// Obtiene la raíz del árbol
template <class T>
Nodo<T>* Arbol<T>::obtenerRaiz() {
    return raiz;
}

// Fija la raíz del árbol a un nuevo nodo
template <class T>
void Arbol<T>::fijarRaiz(Nodo<T>* nraiz) {
    raiz = nraiz;
}

// Inserta un nodo con valor n como hijo del nodo con valor padre
template <class T>
bool Arbol<T>::insertarNodo(T padre, T n) {
    if (!raiz) return false; // Si la raíz es nula, no se puede insertar
    queue<Nodo<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        if (actual->dato == padre) {
            actual->adicionarDesc(n); // Agrega n como hijo del nodo actual
            return true;
        }
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    return false; // No se encontró el nodo padre
}

// Elimina el nodo con valor n del árbol
template <class T>
bool Arbol<T>::eliminarNodo(T n) {
    if (!raiz) return false; // Si la raíz es nula, no se puede eliminar
    if (raiz->dato == n) {
        delete raiz;
        raiz = nullptr;
        return true;
    }
    queue<Nodo<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        if (actual->eliminarDesc(n)) return true; // Elimina el nodo descendiente
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    return false; // No se encontró el nodo a eliminar
}

// Busca un nodo con valor val en el árbol
template <class T>
Nodo<T>* Arbol<T>::buscarNodo(T val) {
    if (!raiz) return nullptr; // Si la raíz es nula, no se puede buscar
    queue<Nodo<T>*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        if (actual->dato == val) return actual; // Nodo encontrado
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    return nullptr; // No se encontró el nodo
}

// Calcula la altura del árbol
template <class T>
int Arbol<T>::altura() {
    return raiz ? raiz->altura() : -1;
}

// Calcula el tamaño del árbol (número de nodos)
template <class T>
int Arbol<T>::tamano() {
    return raiz ? raiz->tamano() : 0;
}

// Realiza un recorrido en nivel del árbol
template <class T>
void Arbol<T>::nivelOrden() {
    if (raiz) raiz->nivelOrden();
}
