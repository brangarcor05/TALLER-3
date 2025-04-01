# TALLER-3
Este proyecto implementa varios **Arboles vistos en la clase de Estructura de Datos** en C++ de manera modular utilizando plantillas (`template`). El árbol permite realizar operaciones como inserción, búsqueda y recorrido en diferentes órdenes (preorden, inorden, posorden).

## Estructura del Proyecto

El proyecto está dividido en varias carpetas donde en cada una encontramos por lo general lo siguente:

- **`NodoBinario.h`**: Define la clase `NodoBinario` que representa los nodos del árbol binario.
- **`NodoBinario.cpp`**: Implementa las funciones definidas en `NodoBinario.h`.  
- **`ArbolBinario.h`**: Define la clase `ArbolBinario`, que implementa el árbol binario ordenado con las operaciones básicas de inserción, búsqueda y recorridos.  
- **`ArbolBinario.cpp`**: Implementa las funciones definidas en `ArbolBinario.hpp`.  
- **`main.cpp`**: Un archivo de ejemplo para demostrar cómo usar el árbol, insertando nodos y mostrando los resultados de los recorridos.
- **`Makefile`**: Un archivo `Makefile` para facilitar la compilación y ejecución del proyecto.


## Requisitos

Este proyecto requiere un compilador de C++ que soporte las características modernas del lenguaje (C++11 o superior).

## Compilación y Ejecución con Makefile

Para compilar y ejecutar este proyecto de manera sencilla, puedes usar el **Makefile** incluido.

### Pasos para compilar y ejecutar:

1. **Compilar el proyecto**:
   Solo debes ejecutar el siguiente comando en la terminal:

   ```bash
   make
