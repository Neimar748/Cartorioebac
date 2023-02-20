#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bilbioteca de alocação de espaço em momória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro(){ //Função responsável por cadastrar os usuários no sistema
	
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file," - "); //está separando as informações no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file," - "); //está separando as informações no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a cadastrado: "); //Coletando a informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file," - "); //está separando as informações no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //o sistema para na tela	
	
		

}

int consulta(){ //Função responsável por consultar os usuários no sistema
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	//Início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //prucura o usuário cadastrado
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //busca no sistema o arquivo
	file = fopen(cpf,"r"); //faz leitura do arquivo o "r" significa ler
	
	
	if(file == NULL){ //retorna se o usuário cadastrado não se encontrato no sistema
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //apresenta as informações do usuário cadastrado
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	fclose(file); //fecha o arquivo de consulta
	
	system("pause"); //o sistema para na tela
}

int deletar(){ //Função responsável por deletar os usuários no sistema
	
	//Início criação de variáveis/string
	char cpf[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser delatado: "); //busca osuário cadastrado no sistema
	scanf("%s",cpf); //%s refere-se a string
		
	FILE *file; //busca no sistema o arquivo
	file = fopen(cpf,"r"); //faz leitura do arquivo o "r" significa ler
	
	if(file == NULL){ //retorna se o usuário informado não se encontra no sistema
		printf("O usuário não se encontra no base de dados!\n");
		system("pause");
		
	}
	else{ //retorna se o usuário é encontrado no sistema
		printf("Usuário deletado com sucesso!\n");
		fclose(file);
		system("pause");
	}
	
	remove(cpf); //remove o usuário no sistema
}

int main(){
	
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
			
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nome.\n");
		printf("\t2 - Consultar nomes.\n");
		printf("\t3 - Deletar nomes.\n");
		printf("\t4 - Sair do sistema.\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenamento a escolha do usuário
	
		system("cls"); //reponsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1: 
			registro(); //chamada de funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
	
		
	} //Fim da seleção
	
		
}
