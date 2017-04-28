OBJ=main.o IGene.o IChromosome.o IPopulation.o
HEAD=IGene.h IChromosome.h IPopulation.h

all : main.exe

main.exe : $(OBJ) $(HEAD)
	g++ $(OBJ) -o main.exe
	./main.exe

IGene.o : IGene.cc IGene.h
	g++ -c IGene.cc

IChromosome.o : IChromosome.cc IChromosome.h IGene.h
	g++ -c IChromosome.cc

IPopulation.o : IPopulation.cc IPopulation.h IChromosome.h
	g++ -c IPopulation.cc

clear :
	rm main.exe main.o IGene.o IChromosome.o IPopulation.o
