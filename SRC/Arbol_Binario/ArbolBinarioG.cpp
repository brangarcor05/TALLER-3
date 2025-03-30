#include "ArbolBinario.h"
#include "NodoBinario.h"

#include <queue>
using namespace std;


template<class T>
ArbolBinario<T>::ArbolBinario()
{
    this->raiz=NULL;
}


template<class T>
bool ArbolBinario<T>::esVacio()
{
    if(this==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
T& ArbolBinario<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}

template<class T>
int ArbolBinario<T>::altura()
{
    return this->raiz->altura();
}

template<class T>
int ArbolBinario<T>::tamano()
{
    return this->raiz->tamano() ;
}

template<class T>
void ArbolBinario<T>::insertar(T& val)
{
    if(this->raiz!=NULL)
    {
        this->raiz->insertar(val);
    }
    else
    {
        NodoBinario<T>* nuevo= new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz=nuevo;
    }


}



template<class T>
bool ArbolBinario<T>::eliminar(T& val)
{ 
	//Nodo* borrar = this->buscar(val);
	NodoBinario<T>* borrar = this->buscar(val);
    if(borrar == NULL)
        return false;

    if(borrar->hijoIzq != NULL)
    {
        //Nodo* nuevo = borrar->hijoIzq->extremo_der();
		NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    else if(borrar->hijoDer != NULL)
    {
		
        //Nodo* nuevo = borrar->hijoDer->extremo_izq();
		NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    return true;
}



template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val)
{
    return this->raiz->buscar(val);
}

template<class T>
void ArbolBinario<T>::preOrden()
{
    this->raiz->preOrden();
}

template<class T>
void ArbolBinario<T>::inOrden()
{
    this->raiz->inOrden();
}

template<class T>
void ArbolBinario<T>::posOrden()
{
    this->raiz->posOrden();
}

template<class T>
void ArbolBinario<T>::nivelOrden()
{
    this->raiz->nivelOrden();
}
// Preorden: Raíz - Izq - Der
template <typename T>
void ArbolBinarioG<T>::preOrden() { 
    preOrden(raiz); 
    cout << endl; 
}

template <typename T>
void ArbolBinarioG<T>::preOrden(NodoBinario<T>* nodo) {
    if (!nodo) return;
    cout << nodo->obtenerDato() << " ";
    preOrden(nodo->obtenerHijoIzq());
    preOrden(nodo->obtenerHijoDer());
}

// Inorden: Izq - Raíz - Der
template <typename T>
void ArbolBinarioG<T>::inOrden() { 
    inOrden(raiz); 
    cout << endl; 
}

template <typename T>
void ArbolBinarioG<T>::inOrden(NodoBinario<T>* nodo) {
    if (!nodo) return;
    inOrden(nodo->obtenerHijoIzq());
    cout << nodo->obtenerDato() << " ";
    inOrden(nodo->obtenerHijoDer());
}

// Postorden: Izq - Der - Raíz
template <typename T>
void ArbolBinarioG<T>::posOrden() { 
    posOrden(raiz); 
    cout << endl; 
}

template <typename T>
void ArbolBinarioG<T>::posOrden(NodoBinario<T>* nodo) {
    if (!nodo) return;
    posOrden(nodo->obtenerHijoIzq());
    posOrden(nodo->obtenerHijoDer());
    cout << nodo->obtenerDato() << " ";
}



template <typename T>
void ArbolBinarioG<T>::nivelOrden() {
    if (!raiz) return;
    queue<NodoBinario<T>*> q;
    q.push(raiz);
    
    while (!q.empty()) {
        NodoBinario<T>* nodo = q.front();
        q.pop();
        cout << nodo->obtenerDato() << " ";
        if (nodo->obtenerHijoIzq()) q.push(nodo->obtenerHijoIzq());
        if (nodo->obtenerHijoDer()) q.push(nodo->obtenerHijoDer());
    }
    cout << endl;
}


