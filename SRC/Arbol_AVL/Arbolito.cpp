#include "ArbolBinarioAVL.h"
#include <iostream>

int main() {
    ArbolBinarioAVL<int> arbol;
    
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(5);
    arbol.insertar(6);
    arbol.insertar(15);

    cout << "Recorrido InOrden: ";
    arbol.imprimirInOrden();

    cout << "Recorrido PreOrden: ";
    arbol.imprimirPreOrden();

    cout << "Recorrido PostOrden: ";
    arbol.imprimirPostOrden();

    return 0;
}

