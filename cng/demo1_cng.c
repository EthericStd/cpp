#include <stdio.h>
#include <stdlib.h>
#include "cng.h"

#define WSIZE 640
#define HSIZE 480

void menu(void)
{
  /* couleur blanche */
  cng_current_color(1.0, 1.0, 1.0);

  /* affichage du menu */
  cng_draw_string("MENU", 20, 10);
  cng_draw_string("[a] association d'une touche", 20, 50);
  cng_draw_string("[b] palette du feu", 20, 65);
  cng_draw_string("[c] animation tres simple", 20, 80);
  cng_draw_string("Evenements pris en compte : bouton 0 et deplacement de la souris", 20, 110);
  cng_draw_string("[ESC] Quitter", 20, 140);
  cng_swap_screen();
}

/* rebond d'un cercle et mesure de temps */
int simple_animation(void)
{
  int i;
  int cx = WSIZE/2, cy = HSIZE/2; /* position initiale du cercle */
  int vx = 5, vy = 5; /* vecteur direction */
  int cra = 50; /* rayon du cercle */
  int cx0 = 0, cy0 = 0, cx1 = 0, cy1 = 0;

  fprintf(stderr, "touche [c] pressee\n");

  /* on efface l'ecran (en noir) */
  cng_clear_screen();

  /* Recuperation du temps initial */
  cng_start_clock();

  cng_current_color(0.0, 1.0, 0.0);
  for (i = 0 ; i < 500 ; i++) {
    /* a droite ou a gauche */
    if ((cx+vx+cra > WSIZE) || (cx-abs(vx)-cra < 0)) vx = -vx;
    /* en bas ou en haut */
    if ((cy+vy+cra > HSIZE) || (cy-abs(vy)-cra < 0)) vy = -vy;
    /* mise a jour de la position du cercle */
    cx += vx; cy += vy;
    /* affichage du cercle */
    cng_circle(cx,cy,cra);
    cng_swap_screen();
    /* effacement de l'ecran */
    cng_clear_screen();
  }
  /* Recuperation du temps final */
  printf("Temps 1 : %f s\n", cng_get_time());

  /* methode plus rapide : effacement du cercle precedent */
  cx = WSIZE/2;
  cy = HSIZE/2;
  cng_clear_screen();
  cng_start_clock();

  cng_current_color(0.0, 1.0, 0.0);
  for (i = 0 ; i < 500 ; i++) {
    if (i > 1) {
      cng_current_color(0.0, 0.0, 0.0);
      if (i%2 == 0) { cng_circle(cx0,cy0,cra);}
      else {cng_circle(cx1,cy1,cra);}
      cng_current_color(0.0, 1.0, 0.0);
    }
    /* a droite ou a gauche */
    if ((cx+vx+cra > WSIZE) || (cx-abs(vx)-cra < 0)) vx = -vx;
    /* en bas ou en haut */
    if ((cy+vy+cra > HSIZE) || (cy-abs(vy)-cra < 0)) vy = -vy;
    /* mise a jour de la position du cercle */
    cx += vx; cy += vy;
    if (i%2 == 0) { cx0 = cx; cy0 = cy; }
    else { cx1 = cx; cy1 = cy; }
    /* affichage du cercle */
    cng_circle(cx,cy,cra);
    cng_swap_screen();
  }
  /* Recuperation du temps final */
  printf("Temps 2 : %f s\n", cng_get_time());

  cng_clear_screen();
  menu();

  return 0;
}

