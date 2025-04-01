#ifndef NODO_H
#define NODO_H

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Nodo {
private:
    T dato;
    vector<Nodo<T>*> hijos;

public:
    Nodo();  // Constructor por defecto
    Nodo(const T& val);  // Constructor con valor
    T obtenerDato();  // Obtener dato
    void fijarDato(const T& val);  // Establecer dato
    vector<Nodo<T>*>& obtenerDesc();  // Obtener hijos
    void fijarDesc(const vector<Nodo<T>*>& listaDesc);  // Establecer hijos
    void adicionarDesc(T val);  // Agregar hijo
    bool eliminarDesc(T val);  // Eliminar hijo
    Nodo<T>* buscarDesc(T val);  // Buscar hijo
    int altura();  // Calcular altura
    int tamano();  // Calcular tamaño
    void preOrden();  // Recorrido preorden
    void posOrden();  // Recorrido postorden
    void inOrden();  // Recorrido inorden
    void nivelOrden();  // Recorrido por nivel
};

#endif // NODO_H
