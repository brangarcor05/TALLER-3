#include <gtest/gtest.h>
#include "Arbol.h"

TEST(ArbolTest, InsertarNodo) {
    Arbol<int> arbol(10);  // Crear árbol con raíz 10
    EXPECT_TRUE(arbol.insertarNodo(10, 5));  // Insertar nodo con valor 5
    EXPECT_TRUE(arbol.insertarNodo(10, 15)); // Insertar nodo con valor 15

    Nodo<int>* raiz = arbol.obtenerRaiz();
    EXPECT_EQ(raiz->obtenerDato(), 10); // Verificar que la raíz es 10
    EXPECT_EQ(raiz->obtenerHijoIzq()->obtenerDato(), 5);  // Verificar hijo izquierdo
    EXPECT_EQ(raiz->obtenerHijoDer()->obtenerDato(), 15); // Verificar hijo derecho
}

TEST(ArbolTest, BuscarNodo) {
    Arbol<int> arbol(10);
    arbol.insertarNodo(10, 5);
    arbol.insertarNodo(10, 15);

    Nodo<int>* nodo = arbol.buscarNodo(5);
    EXPECT_NE(nodo, nullptr);  // Verificar que el nodo 5 existe
    EXPECT_EQ(nodo->obtenerDato(), 5);  // Verificar que el dato es 5

    Nodo<int>* nodoNoExistente = arbol.buscarNodo(20);
    EXPECT_EQ(nodoNoExistente, nullptr);  // Verificar que el nodo 20 no existe
}

TEST(ArbolTest, EliminarNodo) {
    Arbol<int> arbol(10);
    arbol.insertarNodo(10, 5);
    arbol.insertarNodo(10, 15);

    EXPECT_TRUE(arbol.eliminarNodo(5)); // Eliminar nodo con valor 5
    EXPECT_FALSE(arbol.eliminarNodo(20)); // Intentar eliminar un nodo que no existe

    Nodo<int>* nodo = arbol.buscarNodo(5);
    EXPECT_EQ(nodo, nullptr);  // Verificar que el nodo 5 ya no existe
}

TEST(ArbolTest, EsVacio) {
    Arbol<int> arbol;
    EXPECT_TRUE(arbol.esVacio());  // El árbol debe estar vacío

    arbol.insertarNodo(10, 5);
    EXPECT_FALSE(arbol.esVacio()); // El árbol no debe estar vacío después de insertar
}

TEST(ArbolTest, Altura) {
    Arbol<int> arbol(10);
    EXPECT_EQ(arbol.altura(), 1);  // La altura inicial debe ser 1

    arbol.insertarNodo(10, 5);
    arbol.insertarNodo(10, 15);
    EXPECT_EQ(arbol.altura(), 2);  // La altura debe ser 2 después de insertar más nodos
}

TEST(ArbolTest, Tamano) {
    Arbol<int> arbol(10);
    EXPECT_EQ(arbol.tamano(), 1);  // El tamaño inicial debe ser 1

    arbol.insertarNodo(10, 5);
    arbol.insertarNodo(10, 15);
    EXPECT_EQ(arbol.tamano(), 3);  // El tamaño debe ser 3 después de insertar más nodos
}

TEST(ArbolTest, NivelOrden) {
    Arbol<int> arbol(10);
    arbol.insertarNodo(10, 5);
    arbol.insertarNodo(10, 15);

    testing::internal::CaptureStdout();  // Captura la salida estándar
    arbol.nivelOrden();  // Debería imprimir los nodos en nivel orden
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 5 15 ");  // Verifica que la salida es la esperada
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
