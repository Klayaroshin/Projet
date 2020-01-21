#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){
    
    // VARIABLES
    
    int pointsDeVieJoueur = 100;
	int pointsDeVieMonstre = 100;
	int attaqueJoueur = 14;
	int attaqueMonstre = 20;
	int decisionJoueur = 0;
	int decisionMonstre = 0;
	int PointsDeManaJoueur = 10;
	int PointsDeManaMonstre = 10;
	int poisonJoueur = 0;
	int poisonMonstre = 0;
	
	srand(time(NULL));

    // Boucle qui va répéter les combats jusqu'à ce que le monstre où le joueur meurt
	while(pointsDeVieMonstre>0 && pointsDeVieJoueur>0){
		printf ("\n Effectuez l'action a realiser \n \n Voulez vous attaquer (1) \n Vous defendre (2) \n Empoisonner le monstre (3) \n Utiliser l'antidote (4) \n");
		scanf("%d",&decisionJoueur);
        // Affecte une valeur aléatoire pour déterminer la décision du monstre
		decisionMonstre =((rand()%3)+1);
        
        // DECISIONS DU JOUEUR
        
        // Attaque
		if(decisionJoueur == 1){
			printf("\nVous decidez d'attaquer le monstre. \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueJoueur;
        }
        
        // Défense, divise par 4 les dégats
		if (decisionJoueur == 2){
			printf("Vous avez decide de vous defendre.\n");
			attaqueMonstre = attaqueMonstre/4;
			
		}
        
        // Empoisonnement, vérifie que le Joueur ait bien 4 de mana 
		if (decisionJoueur == 3 && PointsDeManaJoueur>=4){
			printf("Vous empoisonnez le monstre.\n");
			poisonJoueur = poisonJoueur +4;
			PointsDeManaJoueur = PointsDeManaJoueur -4;
            // Si le joueur n'a pas assez de mana, redemande l'action a effectuer
			if(decisionJoueur == 3 && PointsDeManaJoueur<4){
				printf ("Vous n'avez plus de mana et vous ne pouvez empoisonner le monstre. \n");
				printf ("Voulez vous attaquer (1) \n Vous vous defendre (2) \n");
				scanf("%d",&decisionJoueur);
			}
		}
        
        // Utilisation Antidote
		if (decisionJoueur == 4){
			printf("Vous avez utilise votre antidote et vous n'etes plus empoisonne \n");
			poisonMonstre = 0;
		}
			
	
        // DECISIONS AUTOMATIQUES DU MONSTRE
        
        // Attaque
        if(decisionMonstre == 1){
			printf("Le monstre vous attaque. \n");
			pointsDeVieJoueur = pointsDeVieJoueur - attaqueMonstre;
		}
        
        // Défense
		if (decisionMonstre == 2){
			printf("Le monstre se defend.\n");
			attaqueJoueur = attaqueJoueur/4;	
		}
        
        // Empoisonnement
		if (decisionMonstre == 3 && PointsDeManaMonstre>=4){
			printf("Le monstre vous empoisonne. \n");
			poisonMonstre = poisonMonstre +4;
			PointsDeManaMonstre = PointsDeManaMonstre -4;
			if(decisionMonstre == 3 && PointsDeManaMonstre<3){
				(decisionMonstre =((rand()%2)+1));
			}
		}
        
        // Enclenchement des dégats du poison Joueur et Monstre
        
        if (poisonJoueur >= 1){
            pointsDeVieMonstre = pointsDeVieMonstre - poisonJoueur;
        }
        if (poisonMonstre >= 1){
            pointsDeVieJoueur = pointsDeVieJoueur - poisonMonstre;
        }

        // Restauration des points de mana Joueur et Monstre
        
        if (PointsDeManaJoueur<10){
            PointsDeManaJoueur++;
        }

        if (PointsDeManaMonstre<10){
            PointsDeManaMonstre++;
        }

        // Affichage des statistiques a la fin d'un tour
        printf ("Vous avez %d points de mana. \n", PointsDeManaJoueur);
        printf ("Vous avez %d points de vie. \n", pointsDeVieJoueur);
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
