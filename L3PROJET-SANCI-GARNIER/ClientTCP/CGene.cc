#include "CGene.h"
#include <cstdlib>
#include <iostream>

#define HAUTEUR 800
#define LARGEUR 800

using namespace std;

int static x=5000;

// Constructeur

CGene::CGene(){
    m_Num=0;
    m_Coordx=0;
    m_Coordy=0;
}

CGene::CGene(int pNum){

	// ce constructeur donne une position aléatoire aux villes.

    m_Num=pNum;
    srand(time(NULL)*x);
    m_Coordx=rand()%LARGEUR;
    x++;
    srand(time(NULL)*x);
    m_Coordy=rand()%HAUTEUR;
    x++;
}

//destructeur

CGene::~CGene(){
}

// Methodes

int CGene::getNum() //accesseur
{
    return m_Num;
}

int CGene::getCoordx() //accesseur
{
    return m_Coordx;
}

int CGene::getCoordy() //accesseur
{
    return m_Coordy;
}

void CGene::print() // afficheur
{
    cout<<"Ville n°"<<m_Num<<endl;
    cout<<"x:"<<m_Coordx<<"    y:"<<m_Coordy<<endl;
}
































