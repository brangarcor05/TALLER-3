#include "ArbolRojoNegro.h"

int main() {
    ArbolRojoNegro arbol;

    // Insertar algunos elementos
    arbol.insertarPublico(10);
    arbol.insertarPublico(20);
    arbol.insertarPublico(30);
    arbol.insertarPublico(15);
    arbol.insertarPublico(25);

    // Mostrar el árbol en diferentes recorridos
    std::cout << "Recorrido Inorden: ";
    arbol.recorridoInordenPublico(); // El recorrido en orden de los nodos

    std::cout << "Recorrido Preorden: ";
    arbol.recorridoPreordenPublico(); // El recorrido preorden de los nodos

    std::cout << "Recorrido Posorden: ";
    arbol.recorridoPosordenPublico(); // El recorrido posorden de los nodos

    return 0;
}