/* reproduction en RVB de l'ensemble des couleurs d'un feu */
int palette_feu(void)
{
  float feu[256][3];
  int i;
  float r, v, b;

  fprintf(stderr, "touche [b] pressee\n");

  cng_clear_screen();

  /* initialisation */
  for (i = 0 ; i < 256 ; i++) {
    feu[i][0] = 0.0; feu[i][1] = 0.0; feu[i][2] = 0.0;
  }

  /* du blanc au jaune */
  for (i = 0 ; i < 64 ; i++) {
    feu[i][0] = 1.0; feu[i][1] = 1.0; feu[i][2] = 1.0-(i/64.0);
  }

  /* du jaune a l'orange */
  for (i = 0 ; i < 64 ; i++) {
    feu[i+64][0] = 1.0; feu[i+64][1] = 1.0-(i/128.0); feu[i+64][2] = 0.0;
  }

  /* de l'orange au rouge */
  for (i = 0 ; i < 64 ; i++) {
    feu[i+128][0] = 1.0; feu[i+128][1] = 0.5-(i/128.0); feu[i+128][2] = 0.0;
  }

  /* du rouge au noir */
  for (i = 0 ; i < 64 ; i++) {
    feu[i+192][0] = 1.0-(i/64.0); feu[i+192][1] = 0.0; feu[i+192][2] = 0.0;
  }

  cng_clear_screen();
  /* affichage de la palette */
  for (i = 0 ; i < 256 ; i++) {
    cng_current_color(feu[i][0], feu[i][1], feu[i][2]);
    cng_line(0, i, WSIZE, i);
  }

  cng_get_pixel(100, 140, &r, &v, &b);
  fprintf(stderr, "couleur (%f, %f, %f)\n", r, v ,b);

  cng_swap_screen();

  cng_get_pixel(100, 140, &r, &v, &b);
  fprintf(stderr, "couleur (%f, %f, %f)\n", r, v ,b);

  /* attente de 4 s */
  cng_delay(4000);
  cng_clear_screen();
  menu();

  return 0;
}

/* premier essai d'une fonction associee a une touche clavier */
/* affichage de points, de segments et de cercles */
int touche_a(void)
{
  int i;

  fprintf(stderr, "touche [a] pressee\n");

  cng_clear_screen();

  cng_current_color(1.0, 1.0, 0);
  cng_line(0, (int)(HSIZE/10.0), WSIZE, (int)(HSIZE/10.0)); /* HLine */
  cng_line((int)(WSIZE/10.0), 0, (int)(WSIZE/10.0), HSIZE); /* VLine */

  cng_current_color(0.0, 1.0, 0);
  cng_circle((int)(WSIZE/10.0) + 50, (int)(HSIZE/10.0) + 50, 50); /* cercle */

  for(i = 0 ; i < 20 ; i++) {
    cng_put_pixel(32*i, 24*i);  /* point */
  }

  cng_swap_screen();

  cng_delay(2000);
  cng_clear_screen();
  menu();

  return 0;
}

/* affichage des coordonnees de la position du curseur souris */
int bouton_0(void)
{
  int x, y;
  char coord[20];

  fprintf(stderr, "Bouton 0 presse\n");

  x = cng_get_mouse_x();
  y = cng_get_mouse_y();
  /* construction de la chaine de caracteres */
  sprintf(coord, "(%d,%d)", x, y);
  cng_current_color(1.0, 1.0, 1.0);
  cng_draw_string(coord, x, y);
  cng_current_color(0.0, 0.0, 0.0);
  cng_swap_screen();

  return 0;
}

/* fonction de suivi graphique du mouvement du curseur souris */
int mon_depla(void)
{
  cng_current_color(1.0, 1.0, 0);
  cng_put_pixel(cng_get_mouse_x(), cng_get_mouse_y());
  cng_swap_screen();

  return 0;
}


int main(int argc, char** argv)
{
  /* creation de la fenetre graphique de taille WSIZE x HSIZE */
  cng_init_window(&argc, argv, "CNG Test", WSIZE, HSIZE);

  /* cng_video_info(); */
  cng_display_func(menu);
  /* association des touches a, b et c */
  cng_assoc_key(cng_a, touche_a);
  cng_assoc_key(cng_b, palette_feu);
  cng_assoc_key(cng_c, simple_animation);
  /* association du bouton 0 (i.e bouton gauche) */
  cng_assoc_button(0, bouton_0);
  /* association deplacement de la souris, bouton 0 appuye */
  cng_assoc_motion(mon_depla);

  cng_clear_screen();

  /* Main loop */
  cng_main_loop();

  /* liberation des ressources */
  cng_destroy_window();

  return EXIT_SUCCESS;
}
