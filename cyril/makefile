OBJ = main.o CVille.o CChemin.o CPopulation.o Mutation.o cng.o Elitisme.o Selection.o
HEAD = CVille.h CChemin.h CPopulation.h Mutation.h cng.h Elitisme.h Selection.h
LDFLAGS = -L. -L/usr/include/GL -L/usr/X11R6/lib -lcng -lglut -lGLU -lGL -lX11 -lm
CFLAGS = -Wall -W -Wstrict-prototypes -Werror -O2 -funroll-loops -pedantic -ffast-math -I.

all : main.exe

main.exe : $(OBJ) $(HEAD)
	g++ $(OBJ) -o main.exe $(LDFLAGS)
	./main.exe

CVille.o : CVille.cc CVille.h
	g++ -c CVille.cc

CChemin.o : CChemin.cc CChemin.h CVille.h
	g++ -c CChemin.cc

CPopulation.o : CPopulation.cc CPopulation.h CChemin.h
	g++ -c CPopulation.cc

Mutation.o : Mutation.cc Mutation.h CVille.h CChemin.h CPopulation.h
	g++ -c Mutation.cc

Elitisme.o : Elitisme.cc Elitisme.h CVille.h CChemin.h CPopulation.h
	g++ -c Elitisme.cc

Selection.o : Selection.cc Selection.h CVille.h CChemin.h CPopulation.h
	g++ -c Selection.cc

libcng.a: cng.o
	ar cr libcng.a cng.o
	ranlib libcng.a

cng.o: cng.h cng.c
	gcc $(CFLAGS) -c cng.c

clean:
	rm -f *.o
	rm -f *~
	rm main.exe
