#include <stdio.h>
#include <stdlib.h>
#include "tabla.h"



int main(int argc, char const *argv[]) {

    FILE *documento = NULL;
	int error = 0;

	documento = fopen("texto.txt", "r");
	if (documento == NULL) {
		printf("Documento vacio\n");
		return 0;
	}

    clasificar(documento);
    getch();
    return 0;
}
