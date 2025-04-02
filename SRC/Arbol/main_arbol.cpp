#include <iostream>
#include "Arbol.h"

int main() {
    Arbol<int> arbol(1);  // Crear árbol con raíz 1
    arbol.insertarNodo(1, 2);  // Agregar hijo 2
    arbol.insertarNodo(1, 3);  // Agregar hijo 3
    arbol.insertarNodo(2, 4);  // Agregar hijo 4
    arbol.insertarNodo(2, 5);  // Agregar hijo 5

    cout << "Preorden: ";
    arbol.obtenerRaiz()->preOrden();  // Recorrido preorden
    cout << endl;

    cout << "Postorden: ";
    arbol.obtenerRaiz()->posOrden();  // Recorrido postorden
    cout << endl;

    cout << "Inorden: ";
    arbol.obtenerRaiz()->inOrden();  // Recorrido inorden
    cout << endl;

    cout << "Nivel orden: ";
    arbol.nivelOrden();  // Recorrido por nivel
    cout << endl;

    return 0;
}
