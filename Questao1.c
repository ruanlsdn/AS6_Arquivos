#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
main (){
	FILE *arq;
	if ((arq=fopen("Questao1.txt", "w"))==NULL){
		printf ("Arquivo não foi criado.\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso.\n");
	}
	fclose(arq);
}
