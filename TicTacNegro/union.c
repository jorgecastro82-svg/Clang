#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define REN 11 //declaracion de constante REN
#define COL 11 //declaracion de constante COL
#define DIMENSION_CUADRADA 3 //dimension de matriz cuadrada 3 x 3

//prototipo de la funcion menu
int menu(char *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int (*)[DIMENSION_CUADRADA], int (*)[DIMENSION_CUADRADA]);
//prototipo de la funcion Imptablero
void Imptablero(char *);
//prototipo de la funcion Inicirespuesta
void Inicirespuesta(char *);
//prototipo de la funcion Imagenrespuestamediana
void Imagenrespuestamediana(char *, int *, int *, int *, int *, int *, int *);
//prototipo de la funcion Imagenrespuestachica
void Imagenrespuestachica(char *, int *, int *, int *, int *, int *, int *);
//prototipo de la funcion Imagenrespuestagrande
void Imagenrespuestagrande(char *, int *, int *, int *, int *, int *, int *);
//prototipo de la funcion tamano
int tamano(char *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int (*)[DIMENSION_CUADRADA], int (*)[DIMENSION_CUADRADA]);
//prototipo de la funcion cuadrante
int cuadrante(int *);
//prototipo de la funcion separacion
void separacion(int, int *, int *, int *, int *);

//prototipos de las funciones

//inicializa la matriz de duenos y tamanos en 0s (es la matriz logic)
void inicializarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]); 

//despliegue tablero, mostrando duenos y tamanos (sirve para debugeo, el usuario nunca lo vera)
void desplegarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]);  

//valida colocacion de piezas
bool colocarPieza(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA], int jugador, int pos, int tam, int *piezas); 

//checar si hay ganador
int checarGanador(int (*duenos)[DIMENSION_CUADRADA]); 

//checar si esta lleno
bool isLleno(int (*duenos)[DIMENSION_CUADRADA]);

//checar si el jugador tiene jugadas validas (basicamente solo checa condicion de empate)
bool tieneJugadasValidas(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA], int *piezas, int jugador);

//es combinacion de printf y scanf con limpieza de buffer, pero en especifico sirve para evitar que se te ponga infinitamente el despliegue cuando te ingresan una letra
int inputNumero(char *mensaje); 

int main(){
    //declaracion de variables en main que se usaran como apuntadores en todo el codigo
    int grandeT1 = 0;
    int chicoT1 = 0;
    int medT1 = 0;
    int grandeT2 = 0;
    int chicoT2 = 0;
    int medT2 = 0;
    int player = 1, ren = 0, col = 0, ci = 0, cj = 0, otra = 0;
    //declaracion de la matriz principal
    char respuesta[REN][COL];
    int duenos[DIMENSION_CUADRADA][DIMENSION_CUADRADA], tamanos[DIMENSION_CUADRADA][DIMENSION_CUADRADA];
    int jugador1Piezas[3] = {2, 2, 2};   //son las piezas del jugador 1
    int jugador2Piezas[3] = {2, 2, 2};  //son las piezas del jugador 2
    int ganador = 0;
    //variable para salida del ciclo do
    int opc = 0;
    do{ //ciclo do while para ver si quiere jugar otra partida
        Inicirespuesta((char *)respuesta);
        inicializarTablero(duenos, tamanos); 
        *(jugador1Piezas + 0) = 2; *(jugador1Piezas + 1) = 2; *(jugador1Piezas + 2) = 2;
        *(jugador2Piezas + 0) = 2; *(jugador2Piezas + 1) = 2; *(jugador2Piezas + 2) = 2;
        ganador = 0;
        player = 1;
        grandeT1 = 0; chicoT1 = 0; medT1 = 0; grandeT2 = 0; chicoT2 = 0; medT2 = 0;
        //imprimir tablero visual al inicio de la partida
        Imptablero((char *)respuesta);
        do{ //ciclo do while para salirse cuando encuentre ganador o sea empate
            //llamada a la funcion menu donde se realizara casi todos los procedimientos
            //recibira un int para ver si continuar o salir
            opc = menu((char *)respuesta, &grandeT1, &grandeT2, &medT1, &medT2, &chicoT1, &chicoT2, &player, &ren, &col, &ci, &cj, jugador1Piezas, jugador2Piezas, &ganador, duenos, tamanos);
        }while(opc == 0); //condicional para salir
        printf("\n");
        if(ganador != 0){
            printf("Jugador %s gana\n", (ganador == 1) ? "Jugador 1" : "Jugador 2");
        } 
        else{
            printf("NO HAY GANADORES\n");
        } 
        printf("Quieres jugar otra? 0=si cualquier numero =No\n"); //pregunta para ver si quiere seguir jugando
        scanf("%d", &otra); //scanf para ver respuesta
    }while(otra == 0); //condicional para cerrar programa
    return 0;
}

