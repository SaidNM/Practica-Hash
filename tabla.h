#ifndef __TABLA__
#define __TABLA__

 		struct Caracter{
        char letra;
        struct Caracter * siguiente;
    };

    	struct Palabra{
        struct Caracter * primera;
        struct Caracter * ultima;
    };


    	struct Elementohash{
            struct Palabra inicio;
            struct Elementohash * siguiente;
    };

    	struct Elemento{
        struct Elementohash * primero;
        struct Elementohash * ultimo;
    };

    	struct Tabla{
        struct Elemento elementos[32];
    };


    int clasificar_palabra (FILE *);
    int funcion_hash(int);
    void inicializar_palabra(struct Palabra *);
    void insertar_letra(struct Palabra *, char);
    void insertar_palabra(struct Tabla *, struct Palabra *, int);
    void inicializar_hash(struct Tabla *);
    void mostrar_tablahash(struct Tabla *);
    void mostrar_palabra(struct Palabra *);

#endif