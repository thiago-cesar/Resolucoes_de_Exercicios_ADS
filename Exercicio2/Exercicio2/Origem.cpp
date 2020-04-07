#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>


int main() {

	setlocale(LC_ALL, "Portuguese");
	int opcao, opcao2, clienteID;//DECLARA��O DE VARI�VEIS PARA FUN��O SWITCH E CONTADRES
	float count, mediakw, maiorkw,menorkw;//DECLARA��O DE VARI�VEIS PARA O "CASO" 2 (M�DIA)
	float contam[10][3] = {0};//DECLARA��O DE UMA MATRIZ NULA (PREENCHIDAS COM ZERO)
	
	
	do {//FUN��O DO IR� MOSTRAR NA TELA O MENU "ENQUANTO" A OP��O 5-SAIR N�O FOR SELECIONADA.
		
		printf("ESCOLHA E DIGITE A OP��O: \n\n 1- CADASTRAR CONSUMIDOR\n" 
			"\n 2- M�DIA DE CONSUMO\n"
			"\n 3- MAIOR CONSUMO \n"
			"\n 4- MENOR CONSUMO \n "
			"\n 5- LISTAR CONSUMIDORES QUE ULTRAPASSARAM 170 KW:\n "
			"\n 6- LISTAR TODOS OS CLIENTE:\n"
			"\n 7- SAIR \n ");

		scanf_s("%d", &opcao);

		switch (opcao)//ADMINISTRAR A VARI�VEL "opcao" DE ACORDO COM OP��O SELECIONADA DO MENU.
		{

		case 1://OP��O 1- CADASTRAR CONSUMIDOR PELO N�MERO DO ID.


			for (int i = 0; i <= 10; i++) {//LOOP FOR PARA CADASTRO CONT�NUO DE CONSUMIDOR.

				printf("DIGITE O ID DO CONSUMIDOR PELO N�MERO ID: ");
				scanf_s("%f", &contam[i][0]);
				printf("DIGITE A QUANTIDADE DE KW CONSUMIDO: ");
				scanf_s("%f", &contam[i][1]);
				contam[i][2] = contam[i][1] * 1.75;
				printf("TOTAL A PAGAR: R$  %.2f \n\n", (contam[i][2]));

				// PARA CADA CADASTRO DE CONSUMIDOR, PERGUNTA-SE SE DESEJA INCLUIR MAIR ALGU�M.1 PARA SIM
				//E, RETORNA PARA O LOOP FOR PARA UM NOVO CADASTRO. N�O,DIGITANDO 2 O PROGRAMA REALIZA UM "break" e
				//RETORNA PARA O MENU.

				printf("\n DESEJA INCLUIR MAIS ALGUM CLIENTE ? DIGITE 1 - SIM OU 2 - N�O.\n");
				scanf_s("%d", &opcao2);

				if (opcao2 == 1) {
					printf("\n DIGITE O PR�XIMO CONSUMIDOR: \n ");
					continue;
				}
				if (opcao2 == 2) {
					break;

				}
			}

			break;

		case 2://OP��O 2- SA�DA DA M�DIA DE CONSUMO EM REAIS.

			count = 0;//VARI�VEL QUE RECEBE OS VALORES SOMADOS DA 3� COLUNA DA MATRIZ (VALOR DO CONSUMO EM REAIS).

			for (int i = 0; i < 10; i++)
			{
				count = count + contam[i][2];//INCREMENTA APENAS A 3� COLUNA.

			}
			mediakw = count / 10;//AP�S O LOOP FOR, REAIZA-SE O C�LCULO DA M�DIA(OBSERVAR QUE
								// � FEITA DE TODAS AS LINHAS, MESMO N�O PREENCHIDAS, QUE EST�O COM VALORES ZERO.

			printf_s(" \n M�DIA DE CONSUMO EM R$ %.2f \n ", mediakw);	
			break;

		case 3:// OPCAO 3 BUSCA O CLIENTE COM MAIOR CONSUMO DE ENERGIA E LISTA ID, CONSUMO EM KW E EM R$.

			maiorkw = contam[0][1];//ATRIBUI O MAIOR VAOR DA BUSCA DO OOP FOR ABAIXO.
			clienteID = contam[0][0];//SALVA O CLIENTE QUE POSSUI O MAIOR CONSUMO AT� O FIM DA COMAPARA��O.
			for (int i=0; i < 10; i++) {
				if (maiorkw < contam[i][1]) {
					maiorkw = contam[i][1];
					clienteID = contam[i][0];
				}
			}
			printf_s("\n MAIOR CONSUMO DE ENERGIA:\n"//IMPRIME OS DADOS COMPLETOS DO CLIENTE QUE MAIS CONSUMIU.
				"\n CLIENTEID:  %d\n"
				"\n CONSUMO: %.f \n" 
				"\n VALOR EM R$: %.2f \n", clienteID, maiorkw, (maiorkw*1.75));
			
			break;

		case 4:// OPCAO 3 BUSCA O CLIENTE COM MENOR CONSUMO DE ENERGIA E LISTA ID, CONSUMO EM KW E EM R$.
			
			menorkw = contam[0][1];//ATRIBUI O MENOR VALOR DA BUSCA DO LOOP FOR ABAIXO.
			clienteID = contam[0][0];//SALVA O CLIENTE QUE POSSUI O MENOR CONSUMO AT� O FIM DA COMAPARA��O.
			
			for (int i = 0; i < 10; i++) {
				if (menorkw > contam[i][1] && contam[i][1]!=0) {
					menorkw = contam[i][1];
					clienteID = contam[i][0];
				}
			}
			printf_s("\n MENOR CONSUMO DE ENERGIA:\n"//IMPRIME OS DADOS COMPLETOS DO CLIENTE QUE MENOS CONSUMIU.
				"\n CLIENTEID:  %d\n"
				"\n CONSUMO: %.f \n"
				"\n VALOR EM R$: %.2f \n", clienteID, menorkw, (menorkw * 1.75));

			break;

		case 5://CASO DA OP��O 5. LISTAR APENAS OS CLIENTES COM CONSUMO ACIMA DE 170 KW.
			
			int cliente;
			float consumo;
			printf_s("\n CLIENTES QUE ULTRAPASSARAM 170 KW:\n  ");
			for (int i = 0; i < 10; i++)
			{
				if (contam[i][1] > 170) //CONDI��O IF PARA LISTAR SA�DA COM APENAS OS CLIENTES COM CONSUMO MAIOR QUE 170 KW.
				{

					cliente = contam[i][0];
					consumo = contam[i][1];
					printf_s("\n CLIENTEID: %d CONSUMIU %.2f KW \n\n", cliente, consumo);

				}
									
			}
			break;

		case 6://CASO DA OP��O 6: LISTAR TODOS CLIENTES POR ID, CONSUMO EM KW E VALOR.

			printf_s("\n LISTA DE CLIENTES:\n  ");
			for (int i = 0; i < 10; i++)
			{
				if (contam[i][1] != 0) //PARA EXCLUIR LINHAS N�O UTILIZADAS.
				{
					cliente = contam[i][0];
					consumo = contam[i][1];
					printf_s("\n CLIENTEID: %d CONSUMO: %.2f KW  VALOR: R$ %.2f \n\n", cliente, consumo, consumo * 1.75);

				}
				
			}
			break;
		
		case 7://OP��O PARA SAIR DO PROGRAMA. ESSA OP��O FINALIZA O WHILE NO FINAL DA ESTRUTURA DO-WHILE.
			printf_s("\n PROGRAMA FINALIZADO.\n ");
			break;

		default://PARA OP��ES N�O LISTADAS NO MENU, O PROGRAMA EXECULTA O DEFAULT NA TELA.
			printf_s("\n DIGITE ALGUMA OP��O V�LIDA!\n ");
			break;
		}
	} while (opcao != 7);//LOOP FINALIZA APENAS SE FOR ESCOLHIDA A OP��O 7 ("SAIR").
	
		

	system ("pause");
	return 0;
}