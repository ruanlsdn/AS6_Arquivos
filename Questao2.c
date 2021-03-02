#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
main (){
	char nome[10];
	FILE *arq;
	printf ("Informe um nome para o arquivo: ");
	fflush(stdin);
	gets (nome);
	if ((arq=fopen(nome, "w"))==NULL){
		printf ("Arquivo não foi criado.");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso.");
	}
	fclose(arq);
}
