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
    printf("=============================\n\n");

    
    int opcao;
    printf("\nMenu de comparação:\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparativo das cartas:\n");
    switch(opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %lu\n", carta1.cidade, carta1.populacao);
            printf("%s: %lu\n", carta2.cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.populacao < carta2.populacao)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Área:\n");
            printf("%s: %.2f\n", carta1.cidade, carta1.area);
            printf("%s: %.2f\n", carta2.cidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.area < carta2.area)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("PIB:\n");
            printf("%s: %.2f\n", carta1.cidade, carta1.pib);
            printf("%s: %.2f\n", carta2.cidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.pib < carta2.pib)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Pontos Turísticos:\n");
            printf("%s: %d\n", carta1.cidade, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.cidade, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f\n", carta1.cidade, carta1.densidadePopulacional);
            printf("%s: %.2f\n", carta2.cidade, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.densidadePopulacional > carta2.densidadePopulacional)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 0:
            printf("Programa encerrado.\n");
            return 0;
        default:
            printf("Opção inválida!\n");
    }

    printf("\n=============================\n");
    

    printf("Programa encerrado.\n");

    return 0;
    

}