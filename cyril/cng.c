/**************************************************************
 *
 *    CNG : Campus Naked Graphic
 *
 *    Copyright (c) 2008 Christian Nguyen
 *
 *    This program is free software; you can redistribute it 
 *    and/or modify it under the terms of the GNU General 
 *    Public License as published by the Free Software 
 *    Foundation (version 2 of the License).
 *
 *    This program is distributed in the hope that it will 
 *    be useful, but WITHOUT ANY WARRANTY; without even the 
 *    implied warranty of MERCHANTABILITY or FITNESS FOR A 
 *    PARTICULAR PURPOSE.  See the GNU General Public License 
 *    for more details.
 *
 *    For a copy of the GNU General Public License, write to the 
 *    Free Software Foundation, Inc., 675 Mass Ave, Cambridge, 
 *    MA 02139, USA.
 **************************************************************/

/**************************************************************
 *    Bibliotheque minimaliste s'appuyant sur OpenGL
 *    pour la realisation des TP d'infographie de 2ieme cycle
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "cng.h"

/**************************************************************
 * variables locales
 **************************************************************/

static int cur_x = 0, cur_y = 0; /* position courante */
static struct timeval start; /* mesure du temps ecoule */
static int left_click = GLUT_UP;
static int right_click = GLUT_UP;

/* les 26 lettres de l'alphabet */
static int (*touche[26])(void)={NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/* les 3 boutons de la souris */
static int (*bouton[3])(void)={NULL, NULL, NULL};

static int (*deplacement)(void)=NULL;

/**************************************************************
 * gestion de la fenetre graphique (initialisation, destruction, ...)
 **************************************************************/

/* definition de la fonction d'affichage */
void cng_display_func(void (*g)(void))
{
  glutDisplayFunc(g);
}

/* fonction appelee quand la fenetre est creee ou change de taille */
void ReshapeFunc (int width, int height)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity ();
  glOrtho(0, width, height, 0, -1, 1);
  glViewport (0, 0, width, height);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity ();
  glutPostRedisplay();
}

/* fonction appelee quand une touche du clavier est pressee */
void KeyboardFunc (unsigned char key, int x, int y)
{
  cur_x = x; cur_y = y; /* pas d'effet, evite simplement un warning */

  if (key >= 'a' && key <= 'z') {
      /* si la touche a ete affectee a une fonction */
      if (touche[key-'a'] != NULL) (*touche[key-'a'])();
  } else {
    if (key == 27) exit (0);
    else fprintf(stderr, "Touche non definie\n");
  }
}


/* fonction appelee quand un bouton (0 ou 2) de la souris est presse */
void MouseFunc (int button, int state, int x, int y)
{
  /* memorisation de la position du clic */
  cur_x = x;
  cur_y = y;

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    left_click = state;
    if (bouton[0] != NULL) (*bouton[0])();
  }
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    right_click = state;
    if (bouton[2] != NULL) (*bouton[2])();
  }
}

/* fonction appelee quand le curseur souris est deplace bouton 0 presse */
void MotionFunc (int x, int y)
{
  /* memorisation de la position du curseur */
  cur_x = x;
  cur_y = y;

  if (left_click == GLUT_DOWN) {
      if (deplacement != NULL) (*deplacement)();
  }
  /* if (right_click == GLUT_DOWN) { */
  /* } */
}

/* constructeur : nom de la fenetre et dimensions (largeur, hauteur) */
void cng_init_window(int* pargc, char** pargv, char *nom, int la, int ha)
{
  glutInit (pargc, pargv);
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize (la, ha);
  glutCreateWindow (nom);

  /* OpenGL settings */
  glClearColor (0, 0, 0, 0);

  /* Declaration of the callbacks */
  glutReshapeFunc (&ReshapeFunc);
  glutKeyboardFunc (&KeyboardFunc);
  glutMouseFunc (&MouseFunc);
  glutMotionFunc (&MotionFunc);
}

/* gestion manuelle du double buffer image */
void cng_swap_screen()
{
  glutSwapBuffers ();
  glutPostRedisplay ();
}

