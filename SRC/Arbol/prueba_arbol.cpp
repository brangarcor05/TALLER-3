// Archivo: main.cpp
#include "Arbol.h"
#include <iostream>

using namespace std;

int main() {
    // Crear un árbol con raíz 1
    Arbol<int> arbol(1);
    
    // Insertar nodos
    arbol.insertarNodo(1, 2);
    arbol.insertarNodo(1, 3);
    arbol.insertarNodo(2, 4);
    arbol.insertarNodo(2, 5);
    arbol.insertarNodo(3, 6);
    arbol.insertarNodo(3, 7);
    
    // Imprimir recorridos
    cout << "Recorrido en preorden: ";
    arbol.obtenerRaiz()->preOrden();
    
    cout << "Recorrido en inorden: ";
    arbol.obtenerRaiz()->inOrden();
    
    cout << "Recorrido en posorden: ";
    arbol.obtenerRaiz()->posOrden();
    
    cout << "Recorrido por niveles: ";
    arbol.nivelOrden();
    
    // Altura y tamaño del árbol
    cout << "Altura del árbol: " << arbol.altura() << endl;
    cout << "Tamaño del árbol: " << arbol.tamano() << endl;
    
    // Buscar nodo
    int val = 5;
    Nodo<int>* nodo = arbol.buscarNodo(val);
    if (nodo) {
        cout << "Nodo " << val << " encontrado en el árbol.\n";
    } else {
        cout << "Nodo " << val << " no encontrado.\n";
    }
    
    // Eliminar nodo
    cout << "Eliminando nodo 3...\n";
    arbol.eliminarNodo(3);
    
    // Imprimir recorrido tras la eliminación
    cout << "Recorrido en preorden tras eliminación: ";
    arbol.obtenerRaiz()->preOrden();
    
    return 0;
}

