#include "parkif.h"

int main() {

    int op = 1;
    char *placa = malloc(20 * sizeof(char));
    veiculo v;

    while(op != 0) {
        init();
        system("cls");
        printf("---------------------------");
        printf("\n- 1) Entrada de Veiculo   -");
        printf("\n- 2) Saida de Veiculo     -");
        printf("\n- 3) Visualizar Veiculos  -");
        printf("\n- 0) Sair                 -");
        printf("\n---------------------------");
        printf("\n>> ");
        scanf("%i", &op);

        switch (op) {
        case 1:
            printf("\n[ENTRADA DE VEICULO]");
            printf("\n- Marca: ");
            fflush(stdin);
            gets(v.marca);
            printf("- Modelo: ");
            fflush(stdin);
            gets(v.modelo);
            printf("- Cor: ");
            fflush(stdin);
            gets(v.cor);
            printf("- Placa: ");
            fflush(stdin);
            gets(v.placa);

            add(v);

            printf("\n[OK]");
            fflush(stdin);
            getchar();
        break;

        case 2:
            printf("\n[SAIDA DE VEICULO]");
            printf("\n- Placa: ");
            fflush(stdin);
            gets(placa);
            switch(rem(placa)) {
                case 0:
                    printf("\n[ERRO]: Nao ha carro no estacionamento!");
                    fflush(stdin);
                    getchar();
                break;
                case 1:
                    printf("\n[OK]");
                    fflush(stdin);
                    getchar();
                break;
                case -1:
                    printf("\n[ERRO]: Placa nao encontrada!");
                    fflush(stdin);
                    getchar();
                break; 
            }
        break;

        case 3:
            view();
            fflush(stdin);
            getchar();
        break;
        }
    }

    printf("\n");
    return 0;
}
