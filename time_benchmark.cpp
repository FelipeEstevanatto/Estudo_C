#include <iostream>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <sys/time.h>

#define resolutionX 64
#define resolutionY 32

// 2 métodos de medir tempos de processamento de blocos de código (tempo que o SO demora para processar ele)

void setCursorPosition(int x, int y);
void updateFrame(char quadroAtual[resolutionY][resolutionX], char quadroFuturo[resolutionY][resolutionX]);

//pro metodo 2
struct timeval  
	tv1, tv2;

int main(){
	
	char quadroAtual[resolutionY][resolutionX], quadroFuturo[resolutionY][resolutionX];
	int p = 0;
	
	for(int i=0; i < resolutionY; i++){
		for( int j=0 ; j < resolutionX ; j++){
			quadroAtual[i][j] = 'a';
			quadroFuturo[i][j] = 'a';
			printf("%c",quadroAtual[i][j]);
		}
		printf("\n");
	}
	
	do{
		
		//Método 1
		clock_t begin = clock();
		
		//Método 2
		gettimeofday(&tv1, NULL);
		
		//=============================================================
		//Algum processamento "pesado" pra ele fazer: exemplo no caso
		//=============================================================
		
		
		for(int i=2; i < resolutionY/2 ; i++){
			for(int j=4; j < resolutionX/2 ; j++){
				quadroFuturo[i][j] = 'b';
			}
		}
		
		updateFrame(quadroAtual,quadroFuturo);
		
		//=============================================================
		//pegar os tempos
		clock_t end = clock();
		gettimeofday(&tv2, NULL);
		
		//Resultados dos métodos
	
		setCursorPosition(68,1+p); printf("%f sec",(double)(end - begin) / CLOCKS_PER_SEC);
		//esse é mais preciso
		setCursorPosition(90,1+p); printf ("Total time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));

		p++;
	}while(p < 100);
	
	setCursorPosition(0,101);	
}

void updateFrame(char quadroAtual[resolutionY][resolutionX], char quadroFuturo[resolutionY][resolutionX]){
	for(int i=0; i < resolutionY; i++){
		for(int j=0; j < resolutionX; j++){
			if(quadroAtual[i][j] != quadroFuturo[i][j]){
				setCursorPosition(j,i); 
				printf("%c",quadroFuturo[i][j]);
			}			
		}
	}
}

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}