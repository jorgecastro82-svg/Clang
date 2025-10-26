#include <stdio.h>
#include <stdbool.h>

#define DIMENSION_CUADRADA 3  //dimension de matriz cuadrada 3 x 3

//prototipos de las funciones

//inicializa la matriz de duenos y tamanoss en 0s
void inicializarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]); 

//despliegue tablero, mostrando duenos y tamanos
void desplegarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]);  

//valida colocasion de piezas
bool colocarPieza(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA], int jugador, int pos, int tam, int *piezas); 

//checar si hay ganador
int checarGanador(int (*duenos)[DIMENSION_CUADRADA]); 

//checar si esta lleno
bool isLleno(int (*duenos)[DIMENSION_CUADRADA]);

//es combinacion de printf y scanf con limpieza de buffer, pero en especifico sirve para evitar que se te ponga infinitamente el despliegue cuando te ingresan una letra
int inputNumero(char *mensaje); 

int main(){
    
    //declaracion de matriz de duenos y tamanos para tablero, asi como las piezas que tiene cada jugador (6 cada jugador 2 de cada tamanos)
    int duenos[DIMENSION_CUADRADA][DIMENSION_CUADRADA], tamanos[DIMENSION_CUADRADA][DIMENSION_CUADRADA];
    int jugadorAzulPiezas[3] = {2,2,2};
    int jugadorRojoPiezas[3] = {2,2,2};

    //inicializacion de tablero en 0s, el usuario no vera 0s esto es parte logica
    inicializarTablero(duenos, tamanos); 

     //azul turnos impares, rojo turnos pares
    int turno = 1;
    //0 significa no ganador, 1 significa gana azul, 2 significa gana rojo
    int ganador = 0; 

    //declaracion de variables para posicion y tamano
    int pos = 0;
    int tam = 0;

    //declaracion de puntero al vector de las piezas de los jugadores
    int *piezas = NULL; //se pone null para que no haya un error o que apunte a memoria no valida

    //inicio del juego
    while(ganador == 0 && !isLleno(duenos)){   //mientras no haya ganador y mientras la matriz de duenos no este llena

        //despliega el tablero con duenos y tamanos
        desplegarTablero(duenos, tamanos); 

        //se usa el operador ternario como condicional para impresion de turnos ya que solo se tiene dos opciones turno azul o turno rojo
        printf("Turno del jugador %s\n", (turno==1) ?"Azul":"Rojo"); 

        //pedir posicion y tamano
        pos = inputNumero("Ingresa tu posicion (1-9): "); 
        tam = inputNumero("Ingresa tu tamano (1=peque,2=med,3=grande): ");

        //Asignacion al puntero al vector de las piezas disponibles que tiene el jugador depende el turno apunta a las del jugador azul o a las del rojo
        piezas = (turno == 1) ? jugadorAzulPiezas : jugadorRojoPiezas; 

        //verificacion de colocasion de pieza
        if(colocarPieza(duenos, tamanos, turno, pos, tam, piezas)){
            ganador = checarGanador(duenos); //checar si gano en el turno

            if(ganador == 0){   //cambio de turno en caso de que no haya ganador
                turno = (turno == 1) ? 2 : 1; 
            }
        } 
        else{
            printf("MOVIMIENTO INVALIDO\n"); //mensaje siempre que siempre aparecera cuando hagas operaciones ilegales
        }
    }

    desplegarTablero(duenos, tamanos);//despliegue de tablero una ultima vez

    //Imprimir si hay ganador o no
    if(ganador != 0){
        printf("Jugador %s gana\n", (ganador==1)? "Azul":"Rojo");
    } 
    else{
        printf("NO HAY GANADORES\n");
    } 

    return 0;
}

//LLenado de los cuerpos de las funciones

// Inicializa el tablero vacio
void inicializarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]){
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            *(*(duenos + i) + j) = 0;   // 0 = casilla vacia
            *(*(tamanos + i) + j) = 0;  // 0 = sin pieza
        }
    }
}