void Imptablero(char *matriz){ //funcion para imprimir todo el tablero
    printf("\n");
    int i = 0, j = 0;
    for(i = 0; i < REN; i++){
        printf("\n");
        for(j = 0; j < COL; j++){ //ciclo for anidado para la impresion
            printf("%-2c", *(matriz + (i * COL) + j));
        }
    }
}

void Inicirespuesta(char *matriz){ //funcion para inicializar la matriz
    int i, j;
    for(i = 0; i < REN; i++){
        for(j = 0; j < COL; j++){
            *(matriz + (i * COL) + j) = ' '; //da un valor "Nulo" a ese lugar
            if(j == 3 || j == 7){
                *(matriz + (i * COL) + j) = 124; //coloca lineas verticales
            }
            if(i == 3 || i == 7){
                *(matriz + (i * COL) + j) = 196; //coloca lineas horizontales
            }
        }
    }
}

void Imagenrespuestamediana(char *matriz, int *m, int *r, int *c, int *ci, int *cj, int *p){
    int i, j;
    //limpiar la pieza para poner la otra
    for(i = (*ci); i < (*ci) + 3; i++){
        for(j = (*cj); j < (*cj) + 3; j++){
            if(!(j == 3 || j == 7 || i == 3 || i == 7)){ //if para no limpiar las --- (mantener el grid)
                *(matriz + (i * COL) + j) = ' ';
            }
        }
    }
    // colocar la pieza mediana
    for(i = (*ci); i < (REN) - (*r); i++){
        //for que usara los apuntadores para ver donde iniciar y donde terminar en columnas
        for(j = (*cj); j < (COL) - (*c); j++){
            //if para comprobar si cumple la condicion y poner el char correspondiente
            if(((i + j) - ((*ci) + (*cj))) == 1 || ((i + j) - ((*ci) + (*cj) + 1)) == 2){
                if(((*p) % 2) != 0){ //if para ver si es el jugador 1
                    *(matriz + (i * COL) + j) = 254; //pone un cuadrado grande
                }
                if(((*p) % 2) == 0){ //if para ver si es el jugador 2
                    *(matriz + (i * COL) + j) = 250; //pone un cuadrado chico 
                }
            }
        }
    }
    (*m)++; //aumento para comprobar si ya usaron el maximo
}

void Imagenrespuestachica(char *matriz, int *cc, int *r, int *c, int *ci, int *cj, int *p){
    int i, j;
    //limpiar la pieza para poner otra
    for(i = (*ci); i < (*ci) + 3; i++){
        for(j = (*cj); j < (*cj) + 3; j++){
            if(!(j == 3 || j == 7 || i == 3 || i == 7)){ //if para no limpiar las --- (mantener el grid)
                *(matriz + (i * COL) + j) = ' ';
            }
        }
    }
    // Colocar la pieza chica
    for(i = (*ci); i < (REN) - (*r); i++){
        //for que usara los apuntadores para ver donde iniciar y donde terminar en columnas
        for(j = (*cj); j < (COL) - (*c); j++){
            //if para comprobar si cumple la condicion y poner el char correspondiente
            if((i - (*ci)) == 1 && (j - (*cj)) == 1){ 
                if(((*p) % 2) != 0){ //if para ver si es el jugador 1
                    *(matriz + (i * COL) + j) = 254; //pone un cuadrado grande
                }
                if(((*p) % 2) == 0){ //if para ver si es el jugador 2
                    *(matriz + (i * COL) + j) = 250; //pone un cuadrado chico
                }
            }
        }
    }
    (*cc)++; //incremento para llevar contado los que hay en el tablero
}

