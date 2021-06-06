#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUFFER	 255

main(){
	
	char teste1[10];
	char teste2[10];

	//-----------------------------------------
	printf("Digite ate 10 letras:\n");
	fgets(teste1,sizeof(teste1),stdin); //ultimo digito é o /0
	//scanf("%s",&teste1);
	fflush(stdin);
	for(int i=0; i < strlen(teste1); i++){
		if( isalpha(teste1[i]) == 0 ){
			printf("DEU PAU\n");
			break;
		}
		else{
			printf("TA SAFE - %c\n",teste1[i]);
		}
	}
	//fflush(stdin);
	//----------------------------------------
	printf("\n\nDigite ate 10 digitos:\n");
	fgets(teste2,sizeof(teste2),stdin);
	
	for(int i=0; i < strlen(teste2); i++){
		if( isdigit(teste2[i]) == 0 ){
			printf("DEU PAU\n");
			break;
		}
		else{
			printf("TA SAFE - %c\n",teste2[i]);
		}
	}
}