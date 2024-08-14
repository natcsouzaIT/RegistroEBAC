#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca para armazenar strings

int registro ()//fun��o respons�vel por cadastrar usu�rios no sistema
{ 
	//in�cio da cria��o de vari�veis ou strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis
	
	printf ("Digite o CPF a ser cadastrado: ");//coletando informa��es digitadas pelo usu�rio
	scanf ("%s", cpf); //para coletar strings
	
	strcpy (arquivo, cpf); //respons�vel por armazenar os valores das strings

	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); //abre o arquivo pra criar a escrita
	fprintf(file, cpf); //salva o valor da vari�vel no arquivo
	fclose (file); //fecha o arquivo

	file = fopen (arquivo, "a"); //abre pra atualizar
	fprintf (file, "," ); //salva o valor da vari�vel no arquivo
	fclose (file); //fecha o arquivo

	printf ("Digite o primeiro nome: ");//pedindo informa��es ao usu�rio
	scanf ("%s", nome);//coletando as informa��es solicitadas
	
	file = fopen (arquivo, "a");//abre pra atualizar
	fprintf (file, nome);//atualiza o conte�do do arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre pra atualizar
	fprintf (file, " " );//atualiza o arquivo pra espa�ar nome e sobrenome
	fclose (file); //fecha o arquivo
	
	printf ("Digite o sobrenome: ");//solicita informa��es ao usu�rio
	scanf ("%s", sobrenome);//coleta as informa��es fornecidas na vari�vel
	
	file = fopen (arquivo, "a");//abre pra atualizar
	fprintf (file, sobrenome);//atualiza o conte�do do arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a");//abre pra atualizar
	fprintf (file, "," );//atualiza o conte�do do arquivo
	fclose (file); //fecha o arquivo
	
	printf ("Digite o cargo: ");//solicita informa��es ao usu�rio
	scanf ("%s", cargo);//coleta as informa��es fornecidas na vari�vel
	
	file = fopen (arquivo, "a");//abre o arquivo pra atualizar
	fprintf (file, cargo);//atualiza o conte�do do arquivo
	fclose (file); //fecha o arquivo

	

	system("pause");//interrompe a execu��o
}

int consulta ()//fun��o respons�vel por consultar usu�rios no sistema
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
		printf("Arquivo n�o localizado.\n");
		
	}

	{
		while (fgets(conteudo, 200, file) != NULL)
		printf ("\nEsses s�o os dados cadastrados para esse usu�rio: ");
		printf ("%s", conteudo);
		printf ("\n\n");
		
	}
	
	system ("pause");
	
}

int deletar ()//fun��o respons�vel por deletar usu�rios no sistema
{
	char cpf [40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	
	if (file == NULL)
	{
		printf ("Usu�rio deletado ou inexistente.\n");
		system ("pause");
	}
	
	system ("pause");
}


int main()//in�cio da execu��o do programa
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //respons�vel por limpar a tela
			
		setlocale(LC_ALL, "Portuguese");
		printf("___Cart�rio da EBAC___\n\n");
		printf("Escolha a op��o desejada no menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:");
	
		scanf ("%d", &opcao);//coleta a op��o do usu�rio
	
		system("cls");//respons�vel por limpar a tela
	
	  	switch (opcao)//chama a fun��o de acordo com a escolha do usu�rio
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
			printf("Op��o Inv�lida.\n");
			system("pause");
			break;	
	    } //fim da sele��o
    }	
}


