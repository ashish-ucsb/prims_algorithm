main: main.cpp prims.cpp
	     g++ -o main main.cpp prims.cpp -I.
clean:
	     rm -f main
