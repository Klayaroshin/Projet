#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct Inventaire {
//	char Potion[20] = "Potion";
//	char Epee[20] = "Epee";
//	char Parchemin[20] = "Parchemin";
//	char Rubis[20] = "Rubis";
//};

//typedef struct Inventaire inventaire;

//void comparerInventaire(inventaire * ){
//}

// Début de la fonction principale
int main(){
	
	
	
	
	
	
	
	
	
	
	int strcomp(char *chaine_un,char *chaine_deux){
		int i;
	 
			for(i=0; chaine_un[i] != '\0' || chaine_deux[i] != '\0'; i++) {
				if (chaine_un[i] < chaine_deux[i])
				   return -1;
				if (chaine_un[i] > chaine_deux[i])
				   return 1;
			}
	}
	
	

	return 0;
}