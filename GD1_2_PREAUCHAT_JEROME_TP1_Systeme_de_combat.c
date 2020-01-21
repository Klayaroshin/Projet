#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){
	int pvmonstre = 100;
	int attaquejoueur = 10;
	int pvjoueur = 100;
	int attaquemonstre = 10;
	int contreAttaque = 0;
	int decisionJ = 0;
	int decisionM = 0;
	int PM = 10;
	int PMmonstre = 10;
	int poisonJ = 0;
	int poisonM = 0;
	int antidote = 0;
	
	srand(time(NULL));

	while(pvmonstre>0 && pvjoueur>0){
		printf ("Voulez vous attaquer (1) ou vous vous defendre (2) ou vous decidez de l'empoisonner (3) ou d'utiliser l'antidote (4)?\n");
		scanf("%d",&decisionJ);
		decisionM =((rand()%3)+1);
		
		if (decisionJ == 4){
			printf("Vous utilisez votre antidote, vous n'etes plus empoisonne");
			poisonM = 0;
		}
			
		if (decisionJ == 3 && PM>=3){
			printf("Vous avez empoisonne le monstre.\n");
			poisonJ ++;
			PM = PM -3;
			if(decisionJ == 3 && PM<3){
				printf ("Vous n'avez plus de mana\n");
				printf ("Voulez vous attaquer (1) ou vous vous defendre (2)\n");
				scanf("%d",&decisionJ);
			}
		}
		
		
		if (decisionM == 3 && PMmonstre>=3){
			printf("Le monstre vous empoisonne.\n");
			poisonM ++;
			PMmonstre = PMmonstre -3;
			if(decisionM == 3 && PMmonstre<3){
				(decisionM =((rand()%2)+1));
			}
		}
		
			
		if (decisionM == 2){
			printf("Le monstre se defend.\n");
			attaquejoueur = attaquejoueur/4;
				
		}
		
		if (decisionJ == 2){
			printf("Vous decidez de vous defendre.\n");
			attaquemonstre = attaquemonstre/4;
			
		}
		
		if(decisionJ == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvmonstre = pvmonstre - attaquejoueur;
			
			}
		
		if(decisionM == 1){
			printf("Le monstre vous attaque.\n");
			pvjoueur = pvjoueur - attaquemonstre;
			
		}
	
	if(poisonJ >= 1){
		pvmonstre = pvmonstre - poisonJ;
	}
	if(poisonM >= 1){
		pvjoueur = pvjoueur - poisonM;
	}
		
		
	if (PM<10){
		PM++;
	}
	
	if (PMmonstre<10){
		PMmonstre++;
	}
	
	printf ("Il vous reste %d points de mana.\n", PM);
	printf ("Le monstre a %d points de vie.\n", pvmonstre);
	printf ("Il vous reste %d points de vie.\n", pvjoueur);
	
	attaquemonstre = 10;
	attaquejoueur = 10;
	
		
	}	
	
	
	


	return 0;
}
