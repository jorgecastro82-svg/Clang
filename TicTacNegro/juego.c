#include <stdio.h>
#include <stdlib.h>
#define REN 11 //declaracion de constante REN

#define COL 11	//declaracion de constante COL
//prototipo de la funcion menu
int menu(char *,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*);
//prototipo de la funcion Imptablero
void Imptablero(char *);
//prototipo de la funcion Inicirespuesta
void Inicirespuesta(char *);
//prototipo de la funcion Imagenrespuestamediana
void Imagenrespuestamediana(char *,int*,int*,int*,int *,int*,int*);
//prototipo de la funcion Imagenrespuestachica
void Imagenrespuestachica(char *,int*,int*,int*,int *,int*,int*);
//prototipo de la funcion Imagenrespuestagrande
void Imagenrespuestagrande(char *,int*,int*,int*,int *,int*,int*);
//prototipo de la funcion tamano
int tamano(char*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int *,int*);
//prototipo de la funcion printf rojo
void printfRojoChar(char);
//prototipo de la funcion printf azul
void printfAzulChar(char);
//prototipo de la funcion cuadrante
int cuadrante(int*);
//prototipo de la funcion separacion
void separacion(int,int*,int*,int *,int*);

int main(){
	//declaracion de variables en main que se usaran como apuntadores en todo el codigo
	int grandeT1=0;
	int chicoT1=0;
	int medT1=0;
	int grandeT2=0;
	int chicoT2=0;
	int medT2=0;
	int player=1,ren=0,col=0,ci=0,cj=0,otra=0;
	//declaracion de la matriz principal
    char respuesta[REN][COL];
	//variable para salida del ciclo do
    int opc=0;
	do{ //ciclo do while para ver si quiere jugar otra partida
		Inicirespuesta((char*)respuesta);
    do{	//ciclo do while para salirse cuando encuentre ganador o sea empate
		//llamada a la funcion menu donde se realizara casi todos los procedimientos
		//recibira un int para ver si continuar o salir
        opc=menu((char*)respuesta,&grandeT1,&grandeT2,&medT1,&medT2,&chicoT1,&chicoT2,&player,&ren,&col,&ci,&cj);
    }while(opc==0);//condicional para salir
	printf("\n");
	printf("Quieres jugar otra? 0=si cualquier numero =No\n");	//pregunta para ver si quiere seguir jugando
	scanf("%d",&otra);	//scanf para ver respuesta
	}while(otra==0);	//condicional para cerrar programa
    return 0;
}

void printfRojoChar(char c){
    printf("\033[1;31m%c\033[0m",c);
}

void printfAzulChar(char c){
    printf("\033[1;34m%c\033[0m",c);
}

void Imptablero(char *matriz){	//funcion para imprimir todo el tablero
	

	printf("\n");
	int i=0,j=0;

		for(i=0;i<REN;i++){
			printf("\n");
			for(j=0;j<COL;j++){	//ciclo for anidado para la impresion
				printf("%-2c",matriz[(i*COL)+j]);
			}
		}
	}
