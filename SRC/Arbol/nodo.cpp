#include "Nodo.h"
#include <queue>
template <typename T>
Nodo<T>::Nodo() : dato(T()) {}

template <typename T>
Nodo<T>::Nodo(const T& val) : dato(val) {}

template <typename T>
T Nodo<T>::obtenerDato() {
    return dato;
}

template <typename T>
void Nodo<T>::fijarDato(const T& val) {
    dato = val;
}

template <typename T>
vector<Nodo<T>*>& Nodo<T>::obtenerDesc() {
    return hijos;
}

template <typename T>
void Nodo<T>::fijarDesc(const vector<Nodo<T>*>& listaDesc) {
    hijos = listaDesc;
}

template <typename T>
void Nodo<T>::adicionarDesc(T val) {
    hijos.push_back(new Nodo<T>(val));
}

template <typename T>
bool Nodo<T>::eliminarDesc(T val) {
    for (auto it = hijos.begin(); it != hijos.end(); ++it) {
        if ((*it)->obtenerDato() == val) {
            delete *it;
            hijos.erase(it);
            return true;
        }
    }
    return false;
}

template <typename T>
Nodo<T>* Nodo<T>::buscarDesc(T val) {
    for (auto hijo : hijos) {
        if (hijo->obtenerDato() == val) {
            return hijo;
        }
    }
    return nullptr;
}

template <typename T>
int Nodo<T>::altura() {
    if (hijos.empty()) return 1;
    int maxAltura = 0;
    for (auto hijo : hijos) {
        maxAltura = max(maxAltura, hijo->altura());
    }
    return 1 + maxAltura;
}

template <typename T>
int Nodo<T>::tamano() {
    int total = 1;  // Contamos el nodo actual
    for (auto hijo : hijos) {
        total += hijo->tamano();
    }
    return total;
}

template <typename T>
void Nodo<T>::preOrden() {
    cout << dato << " ";
    for (auto hijo : hijos) {
        hijo->preOrden();
    }
}

template <typename T>
void Nodo<T>::posOrden() {
    for (auto hijo : hijos) {
        hijo->posOrden();
    }
    cout << dato << " ";
}

template <typename T>
void Nodo<T>::inOrden() {
    if (!hijos.empty()) {
        hijos[0]->inOrden();
    }
    cout << dato << " ";
    if (hijos.size() > 1) {
        hijos[1]->inOrden();
    }
}

template <typename T>
void Nodo<T>::nivelOrden() {
    queue<Nodo<T>*> cola;
    cola.push(this);
    while (!cola.empty()) {
        Nodo<T>* nodo = cola.front();
        cola.pop();
        cout << nodo->obtenerDato() << " ";
        for (auto hijo : nodo->obtenerDesc()) {
            cola.push(hijo);
        }
    }
}

// Explicitar la instanciación de plantillas para tipos que se usen en el proyecto
template class Nodo<int>;
template class Nodo<float>;
