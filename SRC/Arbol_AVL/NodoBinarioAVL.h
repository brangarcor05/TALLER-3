#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

// Definición de la plantilla de la clase NodoBinarioAVL
template <class T>
class NodoBinarioAVL {
    private:
        T dato;  // Dato almacenado en el nodo
        int altura;  // Altura del nodo en el árbol AVL
        NodoBinarioAVL<T>* hijoIzq;  // Puntero al hijo izquierdo
        NodoBinarioAVL<T>* hijoDer;  // Puntero al hijo derecho

    public:
        // Constructor por defecto
        NodoBinarioAVL();

        // Destructor
        ~NodoBinarioAVL();
        
        // Método para obtener el dato almacenado en el nodo
        T& getDato();

        // Método para establecer el dato almacenado en el nodo
        void setDato(const T& val);
        
        // Método para obtener el puntero al hijo izquierdo
        NodoBinarioAVL<T>* getHijoIzq();

        // Método para obtener el puntero al hijo derecho
        NodoBinarioAVL<T>* getHijoDer();
        
        // Método para establecer el puntero al hijo izquierdo
        void setHijoIzq(NodoBinarioAVL<T>* izq);

        // Método para establecer el puntero al hijo derecho
        void setHijoDer(NodoBinarioAVL<T>* der);

        // Método para obtener altura del nodo
        int getAltura();

        // Método para establecer altura del nodo
        void setAltura(int h);

};

// Incluir la implementación del archivo de plantilla
#include "NodoBinarioAVL.cpp"  // Cambio de extensión si es necesario

#endif // NODOBINARIOAVL_H
