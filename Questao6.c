#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

main () {
	FILE *arq;
	char nome[10], nomeArq[10];
	arq = fopen("questão6.txt", "w");
	if (arq == NULL) {
		printf ("Erro ao criar o arquivo\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso\n");
	}
	printf ("Digite o seu nome: ");
	fflush (stdin);
	gets (nome);
	fprintf (arq, "%s", nome);
	fclose(arq);

	arq = fopen("questão6.txt", "r");
	if (arq == NULL) {
		printf ("Erro ao criar o arquivo\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso\n");
	}
	fscanf (arq, "%s", &nomeArq);
	fclose(arq);
	
	system ("cls");
	printf ("%s", nomeArq);
}
