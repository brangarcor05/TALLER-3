#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST arbol;

    // Insertar valores
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(20);
    arbol.insertar(3);
    arbol.insertar(8);
    arbol.insertar(25);

    // Mostrar los recorridos
    arbol.mostrarInorden();
    arbol.mostrarPreorden();
    arbol.mostrarPostorden();

    // Buscar un valor
    Nodo* resultado = arbol.buscar(8);
    if (resultado) cout << "Nodo con valor 8 encontrado." << endl;
    else cout << "Nodo con valor 8 no encontrado." << endl;

    // Eliminar un valor
    arbol.eliminar(20);
    arbol.mostrarInorden();

    return 0;
}
