main.exe: main.o CMatrice.o
	g++ main.o CMatrice.o -c main.exe

main.o: main.cc CMatrice.h
	g++ main.cc -c

CMatrice.o: CMatrice.cc CMatrice.h
	g++ CMatrice.cc -c
