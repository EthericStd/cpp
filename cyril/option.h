// fichier contenant les constantes
#define MAX_ITER 100000 // maximu d'itérations
#define NB_CHEMIN 50
#define NB_VILLE 50
#define MAX_X 10 // taille de la matrice en x
#define MAX_Y 10 // taille de la matrice en y

#define NB_Elitiste NB_CHEMIN*0.2 // nombre de chemins retournés par l'élitisme
#define NB_SELECTION NB_CHEMIN*0.8 // nombre de chemins retournés par la sélection

#define WIDTH 1200 // taille de la fenetre en x
#define HEIGHT 675 // taille de la fenetre en y

#define FACTOR_X WIDTH/MAX_X // facteur multiplicatif en x servant pour la matrice
#define FACTOR_Y HEIGHT/MAX_Y // facteur multiplicatif en y servant pour la matrice
// par exemple si MAX_X et MAX_Y sont égaux à 10,
// si une ville est sur la matrice en (10, 10),
// pour afficher la ville à l'écran,
// on multiplie ses coordonnées dans la matrice par les facteurs