// Muestra el tablero en pantalla
void desplegarTablero(int (*duenos)[DIMENSION_CUADRADA], int (*tamanos)[DIMENSION_CUADRADA]){
    printf("\n---Tablero---\n");
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            int d = *(*(duenos + i) + j);    //asigna dueno de pieza 0 nadie, 1 azul, 2 rojo
            int t = *(*(tamanos + i) + j);  //asigna tamano de pieza
            if(d == 0){
                printf("[   ]");            //pieza sin duenos
            } else if(d == 1){
                printf("[A%d]", t);       //dueno azul
            } else if(d == 2){
                printf("[R%d]", t);       //dueno rojo
            }
        }
        printf("\n");
    }
    printf("\n");
}

//coloca pieza y valida que si se pueda colocar
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
    if(*(piezas + (tam-1)) <= 0){
        printf("YA NO TIENES PIEZAS DE ESE TAMANO\n");
        return false;
    }

    int fila = (pos-1)/3; //convertir posicion en su parte de fila
    int col = (pos-1)%3;  //convertir posicion en su parte de columna

    int celdaTam = *(*(tamanos + fila) + col);  //asaignar tamano encontrado en la matriz de tamanos dada las posiciones
    if(tam <= celdaTam){    //checar que si se la pueda comer, checar si es menor o igual
        printf("Tu pieza no es lo suficientemente grande como para comerte a la que esta ahi\n");
        return false;
    }

    //colocacion de pieza asi como su dueno y su tamano
    *(*(duenos + fila) + col) = jugador;
    *(*(tamanos + fila) + col) = tam;
    (*(piezas + (tam-1)))--; //actualiza las piezas que tiene de ese tamano
    return true;
}

//chequeo de si hay ganador, retorno de 0 significa no ganador, 1 de ganador azul, 2 de ganador rojo
int checarGanador(int (*duenos)[DIMENSION_CUADRADA]){
    //caso filas
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        if(*(*(duenos+i)+0) != 0 && *(*(duenos+i)+0) == *(*(duenos+i)+1) && *(*(duenos+i)+1) == *(*(duenos+i)+2)){
            return *(*(duenos+i)+0);
        }
    }
    //caso columnas
    for(int j = 0; j < DIMENSION_CUADRADA; j++){
        if(*(*(duenos+0)+j) != 0 && *(*(duenos+0)+j) == *(*(duenos+1)+j) && *(*(duenos+1)+j) == *(*(duenos+2)+j)){
            return *(*(duenos+0)+j);
        }
    }
    //caso diagonal derecha
    if(*(*(duenos+0)+0) != 0 && *(*(duenos+0)+0) == *(*(duenos+1)+1) && *(*(duenos+1)+1) == *(*(duenos+2)+2)){
        return *(*(duenos+0)+0);
    }
    //caso diagonal izquierda
    if(*(*(duenos+0)+2) != 0 && *(*(duenos+0)+2) == *(*(duenos+1)+1) && *(*(duenos+1)+1) == *(*(duenos+2)+0)){
        return *(*(duenos+0)+2);
    }

    return 0; //no ganador
}

//checar si el tablero esta lleno
bool isLleno(int (*duenos)[DIMENSION_CUADRADA]){
    for(int i = 0; i < DIMENSION_CUADRADA; i++){
        for(int j = 0; j < DIMENSION_CUADRADA; j++){
            if(*(*(duenos+i)+j) == 0){
                return false; //significa que todavia hay casillas sin duenos
            }
        }
    }
    return true; //todo esta ocupado
}

//leer numeros enteros sin que se haga bucle infinito, combinacion de printf y scanf aparte de limpiada de buffer
int inputNumero(char *mensaje){
    int valor;
    char c;
    while(true){
        printf("%s", mensaje);
        if(scanf("%d", &valor) != 1){
            while((c=getchar()) != '\n' && c != EOF); //limpiada de buffer
            printf("INGRESA UN NUMERO ENTERO CORRECTO\n");
            continue;   //salta la siguiente iteracion pero como es ciclo while true , solo evita limpiar buffer otra vez
        }
        while((c=getchar()) != '\n' && c != EOF); //limpiada de buffer
        return valor;
    }
}
