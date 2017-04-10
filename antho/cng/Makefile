##### MACROS GNU MAKE #####

# le compilateur (integre l'editeur de liens)
CC = gcc

# options du compilateur
# mode DEBUG ou non (cf. option -g et constante DEBUG)
DEBUG=no
ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -W -Wstrict-prototypes -Werror -O2 -funroll-loops -pedantic -ffast-math -I. -D_DEBUG -g
else
	CFLAGS = -Wall -W -Wstrict-prototypes -Werror -O2 -funroll-loops -pedantic -ffast-math -I.
endif

# options de l'editeur de liens (linker)
LDFLAGS = -L. -L/usr/include/GL -L/usr/X11R6/lib -lcng -lglut -lGLU -lGL -lX11 -lm

EXEC = bresenham demo1_cng
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

##### TARGETS ######

# le caractere @ permet une commande "silencieuse" (desactive l'echo)
default:
	@echo "*** specifier une cible"

# les executables a generer
bresenham: bresenham.o
	@echo "*** etape 3 : edition de liens"
	$(CC) $< $(LDFLAGS) -o $@

demo1_cng: demo1_cng.o
	@echo "*** etape 3 : edition de liens"
	$(CC) $< $(LDFLAGS) -o $@

# regle generique appelee par defaut
%.o: %.c
	@echo "*** etape 1&2 : preprocesseur et compilation separee"
	$(CC) $(CFLAGS) $< -c

# informations
# test replique car les commandes doivent etre place APRES la 1ere cible
ifeq ($(DEBUG),yes)
	@echo "*** generation en mode debug"
else
	@echo "*** generation en mode release"
endif

# regle de dependance
$(OBJ): cng.h

# bibliotheque CNG
libcng.a: cng.o
	@echo "*** creation de la bibliotheque CNG"
	ar cr libcng.a cng.o
	ranlib libcng.a

cng.o: cng.c cng.h
	$(CC) $(CFLAGS) cng.c -c

# cibles dont les dependances seront systematiquement reconstruites
# clean peut etre le nom d'un fichier present dans le repertoire courant,
# etant plus recent que ses dependances, la regle ne serait jamais executee.
.PHONY: depend clean realclean

# nettoyage partiel
clean:
	@echo "*** suppression des fichiers objets et des backups"
	@rm -f *.o *~

# nettoyage partiel avec executables
realclean:
	@echo "*** suppression des fichiers objets, des backups et des executables"
	@rm -f *.o *~ $(EXEC)

# nettoyage total y compris la bibliotheque
totalclean:
	@echo "*** suppression de tous les fichiers sauf des sources"
	@rm -f *.o *~ $(EXEC) libcng.a

# makedepend se trouve dans le package xutils-dev (!)
# construit automatiquement la liste des dependances des fichiers d'en-tete
# ATTENTION : modifie le Makefile
depend:
	@echo "*** generation automatique de la liste des dependances"
	@echo "Continuer ?"
	@read rep
	@if [ $rep = "oui" ]; then makedepend -I. $(SRC); fi
