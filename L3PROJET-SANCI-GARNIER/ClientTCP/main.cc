#include "CPossiblePath.h"
#include "CElite.h"
#include "CClientTCP.h"
#include "CGene.h"
#include "CGeneList.h"
#include "CChromosome.h"
#include "CDistance.h"
#include <iostream>

using namespace std;

int main()
{


    int nbCity=10;

    CGeneList cityList(nbCity); // Création des villes + Init de leur position (hauteur , largeur)
    CDistance km(cityList); // Km devra contenir les distances entre chaque ville de la cityList
    CPossiblePath pathList(20,nbCity); // on crée la liste qui contiendra tout les chemins générés aléatoirement
    CElite bestPath(10,pathList,km);  // Calcul et traitement de tous les élites

    for (int z=0;z<1000;z++){
        CElite bestPath(10,pathList,km); // Calcul des élites a chaque itération
        bestPath.mute(pathList,km); // Mutation des élites 
        bestPath.injection(pathList); // Injection de ces élites au sein d'une génération N+1
        bestPath.crossing(pathList,km); // on permute des éléments des élites avec la nouvelle population
    }

    CElite end(10,pathList,km); // Calcul des élites pour avoir le meilleur en premiere position (Pos 0 = Best elite)

    CClientTCP client("127.0.0.1",15500); // On se connecte au serveur d'affichage 

    int x1,y1,x2,y2,tempx,tempy,cityNumber; // (x1, y1) et (x2, y2) seront les coordonnées utilisées pour relier les villes
 

    CChromosome best; // best contient le meilleur chemin
    best=pathList.getList(end.getPathElite(0));

    CGene city;
    
    cityList.print();
    pathList.print();

    for(int i=0;i<nbCity-1;i++){ 
		
        cityNumber=best.getPath(i); // on releve l'indice de la premiere ville
        city=cityList.getGene(cityNumber);

        x1=city.getCoordx(); // on releve les coordonnées de la premiere ville
        y1=city.getCoordy();

        if(i==0){ // on sauvegarde les coordonnées de la premiere ville
            tempx=x1;
            tempy=y1;
        }

        client.drawPoint(x1,y1,CColor::sGreen); // On trace un point =  ville

        cityNumber=best.getPath(i+1); // on prend l'indice de la ville suivante
        city=cityList.getGene(cityNumber);
        x2=city.getCoordx(); // on releve les coordonnées de la ville suivante
        y2=city.getCoordy();

        client.drawSegment( x1, y1, x2, y2, CColor::sRed ); // Traçage du segment reliant 2 villes
    }

    client.drawSegment( x2, y2, tempx, tempy, CColor::sRed ); // Traçage du segment qui relie la premiere et la derniere ville

    return 0;
}
