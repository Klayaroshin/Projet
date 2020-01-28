#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){

    // VARIABLES
  int pvTank = 200;
	int attaqueTank = 8;
	int decisionTank = 0;

  int pvSoigneur = 200;
	int soin = 8;
	int decisionSoigneur = 0;

  int pointsDeVieMage = 50;
  int attaqueMage = 16;
  int decisionMage = 0;

  int pvMonstre2 = 150;
  int decisionMonstre2 = 0;
  int decisionMonstre2Attaque = 0;
  int attaqueMonstre2 = 25;

	int attaqueJoueur = 14;
  int pointsDeVieJoueur = 100;
	int PointsDeManaJoueur = 10;
	int poisonJoueur = 0;
	int decisionJoueur = 0;

	int pointsDeVieMonstre = 300;
	int attaqueMonstre = 20;
	int decisionMonstre = 0;
	int PointsDeManaMonstre = 10;
	int decisionMonstreAttaque = 0;

	int poisonMonstreJoueur = 0;
	int poisonMonstreTank = 0;
  int poisonMonstreSoigneur = 0;
  int poisonMonstreMage = 0;

	srand(time(NULL));

    // Boucle qui va répéter les combats jusqu'à ce que le monstre, le tank, le soigneur où le joueur meurt
	while(pointsDeVieMonstre >0 && pvMonstre2 > 0){
		printf ("\n C'est au tour de Joueur 1. \n Effectuez l'action a realiser \n \n Voulez vous attaquer Monstre 1 (1) \n Vous defendre (2) \n Empoisonner le monstre (3) \n Utiliser l'antidote (4) \n Attaquer Monstre 2 (5)\n");
		scanf("%d",&decisionJoueur);

		printf ("\n C'est au tour du Tank. \n Effectuez l'action a realiser \n \n Voulez vous attaquer Monstre 1 (1) \n Vous defendre et aggro le monstre1 et monstre2(2) \n Attaquer Monstre 2 (3)\n");
		scanf("%d",&decisionTank);

		printf ("\n C'est au tour du Soigneur. \n Effectuez l'action a realiser \n \n Voulez vous soigner Joueur (1) \n Voulez vous soigner Tank (2) \n Vous soigner vous meme (3) \n");
		scanf("%d",&decisionSoigneur);

    printf ("\n C'est au tour du Mage. \n Effectuez l'action a realiser \n \n Voulez vous lancer une boule de feu sur Monstre 1 (1) \n Vous defendre (2) \n Attaquer Monstre 2 (3)\n");
		scanf("%d",&decisionMage);

        // Affecte une valeur aléatoire pour déterminer la décision des monstres
		decisionMonstre = ((rand()%3)+1);
		decisionMonstreAttaque = ((rand()%4)+1);
    decisionMonstre2 = ((rand()%2)+1);
    decisionMonstre2Attaque = ((rand()%4)+1);

        // DECISIONS DU JOUEUR

        // Attaque Monstre 1
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

        // Attaque Monstre 2
    if(decisionJoueur == 5){
			printf("\nJoueur 1 attaque le monstre 2 \n");
			pvMonstre2 = pvMonstre2 - attaqueJoueur;
    }

		// DECISIONS DU TANK

    // Attaque Tank sur monstre 1
		if(decisionTank == 1){
			printf("\nTank attaque le monstre. \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueTank;
    }

	    // Défense du Tank, degats divisé par 6
		if (decisionTank == 2){
			printf("Tank se defend et prend l'aggro du monstre.\n");
			attaqueMonstre = attaqueMonstre/6;
      decisionMonstreAttaque = 2;
      decisionMonstre2Attaque = 2;
		}

    // Attaque Tank sur monstre 2
		if(decisionTank == 3){
			printf("\nTank attaque le monstre2. \n");
			pvMonstre2 = pvMonstre2 - attaqueTank;
    }
    //DECISIONS DU MAGE

    // Attaque mage
    if(decisionMage == 1){
      printf("\nMage lance une boue de feu. \n");
      pointsDeVieMonstre = pointsDeVieMonstre - attaqueMage;
      }

      // Défense du Tank, degats divisé par 6
      if (decisionMage == 2){
        printf("Mage se defend.\n");
        attaqueMonstre = attaqueMonstre/2;
      }

      // Attaque mage
      if(decisionMage == 3){
        printf("\nMage lance une boue de feu sur Monstre 2. \n");
        pvMonstre2 = pvMonstre2 - attaqueMage;
      }

		// DECISIONS DU SOIGNEUR

        // Soin Joueur
		if(decisionSoigneur == 1){
			printf("\nSoigneur soigne Joueur 1. \n");
			pointsDeVieJoueur = pointsDeVieJoueur + soin;
    }

	    // Soin Tank
		if (decisionSoigneur == 2){
			printf("Soigneur soigne Tank.\n");
			pvTank = pvTank + soin;
		}

    // Soin Soigneur
  if (decisionSoigneur == 3){
    printf("Soigneur se soigne lui meme.\n");
    pvSoigneur = pvSoigneur + soin;
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


    // Attaque contre Soigneur
		if(decisionMonstre == 1 && decisionMonstreAttaque == 3){
			printf("Le monstre attaque Soigneur. \n");
			pvSoigneur = pvSoigneur - attaqueMonstre;
		}

    // Attaque contre Mage
    if(decisionMonstre == 1 && decisionMonstreAttaque == 4){
      printf("Le monstre attaque Mage. \n");
      pointsDeVieMage = pointsDeVieMage - attaqueMonstre;
    }

        // Défense
		if (decisionMonstre == 2){
			printf("Le monstre se defend.\n");
			attaqueJoueur = attaqueJoueur/4;
      attaqueTank = attaqueTank/4;
      attaqueMage = attaqueMage/4;
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

    // Empoisonnement Soigneur
    if (decisionMonstre == 3 && PointsDeManaMonstre>=4 && decisionMonstreAttaque ==3){
      printf("Le monstre empoisonne Soigneur. \n");
      poisonMonstreSoigneur = poisonMonstreSoigneur +4;
      PointsDeManaMonstre = PointsDeManaMonstre -4;
      if(decisionMonstre == 3 && PointsDeManaMonstre<3){
        (decisionMonstre =((rand()%2)+1));
      }
    }

    // Empoisonnement Mage
    if (decisionMonstre == 3 && PointsDeManaMonstre>=4 && decisionMonstreAttaque ==4){
      printf("Le monstre empoisonne Mage. \n");
      poisonMonstreMage = poisonMonstreMage +4;
      PointsDeManaMonstre = PointsDeManaMonstre -4;
      if(decisionMonstre == 3 && PointsDeManaMonstre<3){
        (decisionMonstre =((rand()%2)+1));
      }
    }

    // DECISIONS AUTOMATIQUES DU MONSTRE 2

  // Attaque contre Joueur1
  if(decisionMonstre2 == 1 && decisionMonstre2Attaque == 1){
    printf("Le monstre2 attaque Joueur1. \n");
    pointsDeVieJoueur = pointsDeVieJoueur - attaqueMonstre2;
  }

  // Attaque contre Tank
  if(decisionMonstre2 == 1 && decisionMonstre2Attaque == 2){
    printf("Le monstre2 attaque Tank. \n");
    pvTank = pvTank - attaqueMonstre2;
  }


  // Attaque contre Soigneur
  if(decisionMonstre2 == 1 && decisionMonstre2Attaque == 3){
    printf("Le monstre2 attaque Soigneur. \n");
    pvSoigneur = pvSoigneur - attaqueMonstre2;
    }

  // Attaque contre Mage
  if(decisionMonstre2 == 1 && decisionMonstre2Attaque == 4){
    printf("Le monstre2 attaque Mage. \n");
    pointsDeVieMage = pointsDeVieMage - attaqueMonstre2;
  }

      // Défense
  if (decisionMonstre2 == 2){
    printf("Le monstre2 se defend.\n");
    attaqueJoueur = attaqueJoueur/4;
    attaqueTank = attaqueTank/4;
    attaqueMage = attaqueMage/4;
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

        if (poisonMonstreSoigneur >= 1){
            pvSoigneur = pvSoigneur - poisonMonstreSoigneur;
        }

        if (poisonMonstreMage >= 1){
            pointsDeVieMage = pointsDeVieMage - poisonMonstreMage;
        }

        // Restauration des points de mana Joueur et Monstre.

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
        printf ("Le Soigneur a %d points de vie. \n", pvSoigneur);
        printf ("Le Mage a %d points de vie. \n", pointsDeVieMage);
        printf ("Il reste %d points de vie au monstre1. \n", pointsDeVieMonstre);
        printf ("Il reste %d points de vie au monstre2. \n", pvMonstre2);

        // Victoire ou Défaite

        if (pointsDeVieMonstre<0  && pvMonstre2<0){
            printf("\nVous avez Vaincu les monstres ! \n");
        }

        if (pointsDeVieJoueur<=0){
            printf("\nC'est la mort ! \n");
        }

        // Rénitialisation des variables d'attaque
        attaqueJoueur = 14;
	      attaqueMonstre = 20;
        attaqueMonstre2 = 25;
        attaqueTank = 8;
        attaqueMage = 16;

    }
	return 0;
}
