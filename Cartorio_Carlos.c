#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings
 	
int registro() // Função responsavel por cadastrar os usuários no sistema.
{
	//Inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variaveis/strings	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo  W= write (escrever)
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf); //salvar valor da variavel
	fclose(file); //fechar o arquivo.
	
	
	file = fopen(arquivo, "a"); //abrir o arquivo "a" = Atualizar o arquivo pré existente
	fprintf(file,"\nNOME: "); //informção que aparece na tela para o Usuario
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Função responsavel por imprimir algo na tela
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pré existente
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" = Atualizar o arquivo pré existente
	fprintf(file,"\nSOBRENOME: ");//Função responsavel por imprimir algo na tela
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//Função responsavel por imprimir algo na tela
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pré existente
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pré existente
	fprintf(file,"\nCARGO: ");//Função responsavel por imprimir algo na tela
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//Função responsavel por imprimir algo na tela
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");// "a" = Atualizar o arquivo pré existente
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);	
	
    system("pause");
	
}

int consulta()
{
	//Definindo a linguagem
	setlocale(LC_ALL, "Portuguese"); 
	//Inicio da criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");//Função responsavel por imprimir algo na tela
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r"); // "R" = Ler o arquvo
	
	if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Função responsavel por imprimir algo na tela
}
	
	printf("Essas são as informações do usuário: \n\n"); //Função responsavel por imprimir algo na tela
	
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
	
	printf("Digite o CPF a ser deletado: "); //Função responsavel por imprimir algo na tela
	scanf("%s",cpf); // %s refere-se a strings
	
//  FILE = Entrar na biblioteca no campo que fala sobre a função FILE
// file =  Puxar os arquivos.
	FILE *file;
	file = fopen(cpf,"r");
	
	
	
	if(file == NULL) //usuario inexistente
	{
		printf("\nO usuário nao foi encontrado no sistema!\n\n");//Função responsavel por imprimir algo na tela
		fclose(file);//fechar o arquivo
		system("pause");
		fclose(file);
	}
	
	else
	 //usuario existente
	{
		fclose(file);
		remove(cpf);
		printf("\nO usuário foi deletado com sucesso!\n\n");//Função responsavel por imprimir algo na tela
		system("pause");	
	}
}


int main()
   	{
   		 int opcao=0; //Definindo variáveis
		 int laco=1; 
   		 for(laco=1;laco=1;)
   		{
   			
   			system("cls"); //Apagar mensagems
   			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   		 	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
   		 	printf("Escolha a opção desejada do menu\n\n"); //Função responsavel por imprimir algo na tela
   			printf("\t1 - Registrar nomes\n"); //Função responsavel por imprimir algo na tela
   			printf("\t2 - Consultar nomes\n"); //Função responsavel por imprimir algo na tela
   		 	printf("\t3 - Deletar nomes\n"); //Função responsavel por imprimir algo na tela
   		 	printf("\t4 - Sair do sistema.\n\n"); //Funçao responsavel por sair do sistema.
   		 	printf("Opção: ");//fim do menu
   		 
   		 	scanf("%d", &opcao); //Armazenando a escolha do usuario
   		 
   		 	system("cls"); //Apagar mensagens anteriores
   		 	
   		 	
   		 	switch(opcao) //inicio da seleção
   		 	{
   		 		case 1:
   		 		registro(); //chamada de funções.
   		 		break;
   		 		
   		 		case 2:
   		 		consulta(); //chamada de funções.
   		  		break;
   		  		
   		  		case 3:
   		  		deletar(); //chamada de funções.
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Está opção não está disponível!\n"); //Função responsavel por imprimir algo na tela
		  		system("pause"); // pausar sistema
				break; // fim da seleção
			}
		
	    }	
   	}
