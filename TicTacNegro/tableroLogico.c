#include <stdio.h>

//lo hago en otro programa por que si no pasan cosas con push y pull
//despues lo muevo al juego.c original
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
    if(turnos++ % 2 == 0){
        desplegarStats(&azul,"Azul");
        do{
        printf("\nSelecciona Tamanio de pieza a poner")
        scanf("%d",tamanio);
        }while(tamanio)

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