#ifndef _PARKIF_
#define _PARKIF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char marca[30];
    char modelo[30];
    char cor[20];
    char placa[10];
    
} veiculo;

veiculo db;
FILE *arq;
FILE *aux;

void init() {
    arq = fopen("db.bin", "a+");
}

void add(veiculo v) { // escreve os dados do veiculo em um arquivo binario
    db = v;
    fwrite(&db, sizeof(veiculo), 1, arq);
    fclose(arq);
}

int rem(char *placa) {
    int ret, found=0;
    aux = fopen("temp.bin", "a+"); // arquivo binario criado para receber uma copia dos dados de todos os veiculos, exceto os do veiculo que o usuario deseja remover 

    char c = fgetc(arq);
    if (c == EOF) { // caso o estacionamento estiver vazio
        return 0;
    } else {
        rewind(arq);
    }
    
    do {
        ret = fread(&db, sizeof(veiculo), 1, arq);
        if(ret == 1) {
            if (strcmp (placa, db.placa) == 0) { // caso a placa digitada pelo usuario coincidir com a placa sendo lida
                found = 1;
            }
            else {
                fwrite(&db, sizeof(veiculo), 1, aux); // as estruturas dos veiculos com placas nao coincidentes com a digitada pelo usuario sao copiadas para o arq auxiliar 
            }
        }
    } while(ret == 1);

    fclose(arq);
    fclose(aux);

    if (found == 1) {
        remove("db.bin");
        rename("temp.bin", "db.bin"); // o arq auxiliar passa a ter o nome do arq principal e o antigo arq principal eh removido
        return 1;
    }
    else {
        remove("temp.bin");
        return -1;
	}
}

void view() {
    int i=1, ret;

    printf("\n[VISUALIZACAO DE VEICULOS]\n");
    do {
        ret = fread(&db, sizeof(veiculo), 1, arq);
        if(ret == 1) {
            printf("%i | %s / %s / %s / %s\n", i, db.marca, db.modelo, db.cor, db.placa);
        }
        i++;
    } while(ret == 1);

    fclose(arq);
}

#endif