/* affiche sur stderr des informations sur l'environnement graphique */
void cng_video_info()
{
  int bpp = 0;
  int max_tex2d = 0;
  unsigned char rgba = 0;
  unsigned char index = 0;
  unsigned char double_buffer = 0;
  int max_index = 0;
  int max_vertex = 0;
  int texture_units = 0;

  glGetIntegerv (GL_SUBPIXEL_BITS, &bpp);
  glGetIntegerv (GL_MAX_TEXTURE_SIZE, &max_tex2d);
  glGetBooleanv (GL_RGBA_MODE, &rgba);
  glGetBooleanv (GL_INDEX_MODE, &index);
  glGetBooleanv (GL_DOUBLEBUFFER, &double_buffer);
  glGetIntegerv (GL_MAX_ELEMENTS_INDICES, &max_index);
  glGetIntegerv (GL_MAX_ELEMENTS_VERTICES, &max_vertex);
  glGetIntegerv (GL_MAX_TEXTURE_UNITS_ARB, &texture_units);

  printf ("OpenGL driver informations:\n");
  printf ("===========================\n\n");
  printf ("OpenGL version: %s\n", glGetString (GL_VERSION));
  printf ("Software implementation: %s\n", glGetString (GL_VENDOR));
  printf ("Renderer: %s\n\n", glGetString (GL_RENDERER));

  printf ("Double buffering: %s\n", (double_buffer ? "yes" : "no"));
  printf ("Bits per pixel: %d\n", bpp);
  printf ("RGBA color: %s\n", (rgba ? "yes" : "no"));
  printf ("Index color palette: %s\n\n", (index ? "yes" : "no"));

  printf ("Maximum 2D texture size: %d\n", max_tex2d);
  printf ("Maximum texture units: %d\n\n", texture_units);

  printf ("Maximum recommended index elements: %d\n", max_index);
  printf ("Maximum recommended vertex elements: %d\n", max_vertex);

  glutPostRedisplay ();
}

/* boucle d'attente des evenements */
void cng_main_loop()
{
  glutMainLoop ();
}

/* definition de la "idle function" */
void cng_idle_func(void (*g)(void))
{
  glutIdleFunc(g);
}

/* destructeur */
void cng_destroy_window()
{
}

/* efface l'ecran de travail */
void cng_clear_screen()
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* positionne la couleur dans laquelle on va dessiner
   code : r rouge, v vert et b bleu dans [0, 255] */
void cng_current_color(GLfloat r, GLfloat v, GLfloat b)
{
  /*GLfloat coul[4];*/

  glColor3f(r, v, b);
  /*glGetFloatv(GL_CURRENT_COLOR, coul);
  printf("[%.1f,%.1f,%.1f,%.1f]\n", coul[0], coul[1], coul[2], coul[3]);*/
}

/* Fonctions graphiques de base
   ======================================================== */

/* dessine un point de la couleur courante en (x, y) */
void cng_put_pixel(int x, int y)
{
  glBegin(GL_POINTS);
    glVertex2i(x, y);
  glEnd();
}

/* dessine une ligne de la couleur courante de (x1,y1) a (x2,y2) */
void cng_line(int x1, int y1, int x2, int y2)
{
  glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
  glEnd();

  /*glFlush();*/
}

/* dessine une ligne de la couleur courante de la position courante a (x,y) */
void cng_line_to(int x, int y)
{
  glBegin(GL_LINES);
    glVertex2i(cur_x, cur_y);
    glVertex2i(x, y);
  glEnd();
}

/* initialise la position courante */
void cng_move_to(int x, int y)
{
  cur_x = x;
  cur_y = y;
}

/* dessine le contour d'un cercle */
void cng_circle(int posx, int posy, int r)
{
  int i;
  float pi2 = 2.0 * M_PI;

  glPushMatrix();
  glTranslatef(posx, posy, 0.0);
  glBegin(GL_LINE_LOOP);
  for (i=0 ; i<100 ; i++) {
    glVertex2f(r * cos(i*pi2/100.0), r * sin(i*pi2/100.0));
  }
  glEnd();
  glPopMatrix();
}


