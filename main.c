#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo struct
typedef struct {
    char nome[50];
    float consumo;
    int prioridade;
} Dispositivo;

// função para cadastrar os dispositivos
void
cadastrarDispositivos(Dispositivo* dispositivos, int qtd) {
    for (int i = 0; i < qtd; i++) {
    printf("Digite o nome do dispositivo %d: \n", i + 1);
    printf("Nome: ");
    scanf(" %[^\n]", dispositivos[i].nome); // vai ler só até quebrar a linha
    printf("Consumo em kWh: ");
    scanf("%f", &dispositivos[i].consumo);
    printf("Prioridade: (1-Alta, 2-Média 3-Baixa): ");
    scanf("%d", &dispositivos[i].prioridade);
    }
}

//função para exibir os dispositivos
void exibirDispositivos(Dispositivo* dispositivos, int qtd) {
    printf("\n--- Dispositivos cadastrados ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nNome: %s\n", dispositivos[i].nome);
        printf("\nConsumo: %.2f kWh\n", dispositivos[i].consumo);
        printf("\nPrioridade: ");
        switch (dispositivos[i].prioridade) {
            case 1:
                printf("Alta - Atenção Máxima!\n");
                break;
            case 2:
                printf("Média - Monitoramento Padrão.\n");
                break;
            case 3:
                printf("Baixa - Uso eventual.\n");
                break;
            default:
                printf("Desconhecido.\n");
        }
    }
}

int main() {
    int qtd;

    printf("Digite a quantidade de dispositivos: ");
    scanf("%d", &qtd);

    // Alocação dinâmica dos vetores
    Dispositivo* dispositivos = malloc(qtd * sizeof(Dispositivo));

    if (dispositivos == NULL) {
    printf("Erro ao alocar dispositivos.\n");
        return 1;
    }

cadastrarDispositivos(dispositivos, qtd);
exibirDispositivos(dispositivos, qtd);

free(dispositivos);
return 0;
}