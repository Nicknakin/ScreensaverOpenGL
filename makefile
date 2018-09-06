CXX = g++
oglflags = -lsfml-graphics -lsfml-window -lsfml-system

default: cell.o grid.o main.o
	$(CXX) -o shapes.out main.o cell.o grid.o $(oglflags)

debug: main.o cell.o
	$(CXX) -g -Wall -o dbgshapes.out main.cpp cell.cpp grid.cpp $(oglflags)

main: main.cpp
	$(CXX) -c main.cpp $(oglflags)

cell: cell.cpp cell.h
	$(CXX) -c cell.cpp $(oglflags)

grid: grid.cpp grid.h
	$(CXX) -c grid.cpp $(oglflags)

clean:
	rm -rf *.o *.out