void Inicirespuesta(char *matriz){	//funcion para inicializar la matriz
			int i,j;
			for(i=0;i<REN;i++){
			for(j=0;j<COL;j++){
				matriz[(i*COL)+j]=' ';	//da un valor "Nulo" a ese lugar
                if(j==3||j==7){
                    matriz[(i*COL)+j]=124; //coloca lineas verticales
                }
                if(i==3||i==7){
                    matriz[(i*COL)+j]=196;  //coloca lineas horizontales
                }
			}
			}
}
void Imagenrespuestamediana(char *matriz, int* m,int*r,int*c,int*ci,int*cj,int *p){
			int i,j;
			//for que usara los apuntadores para ver donde iniciar y donde terminar en renglones
			for(i=(*ci);i<(REN)-(*r);i++){
			//for que usara los apuntadores para ver donde iniciar y donde terminar en columnas
			for(j=(*cj);j<(COL)-(*c);j++){
				//if para comprobar si cumple la condicion y poner el char correspondiente
				if(((i+j)-((*ci)+(*cj)))==1||((i+j)-((*ci)+(*cj)+1))==2){
					if(((*p)%2)!=0){	//if para ver si es el jugador 1
						matriz[(i*COL)+j]=254;	//pone un cuadrado grande
					}
					if(((*p)%2)==0){	//if para ver si es el jugador 2
						matriz[(i*COL)+j]=250;	//pone un cuadrado chico 
					}
				}
			}
			}
			(*m)++;	//aumento para comprobar si ya usaron el maximo
}
void Imagenrespuestachica(char *matriz,int*cc,int*r,int*c,int*ci,int*cj,int *p){
			int i,j;
			//for que usara los apuntadores para ver donde iniciar y donde terminar en renglones
			for(i=(*ci);i<(REN)-(*r);i++){
			//for que usara los apuntadores para ver donde iniciar y donde terminar en columnas
			for(j=(*cj);j<(COL)-(*c);j++){
				//if para comprobar si cumple la condicion y poner el char correspondiente
				if((i-(*ci))==1&&(j-(*cj))==1){	
					if(((*p)%2)!=0){	//if para ver si es el jugador 1
						matriz[(i*COL)+j]=254;	//pone un cuadrado grande
					}
					if(((*p)%2)==0){	//if para ver si es el jugador 2
						matriz[(i*COL)+j]=250;	//pone un cuadrado chico
					}
				}

			}
			}
		(*cc)++;	//incremento para llevar contado los que hay en el tablero
}
void Imagenrespuestagrande(char *matriz,int* g,int*r,int*c,int*ci,int*cj,int *p){
	int i,j;
		//for que usara los apuntadores para ver donde iniciar y donde terminar en renglones
		for(i=(*ci);i<(REN)-(*r);i++){
			//for que usara los apuntadores para ver donde iniciar y donde terminar en columnas
			for(j=(*cj);j<(COL)-(*c);j++){
				//if para comprobar si cumple la condicion y poner el char correspondiente
				if((i-(*ci))==0 || (j-(*cj))==0||(j-(*cj))==2||(i-(*ci))==2){
					if(((*p)%2)!=0){	//if para ver si es el jugador 1
						matriz[(i*COL)+j]=254;	//pone un cuadrado grande
					}
					if(((*p)%2)==0){	//if para ver si es el jugador 2
						matriz[(i*COL)+j]=250;	//pone un cuadrado chico
					}
				}

			}
		}
	(*g)++;		//incremento para llevar contado los que hay en el tablero
}
int cuadrante(int*p){	//funcion para asignar el cuadrante
	int ddx=0,opc,jugador;
	if((*p)%2!=0)	//if para ver cual es el jugador
	jugador=1;
	else 
	jugador=2;
	//impresion para que puedan escoger el cuadrante
	printf("Donde quieres poner tu pieza jugador %d?\n",jugador);
	do{
	scanf("%d",&opc);	//scanf para el cuadrante seleccionado
	if(opc<1||opc>9){
		printf("\nfuera de rango\n");	//impresion para decir que no puedes seleccionar eso
	}
	else
	ddx=1;		//valor para salir del ciclo
	}while(ddx=0);		//condicional para mantener pidiendo hasta que ponga algo valido
	return (opc-1);		//regreso del cuadrante
}
void separacion(int x,int* r,int* c,int *ci,int*cj ){
	switch(x){
		case 0://caso del cuadrante 1
			(*ci)=0;	//inicio de los renglones
			(*cj)=0;	//inicio de las columnas
			(*r)=8;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=8;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 1://caso del cuadrante 2
			(*ci)=0;	//inicio de los renglones
			(*cj)=4;	//inicio de las columnas
			(*r)=8;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=4;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 2://caso del cuadrante 3			
			(*ci)=0;	//inicio de los renglones
			(*cj)=8;	//inicio de las columnas
			(*r)=8;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=0;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 3://caso del cuadrante 4			
			(*ci)=4;	//inicio de los renglones
			(*cj)=0;	//inicio de las columnas
			(*r)=4;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=8;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 4:	//caso del cuadrante 5		
			(*ci)=4;	//inicio de los renglones
			(*cj)=4;	//inicio de las columnas
			(*r)=4;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=4;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 5://caso del cuadrante 6			
			(*ci)=4;	//inicio de los renglones
			(*cj)=8;	//inicio de las columnas
			(*r)=4;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=0;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 6:	//caso del cuadrante 7		
			(*ci)=8;	//inicio de los renglones
			(*cj)=0;	//inicio de las columnas
			(*r)=0;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=8;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 7:	//caso del cuadrante 8		
			(*ci)=8;	//inicio de los renglones
			(*cj)=4;	//inicio de las columnas
			(*r)=0;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=4;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		case 8:	//caso del cuadrante 9		
			(*ci)=8;	//inicio de los renglones
			(*cj)=8;	//inicio de las columnas
			(*r)=0;		//numero que se utilizara para la resta para limitar la asignacion en renglones
			(*c)=0;		//numero que se utilizara para la resta para limitar la asignacion en columnas
		break;
		//no hay default porque no se puede asignar otro valor aparte de estos
	}
}
//funcion del menu
int menu(char* respuesta,int*g1,int*g2,int*m1,int*m2,int*c1,int*c2,int*player,int* r,int*c,int*ci,int*cj){
	//variables que se van a utilizar adentro de menu
	int opc=0,xdd=0;
	do{//ciclo do para 
	xdd=cuadrante(player);	//llamada a la funcion cuadrante que regresara un valor y se lo dara a xdd
	//llamada a la funcion separacion para asignar los valores que se usaran en tamano
	separacion(xdd,r,c,ci,cj);
	//llamada a funcion tamano que regresara un entero para ver si sale del ciclo 
	opc=tamano(respuesta,g1,g2,m1,m2,c1,c2,player,r,c,ci,cj);
	}while(opc==0);		//condicional para salir
	Imptablero(respuesta);	//llamada a funcion Imptablero
	(*player)++;	//incremento que se usara para saber que jugador esta al momento
	if((*player)==13){	//if para regresarse en caso de que ya existieran 12 jugadas
    return 1;	//retorno 1
	}
	return 0;	//retorno 0
}
//funcion tamano para ver el tamano que se intenta colocar
int tamano(char* respuesta,int* g1,int* g2,int* m1,int* m2,int* c1,int* c2,int* p,int*r,int*c,int*ci,int*cj){
	int pz=0; //variable local
	//impresion de opciones
	printf("\nEscoga el tamano de la pieza\n");
	printf("[1]Grande\n");
	printf("[2]mediano\n");
	printf("[3]chico\n");
	scanf("%d",&pz);		//escaneo de opcion
	switch(pz){				//switch para la seleccion
		case 1:		//caso grande
			if(((*p)%2)!=0){	//if para jugador 1
				if((*g1)<2){	//if para ver si aun tiene piezas grandes
					//llamada a funcion	Imagenrespuestagrande
					Imagenrespuestagrande(respuesta,g1,r,c,ci,cj,p);
					return 1;
				}
				else{	//else en caso de no contar con mas piezas
					printf("Se te acabaron las piezas grandes jugador 1\n");
					return 0;
				}
			}
			 if(((*p)%2)==0){	//if para jugador 2
				if((*g2)<2){	//if para ver si aun tiene piezas grandes
					//llamada a funcion	Imagenrespuestagrande
					Imagenrespuestagrande(respuesta,g2,r,c,ci,cj,p);
					return 1;
				}
				else{	//else en caso de no contar con mas piezas
					printf("Se te acabaron las piezas grandes jugador 2\n");
					return 0;
				}
			}
		break;
		case 2://caso mediano
				if(((*p)%2)!=0){	//if para jugador 1
				if((*m1)<2){	//if para ver si aun tiene piezas medianas
					//llamada a funcion	Imagenrespuestamediana
					Imagenrespuestamediana(respuesta,m1,r,c,ci,cj,p);
					return 1;
				}
				else{	//else en caso de no contar con mas piezas
					printf("Se te acabaron las piezas medianas jugador 1\n");
					return 0;
				}
			}
			 if(((*p)%2)==0){	//if para jugador 2
				if((*m2)<2){	//if para ver si aun tiene piezas medianas
					//llamada a funcion	Imagenrespuestamediana
					Imagenrespuestamediana(respuesta,m2,r,c,ci,cj,p);
					return 1;
				}
				else{		//else en caso de no contar con mas piezas
					printf("Se te acabaron las medianas jugador 2\n");
					return 0;
				}
			}

		break;
		case 3:
				if(((*p)%2)!=0){	//if para jugador 1
				if((*c1)<2){	//if para ver si aun tiene piezas chicas
					//llamada a funcion	Imagenrespuestachica
					Imagenrespuestachica(respuesta,c1,r,c,ci,cj,p);
					return 1;
				}
				else{		//else en caso de no contar con mas piezas
					printf("Se te acabaron las piezas chicas jugador 1\n");
					return 0;
				}
			}
			 if(((*p)%2)==0){	//if para jugador 2
				if((*c2)<2){	//if para ver si aun tiene piezas chicas
					//llamada a funcion	Imagenrespuestachica
					Imagenrespuestachica(respuesta,c2,r,c,ci,cj,p);
					return 1;
				}
				else{		//else en caso de no contar con mas piezas
					printf("Se te acabaron las chicas jugador 2\n");
					return 0;
				}
			}
		break;
		default:
		//impresion en caso de equivocarse
		printf("\nOpcion incorrecta, escoja otra vez\n");
		return 0;
		break;
	}
}
