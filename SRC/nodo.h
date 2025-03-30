#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class Nodo {
public:
    T dato;
    vector<Nodo<T>*> hijos;

    Nodo();
    Nodo(const T& val);
    T obtenerDato();
    void fijarDato(const T& val);
    vector<Nodo<T>*>& obtenerDesc();
    void fijarDesc(const vector<Nodo<T>*>& listaDesc);
    void adicionarDesc(T val);
    bool eliminarDesc(T val);
    Nodo<T>* buscarDesc(T val);
    int altura();
    int tamano();
    void preOrden();
    void posOrden();
    void inOrden();
    void nivelOrden();
};

#include "Nodo.cpp"
#endif


