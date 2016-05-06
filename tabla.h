#ifndef __TABLA__
#define __TABLA__
#include <stdio.h>

    struct Caracter{
        char letra;
        struct Caracter * siguiente;
    };

    struct Palabra{
        struct Caracter * primera;
        struct Caracter * ultima;
    };


    struct Elementohash{
            struct Palabra inicial;
            struct Elementohash * siguiente;
    };

    struct Elementos{
        struct Elementohash * primero;
        struct Elementohash * ultimo;
    };

    struct Tabla_hash{
        struct Elementos elementos[32];
    };


    

    void inicializar_palabra(struct Palabra *);
    void insertar_letra(struct Palabra *, char);
    void insertar_palabra(struct Tabla_hash *, struct Palabra *, int);
    void inicializar_hash(struct Tabla_hash *);
    void mostrar_tablahash(struct Tabla_hash *);
    void mostrar_palabra(struct Palabra *);
    int clasificar(FILE *);
    int hash(int);
#endif
