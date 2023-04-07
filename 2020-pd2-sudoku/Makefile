all:generate.o transform.o solve.o sudoku.o
	g++ -o generate generate.o sudoku.o
	g++ -o transform transform.o sudoku.o
	g++ solve.o sudoku.o -O3 -o solve

sudoku.o: sudoku.cpp sudoku.h
	g++ sudoku.cpp -O3 -c

generate.o: generate.cpp sudoku.h
	g++ -c generate.cpp

transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp

solve.o: solve.cpp sudoku.h
	g++ solve.cpp -O3 -c

clean:
	rm transform.o
	rm sudoku.o
	rm generate.o
	rm solve.o
	rm transform generate solve
