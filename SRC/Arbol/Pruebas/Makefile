CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
GTEST_LIB = -lgtest -lgtest_main -pthread

SRC = src/Arbol.cpp src/Nodo.cpp
OBJ = $(SRC:.cpp=.o)
TEST_SRC = test/test_arbol.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_EXEC = test_arbol

all: $(TEST_EXEC)

$(TEST_EXEC): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(OBJ) $(TEST_OBJ) $(GTEST_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TEST_EXEC)
