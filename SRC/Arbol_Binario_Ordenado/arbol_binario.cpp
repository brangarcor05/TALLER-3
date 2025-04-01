#include "ArbolBinario.hpp"

int main() {
    ArbolBinario<int> arbol;

    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);

    std::cout << "Preorden: ";
    arbol.preOrden();

    std::cout << "Inorden: ";
    arbol.inOrden();

    std::cout << "Posorden: ";
    arbol.posOrden();

    int buscarValor = 40;
    if (arbol.buscar(buscarValor))
        std::cout << buscarValor << " encontrado en el árbol." << std::endl;
    else
        std::cout << buscarValor << " no encontrado en el árbol." << std::endl;

    return 0;
}