void Imagenrespuestagrande(char *matriz, int *g, int *r, int *c, int *ci, int *cj, int *p){
    int i, j;
    //limpiar la pieza para poner la otra
    for(i = (*ci); i < (*ci) + 3; i++){
        for(j = (*cj); j < (*cj) + 3; j++){
            if(!(j == 3 || j == 7 || i == 3 || i == 7)){ //if para no limpiar las --- (mantener el grid)
                *(matriz + (i * COL) + j) = ' ';
            }
        }
    }
    //colocar pieza grande
    for(i = (*ci); i < (REN) - (*r); i++){
        //for que usara los apuntadores para ver donde iniciar y donde terminar en columnas
        for(j = (*cj); j < (COL) - (*c); j++){
            //if para comprobar si cumple la condicion y poner el char correspondiente
            if((i - (*ci)) == 0 || (j - (*cj)) == 0 || (j - (*cj)) == 2 || (i - (*ci)) == 2){
                if(((*p) % 2) != 0){ //if para ver si es el jugador 1
                    *(matriz + (i * COL) + j) = 254; //pone un cuadrado grande
                }
                if(((*p) % 2) == 0){ //if para ver si es el jugador 2
                    *(matriz + (i * COL) + j) = 250; //pone un cuadrado chico
                }
            }
        }
    }
    (*g)++; //incremento para llevar contado los que hay en el tablero
}

int cuadrante(int *p){ //funcion para asignar el cuadrante
    int ddx = 0, opc, jugador;
    if((*p) % 2 != 0) //if para ver cual es el jugador
        jugador = 1;
    else 
        jugador = 2;
    //impresion para que puedan escoger el cuadrante
    printf("Donde quieres poner tu pieza jugador %d?\n", jugador);
    do{
        opc = inputNumero(""); //scanf para el cuadrante seleccionado
        if(opc < 1 || opc > 9){
            printf("\nfuera de rango\n"); //impresion para decir que no puedes seleccionar eso
        }
        else
            ddx = 1; //valor para salir del ciclo
    }while(ddx == 0); //condicional para mantener pidiendo hasta que ponga algo valido
    return (opc - 1); //regreso del cuadrante
}

void separacion(int x, int *r, int *c, int *ci, int *cj){
    switch(x){
        case 0://caso del cuadrante 1
            (*ci) = 0; //inicio de los renglones
            (*cj) = 0; //inicio de las columnas
            (*r) = 8; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 8; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 1://caso del cuadrante 2
            (*ci) = 0; //inicio de los renglones
            (*cj) = 4; //inicio de las columnas
            (*r) = 8; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 4; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 2://caso del cuadrante 3            
            (*ci) = 0; //inicio de los renglones
            (*cj) = 8; //inicio de las columnas
            (*r) = 8; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 0; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 3://caso del cuadrante 4            
            (*ci) = 4; //inicio de los renglones
            (*cj) = 0; //inicio de las columnas
            (*r) = 4; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 8; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 4: //caso del cuadrante 5        
            (*ci) = 4; //inicio de los renglones
            (*cj) = 4; //inicio de las columnas
            (*r) = 4; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 4; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 5://caso del cuadrante 6            
            (*ci) = 4; //inicio de los renglones
            (*cj) = 8; //inicio de las columnas
            (*r) = 4; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 0; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 6: //caso del cuadrante 7        
            (*ci) = 8; //inicio de los renglones
            (*cj) = 0; //inicio de las columnas
            (*r) = 0; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 8; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 7: //caso del cuadrante 8        
            (*ci) = 8; //inicio de los renglones
            (*cj) = 4; //inicio de las columnas
            (*r) = 0; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 4; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        case 8: //caso del cuadrante 9        
            (*ci) = 8; //inicio de los renglones
            (*cj) = 8; //inicio de las columnas
            (*r) = 0; //numero que se utilizara para la resta para limitar la asignacion en renglones
            (*c) = 0; //numero que se utilizara para la resta para limitar la asignacion en columnas
        break;
        //no hay default porque no se puede asignar otro valor aparte de estos
    }
}

