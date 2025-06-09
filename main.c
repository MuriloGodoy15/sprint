#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo struct
typedef struct {
    char nome[50];
    float consumo;
    int prioridade;
    int ligado; // 1 = ligado, 0 = desligado
} Dispositivo;

// Função para cadastrar os dispositivos
void cadastrarDispositivos(Dispositivo* dispositivos, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Digite o nome do dispositivo %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", dispositivos[i].nome);
        printf("Consumo em kWh: ");
        scanf("%f", &dispositivos[i].consumo);
        printf("Prioridade (1 = Alta, 2 = Média, 3 = Baixa): ");
        scanf("%d", &dispositivos[i].prioridade);
        dispositivos[i].ligado = 0;
    }
}

// Função para exibir os dispositivos
void exibirDispositivos(Dispositivo* dispositivos, int qtd) {
    printf("\n--- Dispositivos cadastrados ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nNome: %s\n", dispositivos[i].nome);
        printf("Consumo: %.2f kWh\n", dispositivos[i].consumo);
        printf("Prioridade: ");
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
                printf("Desconhecida.\n");
        }
    }
}

// Função Bubble Sort para ordenar dispositivos por prioridade (1 = maior prioridade)
void ordenarPorPrioridade(Dispositivo* dispositivos, int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (dispositivos[j].prioridade > dispositivos[j + 1].prioridade) {
                Dispositivo temp = dispositivos[j];
                dispositivos[j] = dispositivos[j + 1];
                dispositivos[j + 1] = temp;
            }
        }
    }
}

// Função de simulação de consumo com base na energia disponível
float simularConsumo(Dispositivo* dispositivos, int qtd, float energiaDisponivel) {
    float consumoTotal = 0.0;

    for (int i = 0; i < qtd; i++) {
        if (consumoTotal + dispositivos[i].consumo <= energiaDisponivel) {
            dispositivos[i].ligado = 1;
            consumoTotal += dispositivos[i].consumo;
        } else {
            dispositivos[i].ligado = 0;
        }
    }

    return consumoTotal;
}

// Função para exibir resultados da simulação
void exibirResultados(Dispositivo* dispositivos, int qtd, float consumoTotal) {
    printf("\n--- Resultado da Simulação ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Dispositivo: %s - %s (%.2f kWh)\n",
               dispositivos[i].nome,
               dispositivos[i].ligado ? "LIGADO" : "DESLIGADO",
               dispositivos[i].consumo);
    }
    printf("\nConsumo total: %.2f kWh\n", consumoTotal);
}

int main() {
    int qtd;
    float energiaDisponivel;

    printf("Digite a quantidade de dispositivos: ");
    scanf("%d", &qtd);

    Dispositivo* dispositivos = malloc(qtd * sizeof(Dispositivo));
    if (dispositivos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    cadastrarDispositivos(dispositivos, qtd);
    exibirDispositivos(dispositivos, qtd);

    printf("\nDigite a energia disponível (em kWh): ");
    scanf("%f", &energiaDisponivel);

    ordenarPorPrioridade(dispositivos, qtd);
    float consumoFinal = simularConsumo(dispositivos, qtd, energiaDisponivel);
    exibirResultados(dispositivos, qtd, consumoFinal);

    free(dispositivos);
    return 0;
}
