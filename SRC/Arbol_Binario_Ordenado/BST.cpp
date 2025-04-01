#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() : raiz(nullptr) {}

BST::~BST() {
    destruirRecursivo(raiz);
}

void BST::insertar(int valor) {
    raiz = insertarRecursivo(raiz, valor);
}

Nodo* BST::buscar(int valor) {
    return buscarRecursivo(raiz, valor);
}

void BST::eliminar(int valor) {
    raiz = eliminarRecursivo(raiz, valor);
}

void BST::mostrarInorden() {
    cout << "Recorrido Inorden (Ordenado): ";
    inorden(raiz);
    cout << endl;
}

void BST::mostrarPreorden() {
    cout << "Recorrido Preorden: ";
    preorden(raiz);
    cout << endl;
}

void BST::mostrarPostorden() {
    cout << "Recorrido Postorden: ";
    postorden(raiz);
    cout << endl;
}

Nodo* BST::insertarRecursivo(Nodo* nodo, int valor) {
    if (!nodo) return new Nodo(valor);

    if (valor < nodo->dato)
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, valor);
    else if (valor > nodo->dato)
        nodo->derecho = insertarRecursivo(nodo->derecho, valor);

    return nodo;
}

Nodo* BST::buscarRecursivo(Nodo* nodo, int valor) {
    if (!nodo || nodo->dato == valor)
        return nodo;

    if (valor < nodo->dato)
        return buscarRecursivo(nodo->izquierdo, valor);
    else
        return buscarRecursivo(nodo->derecho, valor);
}

Nodo* BST::eliminarRecursivo(Nodo* nodo, int valor) {
    if (!nodo) return nodo;

    if (valor < nodo->dato)
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, valor);
    else if (valor > nodo->dato)
        nodo->derecho = eliminarRecursivo(nodo->derecho, valor);
    else {
        if (!nodo->izquierdo) {
            Nodo* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (!nodo->derecho) {
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }

        Nodo* temp = minimoNodo(nodo->derecho);
        nodo->dato = temp->dato;
        nodo->derecho = eliminarRecursivo(nodo->derecho, temp->dato);
    }
    return nodo;
}

Nodo* BST::minimoNodo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izquierdo)
        actual = actual->izquierdo;
    return actual;
}

void BST::inorden(Nodo* nodo) {
    if (!nodo) return;
    inorden(nodo->izquierdo);
    cout << nodo->dato << " ";
    inorden(nodo->derecho);
}

void BST::preorden(Nodo* nodo) {
    if (!nodo) return;
    cout << nodo->dato << " ";
    preorden(nodo->izquierdo);
    preorden(nodo->derecho);
}

void BST::postorden(Nodo* nodo) {
    if (!nodo) return;
    postorden(nodo->izquierdo);
    postorden(nodo->derecho);
    cout << nodo->dato << " ";
}

void BST::destruirRecursivo(Nodo* nodo) {
    if (nodo) {
        destruirRecursivo(nodo->izquierdo);
        destruirRecursivo(nodo->derecho);
        delete nodo;
    }
}
