OBJ=main.o CVille.o CChemin.o CPopulation.o
HEAD=CVille.h CChemin.h CPopulation.h

all : main.exe

main.exe : $(OBJ) $(HEAD)
	g++ $(OBJ) -o main.exe
	./main.exe

CVille.o : CVille.cc CVille.h
	g++ -c CVille.cc

CChemin.o : CChemin.cc CChemin.h CVille.h
	g++ -c CChemin.cc

CPopulation.o : CPopulation.cc CPopulation.h CChemin.h
	g++ -c CPopulation.cc

clear :
	rm -f main.exe main.o CVille.o CChemin.o CPopulation.o
