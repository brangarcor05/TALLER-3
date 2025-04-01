#include "AVLTree.h"

int main() {
    AVLTree arbol;

    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(30);
    arbol.insertar(40);
    arbol.insertar(50);
    arbol.insertar(25);

    cout << "Recorrido Inorden: ";
    arbol.inOrden();

    cout << "Recorrido Preorden: ";
    arbol.preOrden();

    cout << "Recorrido Posorden: ";
    arbol.posOrden();

    arbol.eliminar(30);
    cout << "Después de eliminar 30, Inorden: ";
    arbol.inOrden();

    return 0;
}
