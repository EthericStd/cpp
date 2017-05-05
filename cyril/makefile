OBJ = main.o CVille.o CChemin.o CPopulation.o Mutation.o cng.o Elitisme.o Selection.o Croisement.o Upgrade.o
HEAD = CVille.h CChemin.h CPopulation.h Mutation.h cng.h Elitisme.h Selection.h Croisement.h option.h Upgrade.h
LDFLAGS = -L. -L/usr/include/GL -L/usr/X11R6/lib -lcng -lglut -lGLU -lGL -lX11 -lm
CFLAGS = -Wall -W -Wstrict-prototypes -Werror -O2 -funroll-loops -pedantic -ffast-math -I.

all : main.exe

main.exe : $(OBJ) $(HEAD)
	g++ $(OBJ) -o main.exe $(LDFLAGS)
	./main.exe

main.o : main.cc $(HEAD)
	g++ -std=c++0x -c main.cc

CVille.o : CVille.cc CVille.h
	g++ -c CVille.cc

CChemin.o : CChemin.cc CChemin.h CVille.h
	g++ -c CChemin.cc

CPopulation.o : CPopulation.cc CPopulation.h CChemin.h option.h
	g++ -c CPopulation.cc

Mutation.o : Mutation.cc Mutation.h CVille.h CChemin.h CPopulation.h
	g++ -c Mutation.cc

Elitisme.o : Elitisme.cc Elitisme.h CVille.h CChemin.h CPopulation.h
	g++ -c Elitisme.cc

Selection.o : Selection.cc Selection.h CVille.h CChemin.h CPopulation.h
	g++ -c Selection.cc

Croisement.o : Croisement.cc Croisement.h CVille.h CChemin.h CPopulation.h
	g++ -c Croisement.cc

Upgrade.o : Upgrade.cc Upgrade.h CVille.h CChemin.h CPopulation.h Mutation.h Elitisme.h Selection.h Croisement.h
	g++ -c Upgrade.cc

libcng.a: cng.o
	ar cr libcng.a cng.o
	ranlib libcng.a

cng.o: cng.h cng.c
	gcc $(CFLAGS) -c cng.c

clean:
	rm -f *.o
	rm -f *~
	rm main.exe