//funcion del menu
int menu(char *respuesta, int *g1, int *g2, int *m1, int *m2, int *c1, int *c2, int *player, int *r, int *c, int *ci, int *cj, int *ap, int *rp, int *gan, int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]){
    //variables que se van a utilizar adentro de menu
    int opc = 0, xdd = 0;
    do{ //ciclo do para 
        //chequeo de si puede hacer jugadas posibles antes de avanzar
        int jugador = ((*player) % 2 != 0) ? 1 : 2;     //checar si es jugador 1 o 2 checando turno par o impar
        int *piezas = ((*player) % 2 != 0) ? ap : rp;   //asignacion de puntero a las piezas del jugador 1 (ap) o piezas del jugador 2 (rp)
        if(isLleno(duenos) || !tieneJugadasValidas(duenos, tamanos, piezas, jugador)){
            return 1; //terminar el juego si un jugador ya no tiene jugadas posibles en su turno (o sea empate)
        }
        xdd = cuadrante(player); //llamada a la funcion cuadrante que regresara un valor y se lo dara a xdd
        //llamada a la funcion separacion para asignar los valores que se usaran en tamano
        separacion(xdd, r, c, ci, cj);
        //llamada a funcion tamano que regresara un entero para ver si sale del ciclo 
        opc = tamano(respuesta, g1, g2, m1, m2, c1, c2, player, r, c, ci, cj, ap, rp, duenos, tamanos);
    }while(opc == 0); //condicional para salir
    Imptablero(respuesta); //llamada a funcion Imptablero
    (*gan) = checarGanador(duenos);
    if((*gan) != 0){ //if para ver si hay ganador
        return 1; //retorno 1
    }
    (*player)++; //incremento que se usara para saber que jugador esta al momento
    return 0; //retorno 0
}

