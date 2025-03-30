#include "ArbolBinarioAVL.h"
#include <iostream>

int main() {
    ArbolBinarioAVL<int> arbol;

    // Inserta valores en el árbol
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(5);
    arbol.insertar(6);
    arbol.insertar(15);

    // Imprime recorridos del árbol
    cout << "Recorrido InOrden: ";
    arbol.imprimirInOrden();

    cout << "Recorrido PreOrden: ";
    arbol.imprimirPreOrden();

    cout << "Recorrido PostOrden: ";
    arbol.imprimirPostOrden();

    return 0;
}
