#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca para armazenar strings

int registro ()//função responsável por cadastrar usuários no sistema
{ 
	//início da criação de variáveis ou strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis
	
	printf ("Digite o CPF a ser cadastrado: ");//coletando informações digitadas pelo usuário
	scanf ("%s", cpf); //para coletar strings
	
	strcpy (arquivo, cpf); //responsável por armazenar os valores das strings

	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); //abre o arquivo pra criar a escrita
	fprintf(file, cpf); //salva o valor da variável no arquivo
	fclose (file); //fecha o arquivo

	file = fopen (arquivo, "a"); //abre pra atualizar
	fprintf (file, "," ); //salva o valor da variável no arquivo
	fclose (file); //fecha o arquivo

	printf ("Digite o primeiro nome: ");//pedindo informações ao usuário
	scanf ("%s", nome);//coletando as informações solicitadas
	
	file = fopen (arquivo, "a");//abre pra atualizar
	fprintf (file, nome);//atualiza o conteúdo do arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre pra atualizar
	fprintf (file, " " );//atualiza o arquivo pra espaçar nome e sobrenome
	fclose (file); //fecha o arquivo
	
	printf ("Digite o sobrenome: ");//solicita informações ao usuário
	scanf ("%s", sobrenome);//coleta as informações fornecidas na variável
	
	file = fopen (arquivo, "a");//abre pra atualizar
	fprintf (file, sobrenome);//atualiza o conteúdo do arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a");//abre pra atualizar
	fprintf (file, "," );//atualiza o conteúdo do arquivo
	fclose (file); //fecha o arquivo
	
	printf ("Digite o cargo: ");//solicita informações ao usuário
	scanf ("%s", cargo);//coleta as informações fornecidas na variável
	
	file = fopen (arquivo, "a");//abre o arquivo pra atualizar
	fprintf (file, cargo);//atualiza o conteúdo do arquivo
	fclose (file); //fecha o arquivo

	

	system("pause");//interrompe a execução
}

int consulta ()//função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo [200];
	
	
	printf ("Digite o cpf a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{ 	
		printf("Arquivo não localizado.\n");
		
	}

	{
		while (fgets(conteudo, 200, file) != NULL)
		printf ("\nEsses são os dados cadastrados para esse usuário: ");
		printf ("%s", conteudo);
		printf ("\n\n");
		
	}
	
	system ("pause");
	
}

int deletar ()//função responsável por deletar usuários no sistema
{
	char cpf [40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	
	if (file == NULL)
	{
		printf ("Usuário deletado ou inexistente.\n");
		system ("pause");
	}
	
	system ("pause");
}


int main()//início da execução do programa
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsável por limpar a tela
			
		setlocale(LC_ALL, "Portuguese");
		printf("___Cartório da EBAC___\n\n");
		printf("Escolha a opção desejada no menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:");
	
		scanf ("%d", &opcao);//coleta a opção do usuário
	
		system("cls");//responsável por limpar a tela
	
	  	switch (opcao)//chama a função de acordo com a escolha do usuário
    	{
			case 1:	
			registro();
			break;
		
			case 2:
			consulta();				
			break;	
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Opção Inválida.\n");
			system("pause");
			break;	
	    } //fim da seleção
    }	
}


