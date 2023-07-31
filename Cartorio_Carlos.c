#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings
 	
int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema.
{
	//Inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis/strings	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo  W= write (escrever)
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf); //salvar valor da variavel
	fclose(file); //fechar o arquivo.
	
	
	file = fopen(arquivo, "a"); //abrir o arquivo "a" = Atualizar o arquivo pr� existente
	fprintf(file,"\nNOME: "); //inform��o que aparece na tela para o Usuario
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Fun��o responsavel por imprimir algo na tela
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pr� existente
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" = Atualizar o arquivo pr� existente
	fprintf(file,"\nSOBRENOME: ");//Fun��o responsavel por imprimir algo na tela
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//Fun��o responsavel por imprimir algo na tela
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pr� existente
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pr� existente
	fprintf(file,"\nCARGO: ");//Fun��o responsavel por imprimir algo na tela
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//Fun��o responsavel por imprimir algo na tela
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pr� existente
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);	
	
    system("pause");
	
}

int consulta()
{
	//Definindo a linguagem
	setlocale(LC_ALL, "Portuguese"); 
	//Inicio da cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");//Fun��o responsavel por imprimir algo na tela
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r"); // "R" = Ler o arquvo
	
	if(file == NULL)
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Fun��o responsavel por imprimir algo na tela
}
	
	printf("Essas s�o as informa��es do usu�rio: \n\n"); //Fun��o responsavel por imprimir algo na tela
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("%s", conteudo);
}
  	fclose(file); // Fechar o arquivo
	system ("pause"); // Pausar
}   		 

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //Fun��o responsavel por imprimir algo na tela
	scanf("%s",cpf); // %s refere-se a strings
	
//  FILE = Entrar na biblioteca no campo que fala sobre a fun��o FILE
// file =  Puxar os arquivos.
	FILE *file;
	file = fopen(cpf,"r");
	
	
	
	if(file == NULL) //usuario inexistente
	{
		printf("\nO usu�rio nao foi encontrado no sistema!\n\n");//Fun��o responsavel por imprimir algo na tela
		fclose(file);//fechar o arquivo
		system("pause");
		fclose(file);
	}
	
	else
	 //usuario existente
	{
		fclose(file);
		remove(cpf);
		printf("\nO usu�rio foi deletado com sucesso!\n\n");//Fun��o responsavel por imprimir algo na tela
		system("pause");	
	}
}


int main()
   	{
   		 int opcao=0; //Definindo vari�veis
		 int laco=1; 
   		 for(laco=1;laco=1;)
   		{
   			
   			system("cls"); //Apagar mensagems
   			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   		 	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
   		 	printf("Escolha a op��o desejada do menu\n\n"); //Fun��o responsavel por imprimir algo na tela
   			printf("\t1 - Registrar nomes\n"); //Fun��o responsavel por imprimir algo na tela
   			printf("\t2 - Consultar nomes\n"); //Fun��o responsavel por imprimir algo na tela
   		 	printf("\t3 - Deletar nomes\n"); //Fun��o responsavel por imprimir algo na tela
   		 	printf("\t4 - Sair do sistema.\n\n"); //Fun�ao responsavel por sair do sistema.
   		 	printf("Op��o: ");//fim do menu
   		 
   		 	scanf("%d", &opcao); //Armazenando a escolha do usuario
   		 
   		 	system("cls"); //Apagar mensagens anteriores
   		 	
   		 	
   		 	switch(opcao) //inicio da sele��o
   		 	{
   		 		case 1:
   		 		registro(); //chamada de fun��es.
   		 		break;
   		 		
   		 		case 2:
   		 		consulta(); //chamada de fun��es.
   		  		break;
   		  		
   		  		case 3:
   		  		deletar(); //chamada de fun��es.
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Est� op��o n�o est� dispon�vel!\n"); //Fun��o responsavel por imprimir algo na tela
		  		system("pause"); // pausar sistema
				break; // fim da sele��o
			}
		
	    }	
   	}
