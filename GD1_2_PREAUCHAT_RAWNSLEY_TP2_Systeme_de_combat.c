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

  int xpMage = 0;
  int xpTank = 0;
  int xpSoigneur = 0;
  int xpJoueur = 0;

  int lvlMage = 0;
  int lvlTank = 0;
  int lvlSoigneur = 0;
  int lvlJoueur = 0;


	srand(time(NULL));

    // Boucle qui va répéter les combats jusqu'à ce que le monstre, le tank, le soigneur où le joueur meurt
	while((pointsDeVieMonstre >0 || pvMonstre2 > 0) && (pvTank>0 || pvSoigneur>0 || pointsDeVieJoueur>0 || pointsDeVieMage>0)){

    if (pointsDeVieJoueur>0){
		printf ("\n C'est au tour de Joueur 1. \n Effectuez l'action a realiser \n \n Voulez vous attaquer Monstre 1 (1) \n Vous defendre (2) \n Empoisonner le monstre 1 (3) \n Utiliser l'antidote (4) \n Attaquer Monstre 2 (5)\n");
		scanf("%d",&decisionJoueur);
    }
    else{
      printf("Joueur 1 est Mort et ne peut plus attaquer\n");
    }

    if (pvTank>0){
		printf ("\n C'est au tour du Tank. \n Effectuez l'action a realiser \n \n Voulez vous attaquer Monstre 1 (1) \n Vous defendre et aggro le monstre1 et monstre2 (2) \n Attaquer Monstre 2 (3)\n");
		scanf("%d",&decisionTank);
    }
    else{
      printf("Le Tank est mort et ne peut plus tanker\n");
    }

    if (pvSoigneur>0){
		printf ("\n C'est au tour du Soigneur. \n Effectuez l'action a realiser \n \n Voulez vous soigner Joueur (1) \n Voulez vous soigner Tank (2) \n Vous soigner vous meme (3) \n Soigner le Mage (4) \n");
		scanf("%d",&decisionSoigneur);
    }
    else{
      printf("Le Soigneur est mort et ne peut plus soigner\n");
    }


    if (pointsDeVieMage>0){
    printf ("\n C'est au tour du Mage. \n Effectuez l'action a realiser \n \n Voulez vous lancer une boule de feu sur Monstre 1 (1) \n Vous defendre (2) \n Attaquer Monstre 2 (3)\n");
		scanf("%d",&decisionMage);
    }
    else{
      printf("Le Mage est Mort et ne peut plus attaquer\n");
    }



    if (pointsDeVieMage>0){
    printf ("\n C'est au tour du Mage. \n Effectuez l'action a realiser \n \n Voulez vous lancer une boule de feu sur Monstre 1 (1) \n Vous defendre (2) \n Attaquer Monstre 2 (3)\n");
		scanf("%d",&decisionMage);
    }
    else{
      printf("Le Mage est Mort et ne peut plus attaquer\n");
    }


        // Affecte une valeur aléatoire pour déterminer la décision des monstres
    if (pointsDeVieMonstre>0){
  		decisionMonstre = ((rand()%3)+1);
  		decisionMonstreAttaque = ((rand()%4)+1);
    }
    else{
      printf("Le monstre 1 est mort et ne peut plus attaquer\n");
      decisionMonstre = 0;
    }

    if (pvMonstre2>0){
      decisionMonstre2 = ((rand()%2)+1);
      decisionMonstre2Attaque = ((rand()%4)+1);
    }
    else{
      printf("Le monstre 2 est mort et ne peut plus attaquer\n");
      decisionMonstre2 = 0;
    }

        // DECISIONS DU JOUEUR

        // Attaque Monstre 1
		if(decisionJoueur == 1){
			printf("\nJoueur 1 attaque le monstre \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueJoueur;
      xpJoueur += 10;
        }

        // Défense, divise par 4 les dégats
		if (decisionJoueur == 2){
			printf("Joueur1 se défend.\n");
			attaqueMonstre = attaqueMonstre/4;
      xpJoueur =+ 5;

		}

        // Empoisonnement, vérifie que le Joueur ait bien 4 de mana
		if (decisionJoueur == 3 && PointsDeManaJoueur>=4){
			printf("Joueur1 empoisonne le monstre 1.\n");
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
      xpJoueur =+ 2;
		}

        // Attaque Monstre 2
    if(decisionJoueur == 5){
			printf("\nJoueur 1 attaque le monstre 2 \n");
			pvMonstre2 = pvMonstre2 - attaqueJoueur;

      xpJoueur += 10;


    }

		// DECISIONS DU TANK

    // Attaque Tank sur monstre 1
		if(decisionTank == 1){
			printf("\nTank attaque le monstre. \n");
			pointsDeVieMonstre = pointsDeVieMonstre - attaqueTank;

      xpTank += 10;


    }

	    // Défense du Tank, degats divisé par 6
		if (decisionTank == 2){
			printf("Tank se defend et prend l'aggro.\n");
			attaqueMonstre = attaqueMonstre/6;
      decisionMonstreAttaque = 2;
      decisionMonstre2Attaque = 2;

      xpTank += 5;


		}

    // Attaque Tank sur monstre 2
		if(decisionTank == 3){
			printf("\nTank attaque le monstre2. \n");
			pvMonstre2 = pvMonstre2 - attaqueTank;

      xpTank += 10;


    }
    //DECISIONS DU MAGE

    // Attaque mage
    if(decisionMage == 1){
      printf("\nMage lance une boue de feu. \n");
      pointsDeVieMonstre = pointsDeVieMonstre - attaqueMage;

      xpMage += 10;


      }

      // Défense du Tank, degats divisé par 6
      if (decisionMage == 2){
        printf("Mage se defend.\n");
        attaqueMonstre = attaqueMonstre/2;

        xpMage += 5;


      }

      // Attaque mage
      if(decisionMage == 3){
        printf("\nMage lance une boue de feu sur Monstre 2. \n");
        pvMonstre2 = pvMonstre2 - attaqueMage;

        xpMage += 10;


      }

		// DECISIONS DU SOIGNEUR

        // Soin Joueur
		if(decisionSoigneur == 1){
			printf("\nSoigneur soigne Joueur 1. \n");
			pointsDeVieJoueur = pointsDeVieJoueur + soin;
      xpSoigneur += 10;
    }

	    // Soin Tank
		if (decisionSoigneur == 2){
			printf("Soigneur soigne Tank.\n");
			pvTank = pvTank + soin;
      xpSoigneur += 10;
		}

    // Soin Soigneur
  if (decisionSoigneur == 3){
    printf("Soigneur se soigne lui meme.\n");
    pvSoigneur = pvSoigneur + soin;
    xpSoigneur += 10;
  }

    // Soin Soigneur
  if (decisionSoigneur == 4){
    printf("Soigneur soigne le Mage.\n");
    pointsDeVieMage = pointsDeVieMage + soin;
    xpSoigneur += 10;
  }

    // Soin Soigneur
  if (decisionSoigneur == 4){
    printf("Soigneur soigne le Mage.\n");
    pointsDeVieMage = pointsDeVieMage + soin;
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


        // Affichage xp et lvl à la fin d'un attaqueJoueur
        printf ("Mage a gagne %d xp. \n", xpMage);
        printf ("Tank a gagne %d xp. \n", xpTank);
        printf ("Soigneur a gagne %d xp. \n", xpSoigneur);
        printf ("Joueur1 a gagne %d xp. \n", xpJoueur);

        if (xpMage >=20){
          lvlMage++;
          xpMage -=20;
            printf ("Mage est maintenant lvl %d. \n", lvlMage);
        }

        if (xpTank >=20){
          lvlTank++;
          xpTank -=20;
            printf ("Tank est maintenant lvl %d. \n", lvlTank);
        }

        if (xpSoigneur >=20){
          lvlSoigneur++;
          xpSoigneur -=20;
            printf ("Soigneur est maintenant lvl %d. \n", lvlSoigneur);
        }

        if (xpJoueur >=20){
          lvlJoueur++;
          xpJoueur -=20;
            printf ("Joueur est maintenant lvl %d. \n", lvlJoueur);
        }





        // Victoire ou Défaite

        if (pointsDeVieMonstre<0  && pvMonstre2<0){
            printf("\nVous avez Vaincu les monstres ! \n");
        }

        if (pvTank<0 && pvSoigneur<0 && pointsDeVieJoueur<0 && pointsDeVieMage<0){
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
