#include <stdio.h>
#define REN 11

#define COL 11

int menu(char *);

void Imptablero(char *);

void Inicirespuesta(char *);

void Imagenrespuesta(char *);

void printfRojoChar(char);

void printfAzulChar(char);

int main(){
    char respuesta[REN][COL];
    int opc=0;
    do{
        opc=menu((char*)respuesta);
    }while(opc==0);

    return 0;
}

void printfRojoChar(char c){
    printf("\033[1;31m%c\033[0m",c);
}

void printfAzulChar(char c){
    printf("\033[1;34m%c\033[0m",c);
}

void Imptablero(char *matriz){
	

	printf("\n");
	int i=0,j=0;

		for(i=0;i<REN;i++){
			printf("\n");
			for(j=0;j<COL;j++){
				printfRojoChar(matriz[(i*COL)+j]);

			}
		}
	}
void Inicirespuesta(char *matriz){	
			int i,j;
			for(i=0;i<REN;i++){
			for(j=0;j<COL;j++){
				matriz[(i*COL)+j]=' ';
                if(j==3||j==7){
                    matriz[(i*COL)+j]=124;
                }
                if(i==3||i==7){
                    matriz[(i*COL)+j]=196;
                }


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

int menu(char* respuesta){
    Inicirespuesta(respuesta);
	Imagenrespuesta(respuesta);
	Imptablero(respuesta);
    return 1;
}