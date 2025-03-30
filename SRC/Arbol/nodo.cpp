#include "Nodo.h"

template <class T>
Nodo<T>::Nodo() : dato(T()) {}

template <class T>
Nodo<T>::Nodo(const T& val) : dato(val) {}

template <class T>
T Nodo<T>::obtenerDato() { return dato; }

template <class T>
void Nodo<T>::fijarDato(const T& val) { dato = val; }

template <class T>
vector<Nodo<T>*>& Nodo<T>::obtenerDesc() { return hijos; }

template <class T>
void Nodo<T>::fijarDesc(const vector<Nodo<T>*>& listaDesc) { hijos = listaDesc; }

template <class T>
void Nodo<T>::adicionarDesc(T val) { hijos.push_back(new Nodo<T>(val)); }

template <class T>
bool Nodo<T>::eliminarDesc(T val) {
    for (auto it = hijos.begin(); it != hijos.end(); ++it) {
        if ((*it)->dato == val) {
            delete *it;
            hijos.erase(it);
            return true;
        }
    }
    return false;
}

template <class T>
Nodo<T>* Nodo<T>::buscarDesc(T val) {
    for (Nodo<T>* hijo : hijos) {
        if (hijo->dato == val) return hijo;
    }
    return nullptr;
}

template <class T>
int Nodo<T>::altura() {
    int maxAltura = -1;
    for (Nodo<T>* hijo : hijos) {
        maxAltura = max(maxAltura, hijo->altura());
    }
    return maxAltura + 1;
}

template <class T>
int Nodo<T>::tamano() {
    int count = 1;
    for (Nodo<T>* hijo : hijos) {
        count += hijo->tamano();
    }
    return count;
}

template <class T>
void Nodo<T>::preOrden() {
    stack<Nodo<T>*> pila;
    pila.push(this);
    while (!pila.empty()) {
        Nodo<T>* actual = pila.top();
        pila.pop();
        cout << actual->dato << " ";
        for (auto it = actual->hijos.rbegin(); it != actual->hijos.rend(); ++it) {
            pila.push(*it);
        }
    }
    cout << endl;
}

template <class T>
void Nodo<T>::posOrden() {
    stack<Nodo<T>*> pila1, pila2;
    pila1.push(this);
    while (!pila1.empty()) {
        Nodo<T>* actual = pila1.top();
        pila1.pop();
        pila2.push(actual);
        for (Nodo<T>* hijo : actual->hijos) {
            pila1.push(hijo);
        }
    }
    while (!pila2.empty()) {
        cout << pila2.top()->dato << " ";
        pila2.pop();
    }
    cout << endl;
}

template <class T>
void Nodo<T>::inOrden() {
    if (hijos.empty()) {
        cout << dato << " ";
        return;
    }
    for (size_t i = 0; i < hijos.size(); ++i) {
        hijos[i]->inOrden();
        if (i == 0) cout << dato << " ";
    }
}

template <class T>
void Nodo<T>::nivelOrden() {
    queue<Nodo<T>*> cola;
    cola.push(this);
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";
        for (Nodo<T>* hijo : actual->hijos) {
            cola.push(hijo);
        }
    }
    cout << endl;
}



