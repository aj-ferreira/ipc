#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um pedido de disco
struct Request {
    int cilindro;
    int direcao;
};

// Fun��o para comparar dois pedidos com base em seus cilindros
int compareRequests(const void *a, const void *b) {
    struct Request *req1 = (struct Request *)a;
    struct Request *req2 = (struct Request *)b;

    return req1->cilindro - req2->cilindro;
}

// Fun��o para executar o algoritmo SSTF
void sstf(struct Request *requests, int num_requests) {
    // Inicializa o cabe�ote do disco na posi��o 0
    int head = 0;

    // Ordena os pedidos com base em seus cilindros
    qsort(requests, num_requests, sizeof(struct Request), compareRequests);

    // Percorre os pedidos
    for (int i = 0; i < num_requests; i++) {
        // Calcula a dist�ncia entre o cabe�ote do disco e o cilindro do pedido atual
        int distance = abs(head - requests[i].cilindro);

        // Move o cabe�ote do disco para o cilindro do pedido atual
        head = requests[i].cilindro;

        // Imprime o n�mero do cilindro e a dist�ncia percorrida
        printf("Movendo para o cilindro %d (distancia: %d)\n", head, distance);
    }
}

// Fun��o principal
int main() {
    // Cria um conjunto de pedidos de disco
    struct Request requests[] = {
        {176, 1},
        {79, 1},
        {190, 1},
        {92, 1},
        {160, 1},
        {8, 1},
        {48, 1},
        {94, 1},
        {205, 1},
    };

    // Obt�m o n�mero de pedidos
    int num_requests = sizeof(requests) / sizeof(struct Request);

    // Executa o algoritmo SSTF
    sstf(requests, num_requests);

    return 0;
}
