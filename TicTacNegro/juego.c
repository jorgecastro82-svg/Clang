#include <stdio.h>
#include <stdlib.h>
#define REN 11

#define COL 11

int menu(char *,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*);

void Imptablero(char *);

void Inicirespuesta(char *);

void Imagenrespuestamediana(char *,int*,int*,int*,int *,int*,int*);

void Imagenrespuestachica(char *,int*,int*,int*,int *,int*,int*);

void Imagenrespuestagrande(char *,int*,int*,int*,int *,int*,int*);

int tamano(char*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int *,int*);

void printfRojoChar(char);

void printfAzulChar(char);

int cuadrante(int*);

void separacion(int,int*,int*,int *,int*);

int main(){
	int grandeT1=0;
	int chicoT1=0;
	int medT1=0;
	int grandeT2=0;
	int chicoT2=0;
	int medT2=0;
	int player=1,ren=0,col=0,ci=0,cj=0,otra=0;
    char respuesta[REN][COL];
    int opc=0;
	do{
		Inicirespuesta((char*)respuesta);
    do{
        opc=menu((char*)respuesta,&grandeT1,&grandeT2,&medT1,&medT2,&chicoT1,&chicoT2,&player,&ren,&col,&ci,&cj);
    }while(opc==0);
	printf("\n");
	printf("Quieres jugar otra? 0=si cualquier numero =No\n");
	scanf("%d",&otra);
	}while(otra==0);
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
				printf("%-2c",matriz[(i*COL)+j]);
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
void Imagenrespuestamediana(char *matriz, int* m,int*r,int*c,int*ci,int*cj,int *p){
			int i,j;
			for(i=(*ci);i<(REN)-(*r);i++){
			for(j=(*cj);j<(COL)-(*c);j++){
				if(((i+j)-((*ci)+(*cj)))==1||((i+j)-((*ci)+(*cj)+1))==2){
					if(((*p)%2)!=0){	//if para ver si es el jugador 1
						matriz[(i*COL)+j]=254;
					}
					if(((*p)%2)==0){	//if para ver si es el jugador 2
						matriz[(i*COL)+j]=250;
					}
				}
			}
			}
			(*m)++;
}
void Imagenrespuestachica(char *matriz,int*cc,int*r,int*c,int*ci,int*cj,int *p){
			int i,j;
			for(i=(*ci);i<(REN)-(*r);i++){
			for(j=(*cj);j<(COL)-(*c);j++){
				if((i-(*ci))==1&&(j-(*cj))==1){
					if(((*p)%2)!=0){	//if para ver si es el jugador 1
						matriz[(i*COL)+j]=254;
					}
					if(((*p)%2)==0){	//if para ver si es el jugador 2
						matriz[(i*COL)+j]=250;
					}
				}

			}
			}
		(*cc)++;
}
void Imagenrespuestagrande(char *matriz,int* g,int*r,int*c,int*ci,int*cj,int *p){
	int i,j;
		for(i=(*ci);i<(REN)-(*r);i++){
			for(j=(*cj);j<(COL)-(*c);j++){
			if((i-(*ci))==0 || (j-(*cj))==0||(j-(*cj))==2||(i-(*ci))==2){
					if(((*p)%2)!=0){	//if para ver si es el jugador 1
						matriz[(i*COL)+j]=254;
					}
					if(((*p)%2)==0){	//if para ver si es el jugador 2
						matriz[(i*COL)+j]=250;
					}
			}

		}
	}
	(*g)++;
}
int cuadrante(int*p){
	int ddx=0,opc,jugador;
	if((*p)%2!=0)
	jugador=1;
	else 
	jugador=2;
	printf("Donde quieres poner tu pieza jugador %d?\n",jugador);
	do{
	scanf("%d",&opc);
	if(opc<1||opc>9){
		printf("\nfuera de rango\n");
	}
	else
	ddx=1;
	}while(ddx=0);
	return (opc-1);
}
void separacion(int x,int* r,int* c,int *ci,int*cj ){
	switch(x){
		case 0:
			(*ci)=0;
			(*cj)=0;
			(*r)=8;
			(*c)=8;
		break;
		case 1:
			(*ci)=0;
			(*cj)=4;
			(*r)=8;
			(*c)=4;
		break;
		case 2:			
			(*ci)=0;
			(*cj)=8;
			(*r)=8;
			(*c)=0;
		break;
		case 3:			
			(*ci)=4;
			(*cj)=0;
			(*r)=4;
			(*c)=8;
		break;
		case 4:			
			(*ci)=4;
			(*cj)=4;
			(*r)=4;
			(*c)=4;
		break;
		case 5:			
			(*ci)=4;
			(*cj)=8;
			(*r)=4;
			(*c)=0;
		break;
		case 6:			
			(*ci)=8;
			(*cj)=0;
			(*r)=0;
			(*c)=8;
		break;
		case 7:			
			(*ci)=8;
			(*cj)=4;
			(*r)=0;
			(*c)=4;
		break;
		case 8:			
			(*ci)=8;
			(*cj)=8;
			(*r)=0;
			(*c)=0;
		break;
	}
}
int menu(char* respuesta,int*g1,int*g2,int*m1,int*m2,int*c1,int*c2,int*player,int* r,int*c,int*ci,int*cj){
	int opc=0,xdd=0;
    
	xdd=cuadrante(player);
	separacion(xdd,r,c,ci,cj);
	do{
	opc=tamano(respuesta,g1,g2,m1,m2,c1,c2,player,r,c,ci,cj);
	}while(opc==0);
	Imptablero(respuesta);
	(*player)++;
	if((*player)==13){
    return 1;
	}
	return 0;
}

int tamano(char* respuesta,int* g1,int* g2,int* m1,int* m2,int* c1,int* c2,int* p,int*r,int*c,int*ci,int*cj){
	int pz=0;
	printf("\nEscoga el tamano de la pieza\n");
	printf("[1]Grande\n");
	printf("[2]mediano\n");
	printf("[3]chico\n");
	scanf("%d",&pz);
	switch(pz){
		case 1:
			if(((*p)%2)!=0){
				if((*g1)<2){
					Imagenrespuestagrande(respuesta,g1,r,c,ci,cj,p);
					return 1;
				}
				else{
					printf("Se te acabaron las piezas grandes jugador 1\n");
					return 0;
				}
			}
			 if(((*p)%2)==0){
				if((*g2)<2){
					Imagenrespuestagrande(respuesta,g2,r,c,ci,cj,p);
					return 1;
				}
				else{
					printf("Se te acabaron las piezas grandes jugador 2\n");
					return 0;
				}
			}
		break;
		case 2:
					if(((*p)%2)!=0){
				if((*m1)<2){
					Imagenrespuestamediana(respuesta,m1,r,c,ci,cj,p);
					return 1;
				}
				else{
					printf("Se te acabaron las piezas medianas jugador 1\n");
					return 0;
				}
			}
			 if(((*p)%2)==0){
				if((*m2)<2){
					Imagenrespuestamediana(respuesta,m2,r,c,ci,cj,p);
					return 1;
				}
				else{
					printf("Se te acabaron las medianas jugador 2\n");
					return 0;
				}
			}

		break;
		case 3:
							if(((*p)%2)!=0){
				if((*c1)<2){
					Imagenrespuestachica(respuesta,c1,r,c,ci,cj,p);
					return 1;
				}
				else{
					printf("Se te acabaron las piezas chicas jugador 1\n");
					return 0;
				}
			}
			 if(((*p)%2)==0){
				if((*c2)<2){
					Imagenrespuestachica(respuesta,c2,r,c,ci,cj,p);
					return 1;
				}
				else{
					printf("Se te acabaron las chicas jugador 2\n");
					return 0;
				}
			}
		break;
		default:
		printf("\nOpcion incorrecta, escoja otra vez\n");
		break;
	}
}
