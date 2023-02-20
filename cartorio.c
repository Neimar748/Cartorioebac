#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bilbioteca de aloca��o de espa�o em mom�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro(){ //Fun��o respons�vel por cadastrar os usu�rios no sistema
	
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file," - "); //est� separando as informa��es no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file," - "); //est� separando as informa��es no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file," - "); //est� separando as informa��es no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //o sistema para na tela	
	
		

}

int consulta(){ //Fun��o respons�vel por consultar os usu�rios no sistema
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //prucura o usu�rio cadastrado
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //busca no sistema o arquivo
	file = fopen(cpf,"r"); //faz leitura do arquivo o "r" significa ler
	
	
	if(file == NULL){ //retorna se o usu�rio cadastrado n�o se encontrato no sistema
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //apresenta as informa��es do usu�rio cadastrado
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	fclose(file); //fecha o arquivo de consulta
	
	system("pause"); //o sistema para na tela
}

int deletar(){ //Fun��o respons�vel por deletar os usu�rios no sistema
	
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser delatado: "); //busca osu�rio cadastrado no sistema
	scanf("%s",cpf); //%s refere-se a string
		
	FILE *file; //busca no sistema o arquivo
	file = fopen(cpf,"r"); //faz leitura do arquivo o "r" significa ler
	
	if(file == NULL){ //retorna se o usu�rio informado n�o se encontra no sistema
		printf("O usu�rio n�o se encontra no base de dados!\n");
		system("pause");
		
	}
	else{ //retorna se o usu�rio � encontrado no sistema
		printf("Usu�rio deletado com sucesso!\n");
		fclose(file);
		system("pause");
	}
	
	remove(cpf); //remove o usu�rio no sistema
}

int main(){
	
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
			
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nome.\n");
		printf("\t2 - Consultar nomes.\n");
		printf("\t3 - Deletar nomes.\n");
		printf("\t4 - Sair do sistema.\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenamento a escolha do usu�rio
	
		system("cls"); //repons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1: 
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema!\n");
			return 0;
			break;
											
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
	
		
	} //Fim da sele��o
	
		
}
