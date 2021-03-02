#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
main () {
	FILE *arq;
	char nomeCidade[25], cidadeArq[25], opc;
	int quant, i, dddCidade, dddArq;
	arq = fopen("questão5.bin", "w");
	if (arq==NULL) {
		printf ("Erro ao criar o arquivo\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso\n");
	}

	printf ("Digite o nome da cidade: ");
	fflush(stdin);
	gets(nomeCidade);
	printf ("Digite o DDD da cidade: ");
	scanf ("%d", &dddCidade);

	fprintf (arq, "%s %d\n", nomeCidade, dddCidade);
	fprintf (arq, "\n");
	fclose (arq);

	printf ("Deseja inserir mais arquivos? (S ou N): ");
	opc = getche();
	opc = tolower (opc);
	printf ("\n");

	if (opc=='s') {
		arq = fopen("questão5.bin", "a");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}

		printf ("Informe a quantidade de registros: ");
		scanf ("%d", &quant);
		for (i=0; i<quant; i++) {
			printf ("Digite o nome da cidade: ");
			fflush(stdin);
			gets(nomeCidade);
			printf ("Digite o DDD da cidade: ");
			scanf ("%d", &dddCidade);
			fprintf (arq, "%s %d\n", nomeCidade, dddCidade);
			fprintf (arq, "\n");
		}
		fclose(arq);
		printf ("Finalizado\n");
		arq = fopen("questão5.bin", "r");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		printf ("Registros do arquivo...\n");
		while (fscanf(arq, "%s %d\n", cidadeArq, &dddArq) != EOF) {
			printf("Nome da cidade: %s\nDDD da cidade: %d\n", cidadeArq, dddArq);
		}
		fclose(arq);
		/*MEU MÉTODO
		for (i=0; i<quant+1; i++) {
			fscanf(arq, "%s", &cidadeArq);
			printf ("%s\n", cidadeArq);
		}*/
	} else if (opc=='n') {
		arq = fopen("questão5.bin", "r");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		fscanf (arq, "%s %d\n", cidadeArq, &dddArq);
		fclose(arq);
		printf ("Registros do arquivo...\n");
		printf ("Nome da cidade: %s\nDDD da cidade: %d", cidadeArq, dddArq);
	}
}


