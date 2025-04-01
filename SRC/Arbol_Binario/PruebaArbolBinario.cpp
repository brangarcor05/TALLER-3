#include "ArbolBinario.h"
using namespace std;
int main() {
    ArbolBinario<int> arbol;

    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(20);
    arbol.insertar(15);
    arbol.insertar(8);
    arbol.insertar(3);
    arbol.insertar(25);

    cout << "Raiz: " << arbol.datoRaiz() << endl;
    cout << "Altura del árbol: " << arbol.altura() << endl;
    cout << "Tamaño del árbol: " << arbol.tamano() << endl;

    cout << "Recorrido Preorden: ";
    arbol.preOrden();

    cout << "Recorrido Inorden: ";
    arbol.inOrden();

    cout << "Recorrido Posorden: ";
    arbol.posOrden();

    cout << "Buscando el valor 15: ";
    if (arbol.buscar(15)) cout << "Encontrado" << endl;
    else cout << "No encontrado" << endl;

    arbol.eliminar(15);
    cout << "Después de eliminar 15:" << endl;

    cout << "Recorrido Inorden: ";
    arbol.inOrden();

    return 0;
}