//funcion tamano para ver el tamano que se intenta colocar
int tamano(char *respuesta, int *g1, int *g2, int *m1, int *m2, int *c1, int *c2, int *p, int *r, int *c, int *ci, int *cj, int *ap, int *rp, int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]){
    int pz = 0; //variable local
    //impresion de opciones
    printf("\nEscoga el tamano de la pieza\n");
    printf("[1]Grande\n");
    printf("[2]mediano\n");
    printf("[3]chico\n");
    pz = inputNumero(""); //escaneo de opcion
    int index = 3 - pz;
    int new_tam = index + 1;
    int fila = (*ci) / 4;
    int colu = (*cj) / 4;
    int celdaTam = *(*(tamanos + fila) + colu);
    int celdaDueno = *(*(duenos + fila) + colu);
    int jugador = ((*p) % 2 != 0) ? 1 : 2;
    //checar si la pieza ya le pertenece al mismo jugador
    if(celdaDueno == jugador){
        printf("No puedes colocar una pieza sobre tus propias piezas\n");
        return 0;
    }
    
    if(celdaDueno != 0 && new_tam <= celdaTam){ //checar que si se la pueda comer, checar si es menor o igual
        printf("Tu pieza no es lo suficientemente grande como para comerte a la que esta ahi\n");
        return 0;
    }
    int *piezas;
    if(((*p) % 2) != 0){
        piezas = ap;    //es apuntador a piezas del jugador 1 (antes era jugador azul) por eso azul puntero (ap)
    }else{
        piezas = rp;    //es apuntador a piezas del jugador 2 (antes era jugador rojo) por eso rojo puntero (rp)
    }
    switch(pz){ //switch para la seleccion
        case 1: //caso grande
            if(((*p) % 2) != 0){ //if para jugador 1
                if(*(piezas + 2) > 0){ //if para ver si aun tiene piezas grandes
                    //llamada a funcion Imagenrespuestagrande
                    Imagenrespuestagrande(respuesta, g1, r, c, ci, cj, p);
                    (*(piezas + 2))--;
                    *(*(duenos + fila) + colu) = jugador;
                    *(*(tamanos + fila) + colu) = new_tam;
                    return 1;
                }
                else{ //else en caso de no contar con mas piezas
                    printf("Se te acabaron las piezas grandes jugador 1\n");
                    return 0;
                }
            }
            if(((*p) % 2) == 0){ //if para jugador 2
                if(*(piezas + 2) > 0){ //if para ver si aun tiene piezas grandes
                    //llamada a funcion Imagenrespuestagrande
                    Imagenrespuestagrande(respuesta, g2, r, c, ci, cj, p);
                    (*(piezas + 2))--;
                    *(*(duenos + fila) + colu) = jugador;
                    *(*(tamanos + fila) + colu) = new_tam;
                    return 1;
                }
                else{ //else en caso de no contar con mas piezas
                    printf("Se te acabaron las piezas grandes jugador 2\n");
                    return 0;
                }
            }
        break;
        case 2: //caso mediano
            if(((*p) % 2) != 0){ //if para jugador 1
                if(*(piezas + 1) > 0){ //if para ver si aun tiene piezas medianas
                    //llamada a funcion Imagenrespuestamediana
                    Imagenrespuestamediana(respuesta, m1, r, c, ci, cj, p);
                    (*(piezas + 1))--;
                    *(*(duenos + fila) + colu) = jugador;
                    *(*(tamanos + fila) + colu) = new_tam;
                    return 1;
                }
                else{ //else en caso de no contar con mas piezas
                    printf("Se te acabaron las piezas medianas jugador 1\n");
                    return 0;
                }
            }
            if(((*p) % 2) == 0){ //if para jugador 2
                if(*(piezas + 1) > 0){ //if para ver si aun tiene piezas medianas
                    //llamada a funcion Imagenrespuestamediana
                    Imagenrespuestamediana(respuesta, m2, r, c, ci, cj, p);
                    (*(piezas + 1))--;
                    *(*(duenos + fila) + colu) = jugador;
                    *(*(tamanos + fila) + colu) = new_tam;
                    return 1;
                }
                else{ //else en caso de no contar con mas piezas
                    printf("Se te acabaron las medianas jugador 2\n");
                    return 0;
                }
            }
        break;
        case 3:
            if(((*p) % 2) != 0){ //if para jugador 1
                if(*(piezas + 0) > 0){ //if para ver si aun tiene piezas chicas
                    //llamada a funcion Imagenrespuestachica
                    Imagenrespuestachica(respuesta, c1, r, c, ci, cj, p);
                    (*(piezas + 0))--;
                    *(*(duenos + fila) + colu) = jugador;
                    *(*(tamanos + fila) + colu) = new_tam;
                    return 1;
                }
                else{ //else en caso de no contar con mas piezas
                    printf("Se te acabaron las piezas chicas jugador 1\n");
                    return 0;
                }
            }
            if(((*p) % 2) == 0){ //if para jugador 2
                if(*(piezas + 0) > 0){ //if para ver si aun tiene piezas chicas
                    //llamada a funcion Imagenrespuestachica
                    Imagenrespuestachica(respuesta, c2, r, c, ci, cj, p);
                    (*(piezas + 0))--;
                    *(*(duenos + fila) + colu) = jugador;
                    *(*(tamanos + fila) + colu) = new_tam;
                    return 1;
                }
                else{ //else en caso de no contar con mas piezas
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

//inicializar el tablero logico en cada partida a 0s
void inicializarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]){
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            *(*(duenos + i) + j) = 0; // 0 = casilla vacia
            *(*(tamanos + i) + j) = 0; // 0 = sin pieza
        }
    }
}

//despliegue del tablero logico (SOLO ES PARA DEBUGEO EL USUARIO NUNCA LA VERA)
void desplegarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]){
    printf("\n---Tablero---\n");
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            int d = *(*(duenos + i) + j); //asigna dueno de pieza 0 nadie, 1 jugador 1, 2 jugador 2
            int t = *(*(tamanos + i) + j); //asigna tamano de pieza
            if(d == 0){
                printf("[   ]"); //pieza sin duenos
            } else if(d == 1){
                printf("[A%d]", t); //dueno jugador 1
            } else if(d == 2){
                printf("[R%d]", t); //dueno jugador 2
            }
        }
        printf("\n");
    }
    printf("\n");
}

