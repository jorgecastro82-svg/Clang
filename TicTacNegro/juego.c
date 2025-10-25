#include <stdio.h>
#define REN 11

#define COL 11

void Imptablero(char *);

void Inicirespuesta(char *);

void Imagenrespuesta(char *);

void printfRojo(char*);

void printfAzul(char*);

int main(){
    printfRojo("Hola negros\n");
    printfAzul("Hola negros\n");
    char respuesta[REN][COL];
	Inicirespuesta((char*)respuesta);
	Imagenrespuesta((char*)respuesta);
	Imptablero((char*)respuesta);

    return 0;
}

void printfRojo(char *cadena){
    printf("\033[1;31m%s\033[0m",cadena);
}

void printfAzul(char *cadena){
    printf("\033[1;34m%s\033[0m",cadena);
}

void Imptablero(char *matriz){
	

	printf("\n");
	int i=0,j=0;

		for(i=0;i<REN;i++){
			printf("\n");
			for(j=0;j<COL;j++){
				printfRojo("%c",matriz[(i*COL)+j]);

			}
		}
	}
void Inicirespuesta(char *matriz){	
			int i,j;
			for(i=0;i<REN;i++){
			for(j=0;j<COL;j++){
				matriz[(i*COL)+j]=' ';

			}
			}
}
void Imagenrespuesta(char *matriz){
			int i,j;
			for(i=0;i<(REN)-(8);i++){
			for(j=0;j<(COL)-(8);j++){
				if(i+j==1||i+j==3){
				matriz[(i*COL)+j]=254;
				}

			}
			}
}