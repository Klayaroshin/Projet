#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){
    int pointsDeVieJoueur = 100;
	int pointsDeVieMonstre = 100;
	int attaqueJoueur = 10;
	int attaqueMonstre = 10;
	int contreAttaque = 0;
	int decisionJoueur = 0;
	int decisionMonstre = 0;
	int PointsDeManaJoueur = 10;
	int PointsDeManaMonstre = 10;
	int poisonJoueur = 0;
	int poisonMonstre = 0;
	int antidote = 0;
	
	srand(time(NULL));

	while(pointsDeVieMonstre>0 && pointsDeVieJoueur>0){
		printf ("Voulez vous attaquer (1), vous defendre (2) ou empoisonner le monstre (3) ou bien utiliser l'antidote (4) ? \n");
		scanf("%d",&decisionJoueur);
		decisionMonstre =((rand()%3)+1);
		
		if (decisionJoueur == 4){
			printf("Vous utilisez votre antidote, vous n'etes plus empoisonne");
			poisonMonstre = 0;
		}
			
		if (decisionJoueur == 3 && PointsDeManaJoueur>=3){
			printf("Vous empoisonnez le monstre.\n");
			poisonJoueur ++;
			PointsDeManaJoueur = PointsDeManaJoueur -3;
			if(decisionJoueur == 3 && PointsDeManaJoueur<3){
				printf ("Vous n'avez plus de mana et vous ne pouvez empoisonner le monstre. \n");
				printf ("Voulez vous attaquer (1) ou vous vous defendre (2) .\n");
				scanf("%d",&decisionJoueur);
			}
		}
		
		
		if (decisionMonstre == 3 && PointsDeManaMonstre>=3){
			printf("Le monstre vous empoisonne. \n");
			poisonMonstre ++;
			PointsDeManaMonstre = PointsDeManaMonstre -3;
			if(decisionMonstre == 3 && PointsDeManaMonstre<3){
				(decisionMonstre =((rand()%2)+1));
			}
		}
		
			
		if (decisionMonstre == 2){
			printf("Le monstre se defend.\n");
			attaqueJoueur = attaqueJoueur/4;
				
		}
		
		if (decisionJoueur == 2){
			printf("Vous avez decide de vous defendre.\n");
			attaqueMonstre = attaqueMonstre/4;
			
		}
		
		if(decisionJoueur == 1){
			printf("Vous decidez de l'attaquer. \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueJoueur;
			
			}
		
		if(decisionMonstre == 1){
			printf("Le monstre vous attaque. \n");
			pointsDeVieJoueur = pointsDeVieJoueur - attaqueMonstre;
			
		}
	
	if(poisonJoueur >= 1){
		pointsDeVieMonstre = pointsDeVieMonstre - poisonJoueur;
	}
	if(poisonMonstre >= 1){
		pointsDeVieJoueur = pointsDeVieJoueur - poisonMonstre;
	}
		
		
	if (PointsDeManaJoueur<10){
		PointsDeManaJoueur++;
	}
	
	if (PointsDeManaMonstre<10){
		PointsDeManaMonstre++;
	}
	
	printf ("Il vous reste %d points de mana.\n", PointsDeManaJoueur);
	printf ("Le monstre a %d points de vie.\n", pointsDeVieMonstre);
	printf ("Il vous reste %d points de vie.\n", pointsDeVieJoueur);
	
	attaqueMonstre = 11;
	attaqueJoueur = 10;
	
		
	}	
	
	
	


	return 0;
}
