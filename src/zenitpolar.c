#include <stdio.h>
#include "cript.h"

int analiseArg(int argc) {
	if(argc <= 1) return 1;
	return 0;
}

int main(int argc, char **argv) {
	int saida;

	if(analiseArg(argc) == 1) {
		printf("Entrada de parâmetros inválida\nex: ./zenitpolar arquivoAlvo_01 arquivoAlvo_02 (...) arquivoAlvo_n\n\n");
		return 1;
	}

	saida = cript(argc,argv);

	if(saida != 0) {
		printf("\nErro na geracao do(s) arquivo(s).\n\n");
	}else{
		printf("\nArquivo(s) criado(s) com sucesso.\n\n");
	}


	return 0;
}
