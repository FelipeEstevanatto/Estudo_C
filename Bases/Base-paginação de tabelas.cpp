//Sistema de paginação de dados (arquivo binário) -- ainda a ser feito

//ainda quebrado, não faz nada, sistema em construção

#include <stdio.h> 			 //biblioteca base
#include <conio.h>			//frufrus para o código
#include <windows.h>		//definições da função gotoxy
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <wincon.h>
#include <winuser.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;

//definição do tamanho da tela para o uso do gotoxy
//text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 160, 38, 1, 1}; // Define os limites para linha (35) e coluna (80)

//text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1};

void consulta_geral();
void abrir_arquivo();
void gera_tabela(int c);
void gotoxy(int x, int y);

FILE *fp; //Ponteiro para arquivo

int dados[30];

main()
{
	abrir_arquivo();
	for(int i=0; i++; i<30)
		{
			dados[i]=i;
			fwrite(dados, sizeof(dados), 30, fp);
			if(fwrite(&dados, sizeof(dados[i]), 30, fp) != 1) 
			{
			gotoxy(29, 22); printf("Erro na escrita do arquivo!");
			}
		}
	consulta_geral();
}

void consulta_geral()
{
	int cont_tuplas = - 1; // Contador de registros 
	
	char retornar = '0';
	
	rewind(fp);
	while(fread(&dados, sizeof(dados), 1, fp) 	== 1)
	{
		cont_tuplas++;
	}
	printf("tuplas = %d", cont_tuplas);
	int contl = 1, limite, limiteAnte, pag, linha, pag_limite; // Variaveis Auxiliares
	
	pag = 1;
	
	pag_limite = ceil(cont_tuplas / 12);  
	
	gera_tabela(5);	// Gera borda e tabela inicial
	
	do
	{			
		limite = (12 * pag); // 12 linhas de dados por página (oq cabe na tabela)
		
		limiteAnte = (12 * (pag - 1));  // Limite da página anterior 
			
		gotoxy(20, 31); printf("Pressione 0 para fechar o programa");
		
		gotoxy(76, 4);	printf("%d", pag); // Número da página 
		
		contl= 1;    //reseta o contador de linha
		linha= 7;	//reseta a linha inicial(pmr da tabela) em q os dados começarão a ser colocados
		
		rewind(fp);
		
		int num=0;
		
		while(fread(&dados, sizeof(dados), 1, fp) == 1) // segue até o fim do arquivo
		{			
			if(contl > limiteAnte) //se a linha atual for maior que o limite inferior:
			{
					printf("%d",dados[num]);
					linha += 2; 
					num++;
			}
			
			if(contl == limite) break; //se a linha atual for igual ao limite quebra
			else contl++; //adiciona mais uma linha ao contador
		}
		
		gotoxy(20,34); 
		
		fflush(stdin);
		
		retornar = getch();
		
		switch(retornar)
		{
			case char(77): // Se a seta direita for pressionada
				if(pag <= pag_limite) 
				{
					pag++; // Avança a página | Limita pag a 10 
					rewind(fp);		//seta a leitura do arquivo na posição inicial do arquivo ("1º linha e coluna")	
					gera_tabela(5);
				}	
				break;
				
			case char(75): // Se a seta da esquerda
				if(pag > 1) 				
				{
					pag--; // Volta a pagina
					rewind(fp);	
					gera_tabela(5);	
				} 			
				break;
		}
		
	}while (retornar != '0');  
		
	// Se 0 for pressionado 
	
	fclose(fp);	// fecha o arquivo
	return;    // Retorna ao submenu			
}

void abrir_arquivo()
{
	if((fp = fopen("dados.bin", "ab+")) == NULL) 
	{
		system("cls");
		gotoxy(35, 16); printf("Erro na abertura do arquivo!\n"); //caso haja um problema com o arquivo
		exit(1);
	}
}

void gera_tabela(int c)
{
	gotoxy(6,c);	printf("-------------------------------------------\n");
	for(int i=0; i<20; i++)
	{
		gotoxy(60,c+i+1); printf("|                                          |\n");
		//printf("%d\t",dados[i]);
	}
		
}

void gotoxy(int x, int y)	// Move o cursor para a coluna e linha desejada
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}


