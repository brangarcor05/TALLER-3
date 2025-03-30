# Makefile para compilar el proyecto del Árbol Genérico en C++

 # Compilador de C++
CC = g++ 
CFLAGS = -Wall -Wextra -std=c++11  # Opciones de compilación: advertencias y estándar C++11

# Archivos fuente del proyecto
SRC = nodo.cpp arbol.cpp prueba_arbol.cpp  
OBJ = $(SRC:.cpp=.o)  # Genera los archivos objeto reemplazando .cpp por .o

# Nombre del ejecutable
EXEC = prueba_arbol  

# Regla principal: compilar todo
all: $(EXEC)

# Enlaza los archivos objeto para crear el ejecutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regla para compilar archivos .cpp en .o asegurando la dependencia con su .h
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados (.o y el ejecutable)
clean:
	rm -f $(OBJ) $(EXEC)

# Regla para ejecutar el programa después de compilar
eval: $(EXEC)
	./$(EXEC)
