#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla.h"


struct Palabra palabra;
struct Tabla_hash tabla;

int clasificar(FILE *archivo){
    char auxiliar1 = ' ';
    int suma = 0;
    inicializar_palabra(&palabra);
    inicializar_hash(&tabla);

    while (feof(archivo) == 0) {
        auxiliar1 = fgetc(archivo);
        if(auxiliar1 != ' '){
            suma = suma + auxiliar1;
            insertar_letra(&palabra, auxiliar1);
        }
        else{
            insertar_palabra(&tabla, &palabra, suma);
            inicializar_palabra(&palabra);
            suma = 0;
        }
    }

    mostrar_tablahash(&tabla);
    return 0;
}

void inicializar_palabra(struct Palabra * palabra){
    palabra->primera = NULL;
    palabra->ultima = NULL;
}

void inicializar_hash(struct Tabla_hash * tabla){
    int i = 0;
    for(i = 0; i < 32; i++){
        tabla->elementos[i].primero = NULL;
        tabla->elementos[i].ultimo = NULL;
    }
}


void mostrar_tablahash(struct Tabla_hash * tabla){
    int j = 0;
    int salir = 0;

    struct Elementohash *aux = NULL;

    for(j = 0; j < 32; j++){
        if(tabla->elementos[j].primero != NULL){
            aux = tabla->elementos[j].primero;
            salir = 0;
            while(salir == 0){
                printf("posicion %d\n",j);
                mostrar_palabra(&(aux->inicial));
                aux = aux->siguiente;
                if(aux == NULL){
                    salir = 1;
                }
            }
        }
        printf("\n");
    }
}

void mostrar_palabra(struct Palabra  * palabra) {
    int acabar = 0;

    struct Caracter * auxiliar4 = NULL;

    if(palabra->primera != NULL){
        auxiliar4 = palabra->primera;
        while(acabar == 0){
            printf("%c", auxiliar4->letra);
            auxiliar4 = auxiliar4->siguiente;
        
            if(auxiliar4 == NULL){
            
                acabar = 1;
            }
        }
    }
}


void insertar_letra(struct Palabra * palabra, char caracter){
    struct Caracter * auxiliar2 = NULL;

    auxiliar2 = (struct Caracter *)malloc(sizeof(struct Caracter));
    auxiliar2->letra = caracter;
    auxiliar2->siguiente = NULL;

    if(palabra->primera == NULL){
        palabra->primera = auxiliar2;
    }
    else{
        palabra->ultima->siguiente = auxiliar2;
    }
    palabra->ultima = auxiliar2;

}

void insertar_palabra(struct Tabla_hash * tabla, struct Palabra * palabra, int suma){
    int posicion = 0;
    struct Elementohash * auxiliar3 = NULL;

    auxiliar3 = (struct Elementohash*)malloc(sizeof(struct Elementohash));
    if(auxiliar3 == NULL){
        exit(0);
    }
    auxiliar3->inicial=*palabra;
    auxiliar3->siguiente=NULL;

    posicion = funcion_hash(suma);


    if(tabla->elementos[posicion].primero == NULL){
        tabla->elementos[posicion].primero = auxiliar3;
        
    }
    else{
        tabla->elementos[posicion].ultimo->siguiente = auxiliar3;
    }

    tabla->elementos[posicion].ultimo = auxiliar3;

    
}


int funcion_hash(int suma){
    int posicion = 0;
    posicion = suma % 32;
    return posicion;
}
