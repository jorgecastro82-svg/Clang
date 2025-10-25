#include <stdio.h>

void printfRojo(char*);

void printfAzul(char*);

int main(){

    printfRojo("Hola negros\n");
    printfAzul("Hola negros\n");

    return 0;
}

void printfRojo(char *cadena){
    printf("\033[1;31m%s\033[0m",cadena);
}

void printfAzul(char *cadena){
    printf("\033[1;34m%s\033[0m",cadena);
}