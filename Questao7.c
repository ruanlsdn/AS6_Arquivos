#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

main () {
	FILE *arq;
	char nomeCidade[25], cidadeArq[25], opc;
	int quant, i;
	arq = fopen("questão7.txt", "w");
	if (arq==NULL) {
		printf ("Erro ao criar o arquivo\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso\n");
	}

	printf ("Digite o nome da cidade: ");
	fflush(stdin);
	gets(nomeCidade);

	fprintf (arq, "%s", nomeCidade);
	fprintf (arq, "\n");
	fclose (arq);

	printf ("Deseja inserir mais arquivos? (S ou N): ");
	opc = getche();
	opc = tolower (opc);
	printf ("\n");

	if (opc=='s') {
		arq = fopen("questão7.txt", "a");
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
			fprintf (arq, "%s", nomeCidade);
			fprintf (arq, "\n");
		}
		fclose(arq);
		printf ("Finalizado\n");
		arq = fopen("questão7.txt", "r");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		printf ("Registros do arquivo...\n");
		while (fscanf(arq, "%s", cidadeArq) != EOF) {
			printf("Nome da cidade: %s\n", cidadeArq);
		}
		fclose(arq);
		/*MEU MÉTODO
		for (i=0; i<quant+1; i++) {
			fscanf(arq, "%s", &cidadeArq);
			printf ("%s\n", cidadeArq);
		}*/
	} else if (opc=='n') {
		arq = fopen("questão7.txt", "r");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		fscanf (arq, "%s", &cidadeArq);
		fclose(arq);
		printf ("Registros do arquivo...\n");
		printf ("Nome da cidade: %s", cidadeArq);
	}

	printf ("Dejesa excluir o arquivo? (S ou N): ");
	opc = getche();
	opc = tolower(opc);
	printf ("\n");
	if (opc=='s') {
		arq = fopen("questão7.txt", "rb");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		fclose (arq);
		remove("questão7.txt");
		printf ("Excluido");
	}
}


