#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main() {

	int linha, sdp= 0;
	int sds = 0;
	int qm[10][10] = { 0 };
	int vetorsl[10] = { 0 };
	int linhasoma[10] = { 0 };
	int vetorsc[10] = { 0 };
	
	setlocale(LC_ALL, "Portuguese");

	printf_s("ALGORITMO ARA VERIFICAR MATRIZ DO TIPO 'QUADRADO M�GICO'.\n\n"
		"\n\n SIGA AS INSTRU��ES ABAIXO: \n\n"
		"\n 1- O ALGORITMO ACEITA APENAS MATRIZES QUADRADA\n"
		"\n 2- DIGITE A ORDEM DA MATRIZ. SE FOR UMA MATRIZ 2X2, "
		"\n SUA ORDEM � 2. SE FOR UMA MATRIZ 3X3, SUA ORDEM � 3x3 E ASSIM, SUCESSIVAMENTE.\n\n");

	printf_s("DIGITE A QUANTIDADE DE LINHAS DA MATRIZ: ");
	scanf_s("%d", &linha);

	//LOOP FOR PARA SOMA DE ELEMENTOS EM LINHA ARMAZENADOS EM UM VETOR (vetorsl[]).

	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < linha; j++)
		{
			printf_s("\n\n DIGITE O ELEMENTO DA LINHA[%d] E COLUNA [%d]: ", i, j);
			scanf_s("%d", &qm[i][j]);
			vetorsl[i] += qm[i][j];
		}

	}
	
	//LOOP PARA SA�DA DE VALORES DE SOMA POR LINHA.
	
	for (int u = 0; u < linha; u++) {
		printf_s("\n\n TOTAL DE SOMA DE ELEMENTOS DA LINHA %d: %d\n\n ", u, vetorsl[u]);
	}

	//LOOP PARA SA�DA DA SOMA DE CADA COLUNA.

	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < linha; j++)
		{
			vetorsc[i] += qm[j][i];
		}

	}
	for (int u = 0; u < linha; u++) {
		printf_s("\n\n TOTAL DE SOMA DE ELEMENTOS DA COLUNA %d: %d\n\n ", u, vetorsc[u]);

	}

	//LOOP FOR PARA SOMA DE ELEMENTOS DE DIAGONAL SECUND�RIA.

	for (int i = 0; i < linha; i++) 
	{
		for (int j = 0; j < linha; j++) 
		{
			if (j == (linha - 1 - i))
			{
				sds += qm[i][j];
			}
			
		}
	}
	printf_s("\n\n TOTAL DE SOMA DE ELEMENTOS DA DIAGONAL SECUND�RIA: %d\n\n ", sds);
	


	//LOOP FOR PARA SOMA DE ELEMENTOS DA DIAGONAL PRINCIPAL.

	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < linha; j++) 
		{
			if (j == i) {
				sdp = sdp + qm[i][j];
			}
					
		}

	}
	printf_s("\n\n TOTAL DE SOMA DE ELEMENTOS DA DIAGONAL PRINCIPAL: %d\n\n ", sdp);

	//LOOP FOR PARA VERIFICA��O DAS VARI�VEIS EM VETOR (LINHAS E COLUNAS) E DIAGONAIS.

	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < linha; j++) {

			if (vetorsc[i] == vetorsc[j] && sds == sdp)
			{
				printf_s("\n\n A SUA MATRIZ � UM QUADRADO M�GICO! \n\n ");
			}
			
			else 
			{
				printf_s("\n\n A SUA MATRIZ N�O � UM QUADRADO M�GICO! \n\n");
			}
			
			
		}
	}
	

	system("pause");
	return 0;
}