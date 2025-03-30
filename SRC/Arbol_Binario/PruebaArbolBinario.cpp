#include <iostream>
#include "ArbolBinarioG.h"

using namespace std;

int main() {
    // Crear el árbol
    ArbolBinarioG<int> arbol;

    // Insertar valores
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(18);

    // Mostrar recorridos del árbol completo
    cout << "Recorrido Preorden del Árbol: ";
    arbol.preOrden();

    cout << "Recorrido Inorden del Árbol: ";
    arbol.inOrden();

    cout << "Recorrido Postorden del Árbol: ";
    arbol.posOrden();

    cout << "Recorrido Nivel Orden del Árbol: ";
    arbol.nivelOrden();

    // Buscar un nodo y recorrer su subárbol
    int valorBusqueda = 5;
    NodoBinario<int>* subarbol = arbol.buscar(valorBusqueda);
    if (subarbol) {
        cout << "\nRecorridos del subárbol con raíz en " << valorBusqueda << ":\n";
        cout << "Preorden: "; arbol.preOrden(subarbol);
        cout << "Inorden: "; arbol.inOrden(subarbol);
        cout << "Postorden: "; arbol.posOrden(subarbol);
        cout << "Nivel Orden: "; arbol.nivelOrden(subarbol);
    } else {
        cout << "\nValor " << valorBusqueda << " no encontrado en el árbol.\n";
    }

    return 0;
}
