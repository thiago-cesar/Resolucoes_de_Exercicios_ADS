#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>
#include <string>


int main()
{
	
	setlocale(LC_ALL, "Portuguese");
	//FEZ-SE NECESS�RIO INSERIR "" PARA INFORMAR QUE A VARI�VEL EST� "ZERADA".POIS DURANTE
	// A DEPURA��O DO C�DIGO, PERCEBI QUE A MEM�RIA ESTAVA COM CARACTERES DESCONHECIDOS NESSAS
	//VARI�VEIS.
	char string1[20], string2[20], somastr[40] = { "" }, somastr2[40] = { "" };
	int posi ;

	printf_s("Digite o seu primeiro nome:\n");
	gets_s(string1);
	
	printf_s("Digite o seu sobrenome:\n");
	gets_s(string2);
	
	printf_s("Escolha a posi��o de inser��o da String2 na String1\n\n");
	scanf_s("%d", &posi);

	//LOOP FOR PARA CRIAR UMA VARI�VEL PARA SEPARAR A PRIMEIRA PARTE DA STRING 1.

	for (int i = 0; i < posi; i++)
	{	
		somastr[i] = string1[i];
		
	}

	//FUN��O PARA CONCATENAR AS TR�S PRIMEIRAS LETRAS DO PRIMEIRO LOOP FOR (STRING 1).
	strcat_s(somastr, string2);

	printf_s("\n\n PASSO 1: JUN��O DA STRING 2 � POSI��O ESCOLHIDA DA STRING 1: %s! \n\n", somastr);

	//LOOP FOR PARA SOMAR A SEGUNDA PARTE DA STRING 1 PARA STRING 2.

	for (int j = posi; j < (strlen(string2) + posi); j++) {

		int X = j - posi;//VARI�VEL PARA INCIALIZAR A VARI�VEL "somastr2" PARA RECEBER A SEGUNDA PARTE
						//DA STRING 1.
		somastr2[X] = string1[j];
	}
	
	
	//AP�S GERAR UMA VARI�VEL COM A STRING 1 (1 PARTE), SOMAMOS � STRING 2 COM A PARTE RESTANTE
	// DA STRING 1 PARA EM SEGUIDA GERAR A NOVA STRING. UTILIZOU-SE A FUN��O "strcat" PARA CONCATENAR.

	strcat_s(somastr, somastr2);

	printf_s("\n\n PASSO 2: JUN��O DA NOVA STRING COM O ""RESTO DA STRING 1"" CADEIA : %s! \n\n", somastr);



	system("pause");
	return 0;

}