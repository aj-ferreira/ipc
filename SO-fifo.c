#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um pedido de disco
typedef struct {
    int cilindro;  // N�mero do cilindro
    int tempo_chegada;  // Tempo de chegada do pedido
} Pedido;

// Fun��o para comparar pedidos com base no tempo de chegada
int comparar_pedidos(const void *a, const void *b)
{
    Pedido *pedido1 = (Pedido *)a;
    Pedido *pedido2 = (Pedido *)b;
    return pedido1->tempo_chegada - pedido2->tempo_chegada;
}

// Fun��o para executar o escalonamento FCFS
void escalonamento_fcfs(Pedido *pedidos, int num_pedidos) {
    // Ordena os pedidos com base no tempo de chegada
    qsort(pedidos, num_pedidos, sizeof(Pedido), comparar_pedidos);

    // Processa os pedidos na ordem de chegada
    int posicao_braco = 0;  // Posi��o inicial do bra�o de disco
    int tempo_total = 0;  // Tempo total de busca
    for (int i = 0; i < num_pedidos; i++) {
        // Calcula o tempo de busca
        int tempo_busca = abs(pedidos[i].cilindro - posicao_braco);

        // Atualiza a posi��o do bra�o de disco
        posicao_braco = pedidos[i].cilindro;

        // Acumula o tempo total de busca
        tempo_total += tempo_busca;

        // Imprime os detalhes do pedido
        printf("Pedido %d: Cilindro %d, Tempo de Busca %d\n", i + 1, pedidos[i].cilindro, tempo_busca);
    }

    // Calcula o tempo m�dio de busca
    float tempo_medio_busca = (float)tempo_total / num_pedidos;

    // Imprime o tempo m�dio de busca
    printf("Tempo M�dio de Busca: %.2f\n", tempo_medio_busca);
}

int main() {
    // N�mero de pedidos
    int num_pedidos;
    printf("Digite o n�mero de pedidos: ");
    scanf("%d", &num_pedidos);

    // Cria um array de pedidos
    Pedido pedidos[num_pedidos];

    // L� os detalhes do pedido
    for (int i = 0; i < num_pedidos; i++) {
        printf("Digite o n�mero do cilindro para o Pedido %d: ", i + 1);
        scanf("%d", &pedidos[i].cilindro);
        printf("Digite o tempo de chegada para o Pedido %d: ", i + 1);
        scanf("%d", &pedidos[i].tempo_chegada);
    }

    // Executa o escalonamento FCFS
    escalonamento_fcfs(pedidos, num_pedidos);

    return 0;
}

