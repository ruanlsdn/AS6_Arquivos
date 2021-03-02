#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
main () {
	FILE *arq;
	int qtde, i;
	double num[100], numArq[100];
	//DADOS PARA DENTRO DO ARQUIVO
	if ((arq=fopen("Questao3.txt", "w"))==NULL) {
		printf ("Arquivo não foi criado.\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso.\n");
	}
	printf ("Informe quantos numeros pretende digitar: ");
	scanf ("%d", &qtde);
	for (i=0; i<qtde; i++) {
		printf ("Informe o %d numero: ", i+1);
		scanf ("%lf", &num[i]);
		fprintf (arq, "%lf", num[i]);
	}
	fclose(arq);

	//DADOS DO ARQUIVO PARA O PROGRAMA
	if ((arq=fopen("Questao3.txt", "r"))==NULL) {
		printf ("Arquivo não foi criado.\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso.\n");
	}

	for (i=0; i<qtde; i++) {
		fscanf (arq, "%lf", &numArq[i]);
	}
	fclose(arq);

	printf ("Numeros no arquivo: ");
	for (i=0; i<qtde; i++) {
		printf ("%lf ", numArq[i]);
	}

}