/* Fonctions de gestion du texte
   ======================================================== */

/* affichage du texte a la position (x,y) */
void cng_draw_string(const char* texte, int x, int y)
{
  /*int len = strlen(texte);*/ /* Get the number of chars in the string */
  /* This will hold the place where to draw the next char */
/*   int xx = glutStrokeWidth(GLUT_STROKE_ROMAN, texte[i]); */

/*   glDisable(GL_TEXTURE_2D); */
  glDisable(GL_DEPTH_TEST);
  glRasterPos2f(x, y);

  glLineWidth(1.5);
  while (*texte)
    {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *texte);
      texte++;
    }
    /*glPushMatrix();
  glTranslatef(x, y, 0.0);
  glNormal3f(0,0,1);
  for(i=0 ; i<len ; i++)*/ /* Loop through all the chars in the string */
    /*{
      glutStrokeCharacter(GLUT_STROKE_ROMAN, texte[i]);*/
    /* Now we increase the xx printed string width counter by the width of the
       drawn character */
    /*glTranslatef(xx, 0.0, 0.0);*/
    /*}
  glPopMatrix();*/
/*   printf("WIDTH = %d\n", xx); */
  glEnable(GL_DEPTH_TEST);
}


/* Fonctions de gestion des E/S
   ======================================================== */

/* association d'une touche avec une fonction de la forme "int f()" */
void cng_assoc_key(touche_alpha k, int (*g)(void))
{
  touche[k] = g;
}

/* association d'un bouton (0, 1, 2) avec une fonction de la forme "int f()" */
void cng_assoc_button(int bid, int (*g)(void))
{
  bouton[bid] = g;
}

/* association du deplacement souris avec une fonction de la forme "int f()"
   ce deplacement se fait bouton 0 presse pour des raisons d'efficacite */
void cng_assoc_motion(int (*g)(void))
{
  deplacement = g;
}

/* retourne la position en X (resp. Y) du curseur de la souris */
int cng_get_mouse_x(void)
{
  return cur_x;
}

int cng_get_mouse_y(void)
{
  return cur_y;
}

/* Fonctions de traitement d'images
   ======================================================== */

/* recupere la couleur du pixel */
void cng_get_pixel(int x, int y, float* r, float* v, float* b)
{
  /* unsigned char coul[3]; */
/*   int codecoul = 0; */
/*   glGetIntegerv(GL_READ_BUFFER, &codecoul); */
/*   printf("%d (GL_BACK = %d)\n", codecoul, GL_BACK); */
  glReadBuffer(GL_BACK);
  glReadPixels(x, y, 1, 1, GL_RED, GL_FLOAT, r);
  glReadPixels(x, y, 1, 1, GL_GREEN, GL_FLOAT, v);
  glReadPixels(x, y, 1, 1, GL_BLUE, GL_FLOAT, b);

  /* glReadBuffer(GL_FRONT); */
/*   glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, coul); */
/*   printf("TEST : (%u, %u, %u)\n", coul[0], coul[1], coul[2]); */
}

/* recuperation du nombre de plan de l'ecran de travail */
int cng_get_bpp(void)
{
  return 0;
}

/* Fonctions diverses
   ======================================================== */

/* demarrage du chrono (mesure de temps) */
void cng_start_clock(void)
{
  gettimeofday(&start, NULL);
}

/* recuperation du temps en millisecondes (ms) */
double cng_get_time(void)
{
  struct timeval final;

  gettimeofday(&final, NULL);
  return (double)((final.tv_sec+final.tv_usec/1000000.0)-(start.tv_sec+start.tv_usec/1000000.0));
}

/* delais d'attente en millisecondes */
void cng_delay(int ms)
{
  struct timespec tmp;

  if (ms > 1000) {
    tmp.tv_sec = (int) floor(ms/1000.0);
    tmp.tv_nsec = (ms-tmp.tv_sec*1000)*1000000;
  } else {
    tmp.tv_sec = 0;
    tmp.tv_nsec = ms*1000000;
  }
  nanosleep(&tmp, NULL);
}
