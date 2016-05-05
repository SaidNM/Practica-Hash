#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            insertar_palabra(&tabla, &palabra, suma);
            inicializar_palabra(&palabra);
            suma= 0;
        }
    }
    //mostrar_hash(&tabla);
    return 0;
}

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



int funcion_hash(int suma){
    int posicion = 0;
    posicion = suma % 32;
    return posicion;
}

void insertar_palabra(struct Tabla * tabla,struct Palabra* palabra, int suma){
    int posicion = 0;
    struct Elementohash * auxiliar=NULL;

    auxiliar = (struct Elementohash*)malloc(sizeof(struct Elementohash));
    if(auxiliar==NULL){
        exit(0);
    }
    auxiliar->inicio= *palabra;
    auxiliar->siguiente=NULL;

    posicion = funcion_hash(suma);

    if(tabla->elementos[posicion].primero == NULL){
        tabla->elementos[posicion].primero = auxiliar;
    }
    else{
        tabla->elementos[posicion].ultimo->siguiente = auxiliar;
    }

    tabla->elementos[posicion].ultimo = auxiliar;
}


void mostrar_tablahash(struct Tabla * tabla){
    int i = 0;
    int salir = 0;

    struct Elementohash * auxiliar = NULL;

    for(i= 0; i < 32; i++){
        if(tabla->elementos[i].primero != NULL){
            auxiliar = tabla->elementos[i].primero;
            salir = 0;
            while(salir == 0){
                printf("Lugar numero %d\n",i);
                mostrar_palabra(&(auxiliar->inicio));
                auxiliar = auxiliar->siguiente;
                if(auxiliar == NULL){
                    salir = 1;
                }
            }
        }
        
        printf("%s\n","");
    }
}


void mostrar_palabra(struct Palabra  * palabra) {
    int acabarpalabra = 0;

    struct Caracter * auxiliarcaracter = NULL;

    if(palabra->primero != NULL){
        auxiliarcaracter = palabra->primero;
        while(acabarpalabra == 0){
            printf("%c", auxiliarcaracter->letra);
            auxiliarcaracter = auxiliarcaracter->siguiente;
            if(auxiliarcaracter == NULL);
                acabarpalabra = 1;
            }
        }
    }
}