//coloca pieza y valida que si se pueda colocar (solo coloca la pieza en sus correspondientes logicos, tiene validacion especifica para tablero logico
bool colocarPieza(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA], int jugador, int pos, int tam, int *piezas){
    //checar que no sea posicion fuera del tablero
    if(pos < 1 || pos > 9){
        printf("POSICION INVALIDA\n");
        return false;
    }
    if(tam < 1 || tam > 3){
        printf("TAMANO INVALIDO\n");
        return false;
    }
    if(*(piezas + (tam - 1)) <= 0){
        printf("YA NO TIENES PIEZAS DE ESE TAMANO\n");
        return false;
    }

    int fila = (pos - 1) / 3; //convertir posicion en su parte de fila
    int col = (pos - 1) % 3; //convertir posicion en su parte de columna

    int celdaTam = *(*(tamanos + fila) + col); //asignar tamano encontrado en la matriz de tamanos dada las posiciones
    if(celdaTam != 0 && tam <= celdaTam){ //checar que si se la pueda comer, checar si es menor o igual
        printf("Tu pieza no es lo suficientemente grande como para comerte a la que esta ahi\n");
        return false;
    }

    //colocacion de pieza asi como su dueno y su tamano
    *(*(duenos + fila) + col) = jugador;
    *(*(tamanos + fila) + col) = tam;
    (*(piezas + (tam - 1)))--; //actualiza las piezas que tiene de ese tamano o sea las decrementa si se puso una
    return true;
}

//chequeo de si hay ganador, retorno de 0 significa no ganador, 1 de ganador azul, 2 de ganador rojo
int checarGanador(int (*duenos)[DIMENSION_CUADRADA]){
    //caso filas
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        if(*(*(duenos + i) + 0) != 0 && *(*(duenos + i) + 0) == *(*(duenos + i) + 1) && *(*(duenos + i) + 1) == *(*(duenos + i) + 2)){
            return *(*(duenos + i) + 0);
        }
    }
    //caso columnas
    for(int j = 0; j < DIMENSION_CUADRADA; j++){
        if(*(*(duenos + 0) + j) != 0 && *(*(duenos + 0) + j) == *(*(duenos + 1) + j) && *(*(duenos + 1) + j) == *(*(duenos + 2) + j)){
            return *(*(duenos + 0) + j);
        }
    }
    //caso diagonal derecha
    if(*(*(duenos + 0) + 0) != 0 && *(*(duenos + 0) + 0) == *(*(duenos + 1) + 1) && *(*(duenos + 1) + 1) == *(*(duenos + 2) + 2)){
        return *(*(duenos + 0) + 0);
    }
    //caso diagonal izquierda
    if(*(*(duenos + 0) + 2) != 0 && *(*(duenos + 0) + 2) == *(*(duenos + 1) + 1) && *(*(duenos + 1) + 1) == *(*(duenos + 2) + 0)){
        return *(*(duenos + 0) + 2);
    }

    return 0; //no ganador
}

//checar si el tablero esta lleno
bool isLleno(int (*duenos)[DIMENSION_CUADRADA]){
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            if(*(*(duenos + i) + j) == 0){
                return false; //significa que todavia hay casillas sin duenos
            }
        }
    }
    return true; //todo esta ocupado
}

//checar si el jugador tiene posibilidades de poner una pieza (condicion de empate basicamente)
bool tieneJugadasValidas(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA], int *piezas, int jugador){
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            int celdaDueno = *(*(duenos + i) + j);
            int celdaTam = *(*(tamanos + i) + j);
            //caso de que haya casillas vacias en el tablero
            if(celdaDueno == 0){
                if(*(piezas + 0) > 0 || *(piezas + 1) > 0 || *(piezas + 2) > 0){
                    return true;
                }
            }
            //checar si puede comerse las piezas del jugador opuesto
            else if(celdaDueno != jugador){
                if((celdaTam == 1 && *(piezas + 1) > 0) || 
                   (celdaTam == 1 && *(piezas + 2) > 0) || 
                   (celdaTam == 2 && *(piezas + 2) > 0)){
                    return true;
                }
            }
        }
    }
    return false; //no tiene jugadas posibles asi que hay empate
}

//leer numeros enteros sin que se haga bucle infinito, combinacion de printf y scanf aparte de limpiada de buffer
int inputNumero(char *mensaje){
    int valor;
    char c;
    while(true){
        printf("%s", mensaje);
        if(scanf("%d", &valor) != 1){
            while((c = getchar()) != '\n' && c != EOF); //limpiada de buffer
            printf("INGRESA UN NUMERO ENTERO CORRECTO\n");
            continue; //salta la siguiente iteracion pero como es ciclo while true , solo evita limpiar buffer otra vez
        }
        while((c = getchar()) != '\n' && c != EOF); //limpiada de buffer
        return valor;
    }
}    