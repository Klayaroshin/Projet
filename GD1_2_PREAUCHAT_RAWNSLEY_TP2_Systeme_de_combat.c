#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){
    
    // VARIABLES
    int pvTank = 200;
	int attaqueTank = 8;
	int decisionTank = 0;
	
    int pointsDeVieJoueur = 100;
	int pointsDeVieMonstre = 100;
	int attaqueJoueur = 14;
	int attaqueMonstre = 20;
	int decisionJoueur = 0;
	int decisionMonstre = 0;
	int PointsDeManaJoueur = 10;
	int PointsDeManaMonstre = 10;
	int poisonJoueur = 0;
	int poisonMonstreJoueur = 0;
	int poisonMonstreTank = 0;
	int decisionMonstreAttaque = 0;
	
	srand(time(NULL));

    // Boucle qui va répéter les combats jusqu'à ce que le monstre où le joueur meurt
	while(pointsDeVieMonstre>0 && pointsDeVieJoueur>0 && pvTank>0){
		printf ("\n C'est au tour de Joueur 1. \n Effectuez l'action a realiser \n \n Voulez vous attaquer (1) \n Vous defendre (2) \n Empoisonner le monstre (3) \n Utiliser l'antidote (4) \n");
		scanf("%d",&decisionJoueur);
		printf ("\n C'est au tour du Tank. \n Effectuez l'action a realiser \n \n Voulez vous attaquer (1) \n Vous defendre (2) \n");
		scanf("%d",&decisionTank);
	
        // Affecte une valeur aléatoire pour déterminer la décision du monstre
		decisionMonstre =((rand()%3)+1);
		decisionMonstreAttaque = ((rand()%2)+1);
        
        // DECISIONS DU JOUEUR
        
        // Attaque
		if(decisionJoueur == 1){
			printf("\nJoueur 1 attaque le monstre \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueJoueur;
        }
        
        // Défense, divise par 4 les dégats
		if (decisionJoueur == 2){
			printf("Joueur1 se défend.\n");
			attaqueMonstre = attaqueMonstre/4;
			
		}
        
        // Empoisonnement, vérifie que le Joueur ait bien 4 de mana
		if (decisionJoueur == 3 && PointsDeManaJoueur>=4){
			printf("Joueur1 empoisonne le monstre.\n");
			poisonJoueur = poisonJoueur +4;
			PointsDeManaJoueur = PointsDeManaJoueur -4;
            // Si le joueur n'a pas assez de mana, redemande l'action a effectuer
			if(decisionJoueur == 3 && PointsDeManaJoueur<4){
				printf ("Joueur1 n'a plus de mana, il ne peut empoisonner le monstre. \n");
				printf ("Voulez vous attaquer (1) \n Vous vous defendre (2) \n");
				scanf("%d",&decisionJoueur);
			}
		}
        
        // Utilisation Antidote
		if (decisionJoueur == 4){
			printf("Vous avez utilise votre antidote et vous n'etes plus empoisonne \n");
			poisonMonstreJoueur = 0;
		}
			
		// DECISIONS DU TANK
        
        // Attaque Tank
		if(decisionTank == 1){
			printf("\nTank attaque le monstre. \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueTank;
        }
	
	    // Défense du Tank, degats divisé par 6
		if (decisionTank == 2){
			printf("Tank se défend.\n");
			attaqueMonstre = attaqueMonstre/6;
			
		}
        // DECISIONS AUTOMATIQUES DU MONSTRE
        
        // Attaque contre Joueur1
        if(decisionMonstre == 1 && decisionMonstreAttaque == 1){
			printf("Le monstre attaque Joueur1. \n");
			pointsDeVieJoueur = pointsDeVieJoueur - attaqueMonstre;
		}
          
		// Attaque contre Tank
		if(decisionMonstre == 1 && decisionMonstreAttaque == 2){
			printf("Le monstre attaque Tank. \n");
			pvTank = pvTank - attaqueMonstre;
		}
		
        // Défense
		if (decisionMonstre == 2){
			printf("Le monstre se defend.\n");
			attaqueJoueur = attaqueJoueur/4;	
		}
        
        // Empoisonnement Joueur1
		if (decisionMonstre == 3 && PointsDeManaMonstre>=4 && decisionMonstreAttaque ==1){
			printf("Le monstre empoisonne Joueur1. \n");
			poisonMonstreJoueur = poisonMonstreJoueur +4;
			PointsDeManaMonstre = PointsDeManaMonstre -4;
			if(decisionMonstre == 3 && PointsDeManaMonstre<3){
				(decisionMonstre =((rand()%2)+1));
			}
		}
		
        // Empoisonnement Tank
		if (decisionMonstre == 3 && PointsDeManaMonstre>=4 && decisionMonstreAttaque ==2){
			printf("Le monstre empoisonne Tank. \n");
			poisonMonstreTank = poisonMonstreTank +4;
			PointsDeManaMonstre = PointsDeManaMonstre -4;
			if(decisionMonstre == 3 && PointsDeManaMonstre<3){
				(decisionMonstre =((rand()%2)+1));
			}
		}
        
        // Enclenchement des dégats du poison Joueur et Monstre
        
        if (poisonJoueur >= 1){
            pointsDeVieMonstre = pointsDeVieMonstre - poisonJoueur;
        }
        if (poisonMonstreJoueur >= 1){
            pointsDeVieJoueur = pointsDeVieJoueur - poisonMonstreJoueur;
        }
		
        if (poisonMonstreTank >= 1){
            pvTank = pvTank - poisonMonstreTank;
        }
        // Restauration des points de mana Joueur et Monstre
        
        if (PointsDeManaJoueur<10){
            PointsDeManaJoueur++;
        }

        if (PointsDeManaMonstre<10){
            PointsDeManaMonstre++;
        }

        // Affichage des statistiques a la fin d'un tour
        printf ("Le joueur1 a %d points de mana. \n", PointsDeManaJoueur);
        printf ("Le joueur1 a %d points de vie. \n", pointsDeVieJoueur);
        printf ("Le Tank a %d points de vie. \n", pvTank);
        printf ("Il reste %d points de vie au monstre. \n", pointsDeVieMonstre);
        
        // Victoire ou Défaite
        
        if (pointsDeVieMonstre<=0){
            printf("\nVous avez Vaincu le monstre ! \n");
        }

        if (pointsDeVieJoueur<=0){
            printf("\nVous etes mort ! \n");
        }
        
        // Rénitialisation des variables d'attaque
        attaqueJoueur = 14;
	    attaqueMonstre = 20;
		
    }	
	return 0;
}
