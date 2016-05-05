#include <stdio.h>
#include <stdlib.h>
#include "tabla.h"

void inicializar_palabra(struct Palabra *palabra){
	palabra->primera=NULL;
	palabra->ultima=NULL;
}

void inicializar_hash(struct Tabla * tabla){
    int i = 0;
    for(i = 0; i < 32; i++){
        tabla->elementos[i].primero = NULL;
        tabla->elementos[i].ultimo = NULL;
    }
}
/*
int clasificar_palabra(FILE *archivo){
    char aux = ' ';
    int suma = 0;
    struct Palabra palabra;
    struct Tabla tabla;
    inicializar_palabra(&palabra);
    inicializar_hash(&tabla);

    while (feof(archivo) == 0) {
        aux = fgetc(archivo);
        if(aux != ' '){
            suma +=aux;
            insertar_letra(&palabra,aux);
        }
        else{
            //insertar_palabra(&tabla, &palabra, suma);
            inicializar_palabra(&palabra);
            suma= 0;
        }
    }
    //mostrar_hash(&tabla);
    return 0;
}
*/
void insertar_letra(struct Palabra * palabra, char letra){
    struct Caracter* auxcaracter = NULL;
    auxcaracter = (struct Caracter *)malloc(sizeof(struct Caracter));
    auxcaracter->letra = letra;
    auxcaracter->siguiente = NULL;
    if(palabra->primera == NULL){
        palabra->primera = auxcaracter;
    }
    else{
        palabra->ultima->siguiente = auxcaracter;
    }
    palabra->ultima = auxcaracter;
}



