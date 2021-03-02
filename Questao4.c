#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

main () {
	FILE *arq;
	char nomeAluno[25], nomeArq[25], opc;
	int quant, i, idadeAluno, idadeArq;
	arq = fopen("questão4.txt", "w");
	if (arq==NULL) {
		printf ("Erro ao criar o arquivo\n");
		exit(1);
	} else {
		printf ("Arquivo criado com sucesso\n");
	}

	printf ("Digite o nome do aluno: ");
	fflush(stdin);
	gets(nomeAluno);
	printf ("Digite a idade do aluno: ");
	scanf ("%d", &idadeAluno);

	fprintf (arq, "%s %d\n", nomeAluno, idadeAluno);
	fprintf (arq, "\n");
	fclose (arq);

	printf ("Deseja inserir mais arquivos? (S ou N): ");
	opc = getche();
	opc = tolower (opc);
	printf ("\n");

	if (opc=='s') {
		arq = fopen("questão4.txt", "a");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}

		printf ("Informe a quantidade de registros: ");
		scanf ("%d", &quant);
		for (i=0; i<quant; i++) {
			printf ("Digite o nome do aluno: ");
			fflush(stdin);
			gets(nomeAluno);
			printf ("Digite a idade do aluno: ");
			scanf ("%d", &idadeAluno);
			fprintf (arq, "%s %d\n", nomeAluno, idadeAluno);
		}
		fclose(arq);
		printf ("Finalizado\n");
		arq = fopen("questão4.txt", "r");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		printf ("Registros do arquivo...\n");
		while (fscanf(arq, "%s %d\n", nomeArq, &idadeArq) != EOF) {
			printf("Nome do aluno: %s\nIdade do aluno: %d\n", nomeArq, idadeArq);
		}
		fclose(arq);
		/*MEU MÉTODO
		for (i=0; i<quant+1; i++) {
			fscanf(arq, "%s", &cidadeArq);
			printf ("%s\n", cidadeArq);
		}*/
	} else if (opc=='n') {
		arq = fopen("questão4.txt", "r");
		if (arq==NULL) {
			printf ("Erro ao criar o arquivo\n");
			exit(1);
		} else {
			printf ("Arquivo criado com sucesso\n");
		}
		fscanf (arq, "%s %d", nomeArq, &idadeArq);
		fclose(arq);
		printf ("Registros do arquivo...\n");
		printf ("Nome do aluno: %s\nIdade do aluno: %d", nomeArq, idadeArq);
	}
}


