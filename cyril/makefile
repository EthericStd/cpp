OBJ=main.o CVille.o CChemin.o IPopulation.o
HEAD=CVille.h CChemin.h IPopulation.h

all : main.exe

main.exe : $(OBJ) $(HEAD)
	g++ $(OBJ) -o main.exe
	./main.exe

CVille.o : CVille.cc CVille.h
	g++ -c CVille.cc

CChemin.o : CChemin.cc CChemin.h CVille.h
	g++ -c CChemin.cc

IPopulation.o : IPopulation.cc IPopulation.h CChemin.h
	g++ -c IPopulation.cc

clear :
	rm main.exe main.o CVille.o CChemin.o IPopulation.o
