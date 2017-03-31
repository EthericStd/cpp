OBJ=main.o Igene.o Ichromosome.o Ipopulation.o
HEAD=Igene.h Ichromosome.h Ipopulation.h

all : main.exe

main.exe : main.o $(HEAD)
	g++ main.o -o main.exe
	./main.exe
