#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main() {
    // Crear el árbol con un punto inicial
    Arbol<int> arbol(pair<int, int>(10, 10));
    
    // Insertar varios puntos en el árbol
    arbol.insertar(pair<int, int>(5, 5));
    arbol.insertar(pair<int, int>(15, 15));
    arbol.insertar(pair<int, int>(20, 20));
    arbol.insertar(pair<int, int>(2, 2));
    arbol.insertar(pair<int, int>(8, 8));

    // Imprimir la altura y tamaño del árbol
    cout << "Altura del árbol: " << arbol.altura() << endl;
    cout << "Tamaño del árbol: " << arbol.tamano() << endl;

    // Buscar un punto específico en el árbol
    pair<int, int> punto_buscar(15, 15);
    Nodo<int>* resultado = arbol.buscar(punto_buscar);
    if (resultado != nullptr) {
        cout << "Punto encontrado: (" << resultado->obtenerDato().first << ", " << resultado->obtenerDato().second << ")" << endl;
    } else {
        cout << "Punto no encontrado." << endl;
    }

    // Realizar recorrido preorden
    cout << "Recorrido en preorden:" << endl;
    arbol.preOrden();

    // Realizar recorrido posorden
    cout << "Recorrido en posorden:" << endl;
    arbol.posOrden();

    return 0;
}
