#include <stdio.h>
#include <string.h>
#define len 1000

void conversao(char *entrada, int tamanho) {
	int i;

	for(i=0;i<tamanho;i++) {
		if(entrada[i]=='Z') {entrada[i]='P'; continue;}
		if(entrada[i]=='z') {entrada[i]='p'; continue;}
		if(entrada[i]=='P') {entrada[i]='Z'; continue;}
		if(entrada[i]=='p') {entrada[i]='z'; continue;}

		if(entrada[i]=='E') {entrada[i]='O'; continue;}
		if(entrada[i]=='e') {entrada[i]='o'; continue;}
		if(entrada[i]=='O') {entrada[i]='E'; continue;}
		if(entrada[i]=='o') {entrada[i]='e'; continue;}

		if(entrada[i]=='N') {entrada[i]='L'; continue;}
		if(entrada[i]=='n') {entrada[i]='l'; continue;}
		if(entrada[i]=='L') {entrada[i]='N'; continue;}
		if(entrada[i]=='l') {entrada[i]='n'; continue;}

		if(entrada[i]=='I') {entrada[i]='A'; continue;}
		if(entrada[i]=='i') {entrada[i]='a'; continue;}
		if(entrada[i]=='A') {entrada[i]='I'; continue;}
		if(entrada[i]=='a') {entrada[i]='i'; continue;}


		if(entrada[i]=='T') {entrada[i]='R'; continue;}
		if(entrada[i]=='t') {entrada[i]='r'; continue;}
		if(entrada[i]=='R') {entrada[i]='T'; continue;}
		if(entrada[i]=='r') {entrada[i]='t'; continue;}
	}
}


int cript( int argc, char **argv) {
	FILE * arquivoOrigem;
	FILE * arquivoDestino;
	char linha[len];
	char saida[30];
	int i = 1;

	while(i<=(argc-1)) {

		arquivoOrigem = fopen(argv[i],"r+");
		if(arquivoOrigem == NULL) {
			fclose(arquivoOrigem);
			return i;
		}

		strcpy(saida,argv[i]);
		strcat(saida,".zp");
		arquivoDestino = fopen(saida,"w");
		if(arquivoDestino == NULL) {
			fclose(arquivoDestino);
			return i;
		}

		while(!feof(arquivoOrigem)) {
			fgets(linha,len,arquivoOrigem);
			conversao(linha,strlen(linha));
			fputs(linha,arquivoDestino);
		}
		fclose(arquivoOrigem);
		fclose(arquivoDestino);
		i++;
	}

	return 0;
}
