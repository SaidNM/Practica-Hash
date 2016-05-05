#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla.h"



int main() {

    FILE * documento = NULL;

	archivo = fopen("texto.txt", "r");
	if (documento == NULL) {
		printf("Documento vacio\n");
		return 0;
	}
    clasificar_palabra(documento);
    getch();
    return 0;
}
