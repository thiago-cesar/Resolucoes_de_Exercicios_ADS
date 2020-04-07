#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>


int main() {

	setlocale(LC_ALL, "Portuguese");
	int opcao, opcao2, clienteID;//DECLARAÇÃO DE VARIÁVEIS PARA FUNÇÃO SWITCH E CONTADRES
	float count, mediakw, maiorkw,menorkw;//DECLARAÇÃO DE VARIÁVEIS PARA O "CASO" 2 (MÉDIA)
	float contam[10][3] = {0};//DECLARAÇÃO DE UMA MATRIZ NULA (PREENCHIDAS COM ZERO)
	
	
	do {//FUNÇÃO DO IRÁ MOSTRAR NA TELA O MENU "ENQUANTO" A OPÇÃO 5-SAIR NÃO FOR SELECIONADA.
		
		printf("ESCOLHA E DIGITE A OPÇÃO: \n\n 1- CADASTRAR CONSUMIDOR\n" 
			"\n 2- MÉDIA DE CONSUMO\n"
			"\n 3- MAIOR CONSUMO \n"
			"\n 4- MENOR CONSUMO \n "
			"\n 5- LISTAR CONSUMIDORES QUE ULTRAPASSARAM 170 KW:\n "
			"\n 6- LISTAR TODOS OS CLIENTE:\n"
			"\n 7- SAIR \n ");

		scanf_s("%d", &opcao);

		switch (opcao)//ADMINISTRAR A VARIÁVEL "opcao" DE ACORDO COM OPÇÃO SELECIONADA DO MENU.
		{

		case 1://OPÇÃO 1- CADASTRAR CONSUMIDOR PELO NÚMERO DO ID.


			for (int i = 0; i <= 10; i++) {//LOOP FOR PARA CADASTRO CONTÍNUO DE CONSUMIDOR.

				printf("DIGITE O ID DO CONSUMIDOR PELO NÚMERO ID: ");
				scanf_s("%f", &contam[i][0]);
				printf("DIGITE A QUANTIDADE DE KW CONSUMIDO: ");
				scanf_s("%f", &contam[i][1]);
				contam[i][2] = contam[i][1] * 1.75;
				printf("TOTAL A PAGAR: R$  %.2f \n\n", (contam[i][2]));

				// PARA CADA CADASTRO DE CONSUMIDOR, PERGUNTA-SE SE DESEJA INCLUIR MAIR ALGUÉM.1 PARA SIM
				//E, RETORNA PARA O LOOP FOR PARA UM NOVO CADASTRO. NÃO,DIGITANDO 2 O PROGRAMA REALIZA UM "break" e
				//RETORNA PARA O MENU.

				printf("\n DESEJA INCLUIR MAIS ALGUM CLIENTE ? DIGITE 1 - SIM OU 2 - NÃO.\n");
				scanf_s("%d", &opcao2);

				if (opcao2 == 1) {
					printf("\n DIGITE O PRÓXIMO CONSUMIDOR: \n ");
					continue;
				}
				if (opcao2 == 2) {
					break;

				}
			}

			break;

		case 2://OPÇÃO 2- SAÍDA DA MÉDIA DE CONSUMO EM REAIS.

			count = 0;//VARIÁVEL QUE RECEBE OS VALORES SOMADOS DA 3ª COLUNA DA MATRIZ (VALOR DO CONSUMO EM REAIS).

			for (int i = 0; i < 10; i++)
			{
				count = count + contam[i][2];//INCREMENTA APENAS A 3ª COLUNA.

			}
			mediakw = count / 10;//APÓS O LOOP FOR, REAIZA-SE O CÁLCULO DA MÉDIA(OBSERVAR QUE
								// É FEITA DE TODAS AS LINHAS, MESMO NÃO PREENCHIDAS, QUE ESTÃO COM VALORES ZERO.

			printf_s(" \n MÉDIA DE CONSUMO EM R$ %.2f \n ", mediakw);	
			break;

		case 3:// OPCAO 3 BUSCA O CLIENTE COM MAIOR CONSUMO DE ENERGIA E LISTA ID, CONSUMO EM KW E EM R$.

			maiorkw = contam[0][1];//ATRIBUI O MAIOR VAOR DA BUSCA DO OOP FOR ABAIXO.
			clienteID = contam[0][0];//SALVA O CLIENTE QUE POSSUI O MAIOR CONSUMO ATÉ O FIM DA COMAPARAÇÃO.
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
			clienteID = contam[0][0];//SALVA O CLIENTE QUE POSSUI O MENOR CONSUMO ATÉ O FIM DA COMAPARAÇÃO.
			
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

		case 5://CASO DA OPÇÃO 5. LISTAR APENAS OS CLIENTES COM CONSUMO ACIMA DE 170 KW.
			
			int cliente;
			float consumo;
			printf_s("\n CLIENTES QUE ULTRAPASSARAM 170 KW:\n  ");
			for (int i = 0; i < 10; i++)
			{
				if (contam[i][1] > 170) //CONDIÇÃO IF PARA LISTAR SAÍDA COM APENAS OS CLIENTES COM CONSUMO MAIOR QUE 170 KW.
				{

					cliente = contam[i][0];
					consumo = contam[i][1];
					printf_s("\n CLIENTEID: %d CONSUMIU %.2f KW \n\n", cliente, consumo);

				}
									
			}
			break;

		case 6://CASO DA OPÇÃO 6: LISTAR TODOS CLIENTES POR ID, CONSUMO EM KW E VALOR.

			printf_s("\n LISTA DE CLIENTES:\n  ");
			for (int i = 0; i < 10; i++)
			{
				if (contam[i][1] != 0) //PARA EXCLUIR LINHAS NÃO UTILIZADAS.
				{
					cliente = contam[i][0];
					consumo = contam[i][1];
					printf_s("\n CLIENTEID: %d CONSUMO: %.2f KW  VALOR: R$ %.2f \n\n", cliente, consumo, consumo * 1.75);

				}
				
			}
			break;
		
		case 7://OPÇÃO PARA SAIR DO PROGRAMA. ESSA OPÇÃO FINALIZA O WHILE NO FINAL DA ESTRUTURA DO-WHILE.
			printf_s("\n PROGRAMA FINALIZADO.\n ");
			break;

		default://PARA OPÇÕES NÃO LISTADAS NO MENU, O PROGRAMA EXECULTA O DEFAULT NA TELA.
			printf_s("\n DIGITE ALGUMA OPÇÃO VÁLIDA!\n ");
			break;
		}
	} while (opcao != 7);//LOOP FINALIZA APENAS SE FOR ESCOLHIDA A OPÇÃO 7 ("SAIR").
	
		

	system ("pause");
	return 0;
}