//script base de um menu de setas em C++ que busca ser o mais explicado possível

#include <stdio.h> 			 //biblioteca base
#include <conio.h>			//frufrus para o código
#include <windows.h>		//definições da função gotoxy

#define Linicial 6   	//Definir valor da linha inicial do menu
#define Lfinal 12		//definir o valor da linha final
#define Coluna 10		//definir a coluna em que a seta vai se movimentar ( valor Y )

//definição do tamanho da tela para o uso do gotoxy
text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 160, 38, 1, 1}; // Define os limites para linha (35) e coluna (80)

//cabeçalho das funções conio.c
void gotoxy(int x, int y);
void textbackground(int newcolor);

int menu(int ini, int fim, int col)
{
	int aux = ini; // Recebe posição da seta
	int entrada; // Armazena entrada do teclado
	int espaco = 2; //espaçamento entre as opções do menu, nesse caso é 2
	
	do
	{
		gotoxy(col,aux); printf("%c", 62);	// o char da setinha (62 = >) é impresso sempre no começo do loop
			
		//fflush(stdin); aqui caso se tenha usado scanf antes
		
		entrada = getch(); 
		
		gotoxy(col,aux); printf(" ");		//Limpa o local inicial onde a setinha estava com um espaço vazio
		
		switch(entrada) //esse switch analisa qual tecla foi digitada do menu de setinha (cima ou baixo)
		{
			case 72: // Seta para cima
				aux -= espaco; 	
				
				if(aux < ini) aux  = fim;  //se já estiver no topo das opções e clicar para cima novamente a seta desce para a ultima opção dando uma impressão de loop de opções

				gotoxy(col,aux); printf("%c", 62); //printa a setinha no local novo escolhido
				break;
				
			case 80: // Seta para baixo
				aux += espaco;
					
				if(aux > fim) aux = ini; //se ja estiver no fim... 
					
				gotoxy(col,aux); printf("%c", 62);
				break;	
				
			case 13: //quando apertar enter manda o resultado escolhido
				return (aux - ini)/espaco; // Retorna o valor da opção seleciona => inicia em 0
										//Valor atual da seta - valor inicial/espaçamento entre opções
				break;	
		}
		
	}while(true);
}

main()
{
	
	textbackground(8);		system("cls");  //só para trocar a cor de fundo do terminal
	
	gotoxy(8,4);	printf("Script base para um menu de navegar com setas");
	
	gotoxy(12,6);	printf("Resultado 1"); 	//o Y da primeira opção deve ser a definição da Linicial
	gotoxy(12,8);	printf("Resultado 2");
	gotoxy(12,10);	printf("Resultado 3");
	gotoxy(12,12);	printf("Resultado 4");	//o Y da ultima opção deve ser a definição da Lfinal

	//=======================Chamada da função de menu e apresentação do resultado=============================================
	
	int resposta = menu(Linicial,Lfinal,Coluna);  //é gerada uma int que armazenará o return da função de menu
	switch(resposta)							  //que depois por um switch vai ler esse resultado e apresentar o que deve
		{
		case 0:
			printf("codigo do resultado 1");
			//codigo do resultado 1
			break;
		case 1:
			printf("codigo do resultado 2");
			//codigo do resultado 2
			break;
		case 2:
			printf("codigo do resultado 3");
			//codigo do resultado 3
			break;
		case 3:
			printf("codigo do resultado 4"); 
			//codigo do resultado 4
			break;	
		};	
}
	
	//===============================Funções conio.c=========================================================

void gotoxy(int x, int y)	// Move o cursor para a coluna e linha desejada
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void textbackground(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}
