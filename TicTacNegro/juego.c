#include <stdio.h>
#include <stdlib.h>
#define REN 11

#define COL 11

int menu(char *,int*,int*,int*,int*,int*,int*);

void Imptablero(char *);

void Inicirespuesta(char *);

void Imagenrespuestamediana(char *);

void Imagenrespuestachica(char *);

void Imagenrespuestagrande(char *);

void tamano(char*,int*,int*,int*,int*,int*,int*);

void printfRojoChar(char);

void printfAzulChar(char);

int main(){
	int grandeT1=0;
	int chicoT1=0;
	int medT1=0;
	int grandeT2=0;
	int chicoT2=0;
	int medT2=0;
    char respuesta[REN][COL];
    int opc=0;
    do{
        opc=menu((char*)respuesta,&grandeT1,&grandeT2,&medT1,&medT2,&chicoT1,&chicoT2);
    }while(opc==0);
	printf("\n");
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
void Imagenrespuestamediana(char *matriz){
			int i,j;
			for(i=0;i<(REN)-(8);i++){
			for(j=0;j<(COL)-(8);j++){
				if(i+j==1||i+j==3){
				matriz[(i*COL)+j]=254;
				}

			}
			}
}
void Imagenrespuestachica(char *matriz){
			int i,j;
			for(i=0;i<(REN)-(8);i++){
			for(j=0;j<(COL)-(8);j++){
				if(i==1&&j==1){
				matriz[(i*COL)+j]=254;
				}

			}
			}
}
void Imagenrespuestagrande(char *matriz){
	int i,j;
	for(i=0;i<(REN)-(8);i++){
		for(j=0;j<(COL)-(8);j++){
			if(i==0 || j==0||j==2||i==2){
				matriz[(i*COL)+j]=254;
			}

		}
	}
}
int menu(char* respuesta,int*g1,int*g2,int*m1,int*m2,int*c1,int*c2){
    Inicirespuesta(respuesta);
	tamano(respuesta,g1,g2,m1,m2,c1,c2);
	Imptablero(respuesta);
	
    return 1;
}

void tamano(char* respuesta,int* g1,int* g2,int* m1,int* m2,int* c1,int* c2){
	int pz=0;
	printf("Escoga el tamano de la pieza\n");
	printf("[1]Grande\n");
	printf("[2]mediano\n");
	printf("[3]chico\n");
	scanf("%d",&pz);
	switch(pz){
		case 1:
		Imagenrespuestagrande(respuesta);
		break;
		case 2:
		Imagenrespuestamediana(respuesta);
		break;
		case 3:
		Imagenrespuestachica(respuesta);
		break;
		default:
		printf("\nOpcion incorrecta, escoja otra vez\n");
		break;
	}
}
