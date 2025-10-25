//lo hago en otro programa por que si no pasan cosas con push y pull
//despues lo muevo al juego.c original

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DIMENSION_LOGICA 3

//Declaracion de estadisticas del jugador
    typedef struct player{
        int grandes;
        int medianos;
        int pequenos;
        char valores[3];
    }player;

//funciones prototipos
void desplegarMatrizLogica(char (*matriz)[DIMENSION_LOGICA]);

void desplegarStats(player *jugador,char *color);

char seleccionPieza();

bool validacionPieza(char pieza,player *jugador);

void actualizacionPiezas(char piezaEscojida,player *jugador);

int main(){
    //Declaracion de tablero logico
    char matrizLogica[DIMENSION_LOGICA][DIMENSION_LOGICA] = {0};
    desplegarMatrizLogica(matrizLogica);

    //asignacion de cantidad de piezas asi como asignacion de valores en tablon logico
    player azul = {2,2,2, {'1','2','3'}};

    player rojo = {2,2,2, {'4','5','6'}};

    //Declaracion de turnos, numeros par le toca al azul, rojo impares
    int turnos = 0;
    int tamanio = 0;
    char piezaEscojida = 0;
    if(turnos++ % 2 == 0){
        do{
            desplegarStats(&azul,"Azul");
            piezaEscojida = seleccionPieza();
        }while(!validacionPieza(piezaEscojida,&azul));
        
        //actualizacion de cuantas piezas tiene el jugador
        actualizacionPiezas(piezaEscojida,&azul);
    }
    else{
        desplegarStats(&rojo,"Rojo");
    }

    return 0;
}

void desplegarMatrizLogica(char (*matriz)[DIMENSION_LOGICA]){
    for(int i = 0; i < DIMENSION_LOGICA ;i++){
        for(int j = 0; j < DIMENSION_LOGICA ;j++){
            printf("[%c]",*(*(matriz + i)+j));     
        }
        printf("\n");
    }
}

void desplegarStats(player *jugador,char *color){
    printf("\nTurno del Jugador %s\nCantidad de mayores: %d\nCantidad de medianos: %d\nCantidad de pequenios: %d\n",color,jugador->grandes,jugador->medianos,jugador->pequenos);
}

char seleccionPieza(){
    char opc = 0;
    printf("\nSelecciona Tamanio de pieza a poner");
    printf("\n[1] Para pequenia");
    printf("\n[2] Para mediana");
    printf("\n[3] Para grande");
    printf("\nSu opcion es: ");
    scanf("%c",&opc);
    while(getchar() != '\n');
    return opc;
}

bool validacionPieza(char pieza,player *jugador){
    if(pieza - '0' > 3 || pieza - '0' < 1){
        printf("\nESA PIEZA NO EXISTE\n");
        return false;
    }
    else if(jugador->valores[pieza - '0'] == 0){
        printf("\nYA NO TIENES MAS DE ESAS PIEZAS\n");
        return false;
    }
    return true;
}

void actualizacionPiezas(char piezaEscojida,player *jugador){
    //actualizacion de cuantas piezas tiene el jugador
        switch(piezaEscojida){
            case '1':
                jugador->pequenos--;
            break; 

            case '2':
                jugador->medianos--;
            break; 

            case '3':
                jugador->grandes--;
            break; 

            default:
                printf("\nimposible que llegues aqui, al menos que haya un grave error logico.....\n");
            break;
        }
}

void colocarPieza(char (*matriz)[DIMENSION_LOGICA],char piezaEscojida){
     printf("[%c]",*(*(matriz + i)+j));     
}