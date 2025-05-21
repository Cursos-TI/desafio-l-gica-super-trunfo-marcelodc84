#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

// ESTRUTURA DO OBJETO CARTA
typedef struct {
    char codigo[5];
    char estado;
    char cidade[50];
    unsigned long int populacao;
    int pontosTuristicos;
    float area;
    float pib;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} CartaCidade;

// FUNÇÕES
CartaCidade CriarCarta() {
    
    CartaCidade carta;
    
    printf("Digite o código da carta: ");
    scanf("%s", carta.codigo);

    printf("Digite o estado da cidade: ");
    scanf(" %c", &carta.estado);

    printf("Digite o nome da cidade: ");
    getchar(); // Limpar o buffer do teclado
    fgets(carta.cidade, sizeof(carta.cidade), stdin);
    carta.cidade[strcspn(carta.cidade, "\n")] = 0; // Remover o caractere de nova linha, se houver

    printf("Digite a população da cidade: ");
    scanf("%lu", &carta.populacao);
    
    printf("Digite a área da cidade: ");
    scanf("%f", &carta.area);
    
    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta.pib);
    
    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta.pontosTuristicos);
    
    //calcular densidade populacional e pib per capita
    carta.densidadePopulacional = (float)carta.populacao / carta.area;
    carta.pibPerCapita = carta.pib / carta.populacao;

    //calcular superpoder
    carta.superPoder = 
        carta.populacao + 
        carta.area + 
        carta.pib + 
        carta.pontosTuristicos +
        carta.pibPerCapita +
        (1 / carta.densidadePopulacional);

    return carta;
}

//exibir os dados da carta
void ExibirCarta(CartaCidade carta) {
    printf("Código: %s\n", carta.codigo);
    printf("Estado: %c\n", carta.estado);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f\n", carta.densidadePopulacional);
    printf("PIB Per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

//comparação das cartas
void CompararCartas(CartaCidade carta1, CartaCidade carta2) {

    printf("População: ");
    if(carta1.populacao > carta2.populacao) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.populacao < carta2.populacao) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }

    printf("Área: ");
    if(carta1.area > carta2.area) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.area < carta2.area) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }

    printf("PIB: ");
    if(carta1.pib > carta2.pib) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.pib < carta2.pib) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }

    printf("Pontos Turísticos: ");
    if(carta1.pontosTuristicos > carta2.pontosTuristicos) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.pontosTuristicos < carta2.pontosTuristicos) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }

    printf("Densidade Populacional: ");
    if(carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.densidadePopulacional > carta2.densidadePopulacional) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }
    
    printf("PIB Per Capita: ");
    if(carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.pibPerCapita < carta2.pibPerCapita) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }
    
    printf("Super Poder: ");
    if(carta1.superPoder > carta2.superPoder) {
        printf("Carta 1 venceu (1)\n");
    } else if(carta1.superPoder < carta2.superPoder) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate\n");
    }
}

// PROGRAMA PRINCIPAL
int main() {
    // Definição das variáveis para armazenar as propriedades das cidades

    //TESTE - definindo as cartas manualmente
    // CartaCidade carta1 = {
    //     .codigo = "A01",
    //     .estado = 'A',
    //     .cidade = "São_Paulo",
    //     .populacao = 12345678,
    //     .pontosTuristicos = 45,
    //     .area = 1500.0,
    //     .pib = 5000000000.0,
    //     .densidadePopulacional = 8200.0,
    //     .pibPerCapita = 40000.0,
    //     .superPoder = 987654321.0
    // };
    // CartaCidade carta2 = {
    //     .codigo = "B01",
    //     .estado = 'B',
    //     .cidade = "Rio_de_Janeiro",
    //     .populacao = 6789012,
    //     .pontosTuristicos = 765,
    //     .area = 1200.0,
    //     .pib = 3000000000.0,
    //     .densidadePopulacional = 5650.0,
    //     .pibPerCapita = 45000.0,
    //     .superPoder = 123456789.0
    // };
    

    CartaCidade carta1;
    CartaCidade carta2;

    //atribuir variáveis cartas
    printf("Vamos agora cadastrar a carta 1:\n");
    carta1 = CriarCarta();

    printf("=============================\n");
    printf("Vamos agora cadastrar a carta 2:\n");
    carta2 = CriarCarta();

    printf("=============================\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("=============================\n");

    // Exibir os dados da carta 1
    printf("Dados da Carta 1:\n");
    ExibirCarta(carta1);
    printf("=============================\n");
    // Exibir os dados da carta 2
    printf("Dados da Carta 2:\n");
    ExibirCarta(carta2);
    printf("=============================\n");
    
    // Comparar as cartas
    printf("\nComparativo das cartas:\n");
    CompararCartas(carta1, carta2);
    printf("\n=============================\n");

    printf("Programa encerrado.\n");

    return 0;
    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}