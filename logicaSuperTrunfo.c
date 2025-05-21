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

int CalcularResultado(CartaCidade carta1, CartaCidade carta2, int opcao) {
    switch(opcao) {
        case 1:
            return (carta1.populacao > carta2.populacao) ? 1 : 0;
        case 2:
            return (carta1.area > carta2.area) ? 1 : 0;
        case 3:
            return (carta1.pib > carta2.pib) ? 1 : 0;
        case 4:
            return (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 0;
        case 5:
            return (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 0;
        default:
            return 0;
    }
}

// PROGRAMA PRINCIPAL
int main() {
    // Definição das variáveis para armazenar as propriedades das cidades

    //TESTE - definindo as cartas manualmente
    CartaCidade carta1 = {
        .codigo = "A01",
        .estado = 'A',
        .cidade = "São Paulo",
        .populacao = 12345678,
        .pontosTuristicos = 45,
        .area = 1500.0,
        .pib = 5000000000.0,
        .densidadePopulacional = 8200.0,
        .pibPerCapita = 40000.0,
        .superPoder = 987654321.0
    };
    CartaCidade carta2 = {
        .codigo = "B01",
        .estado = 'B',
        .cidade = "Rio de Janeiro",
        .populacao = 6789012,
        .pontosTuristicos = 765,
        .area = 1200.0,
        .pib = 3000000000.0,
        .densidadePopulacional = 5650.0,
        .pibPerCapita = 45000.0,
        .superPoder = 123456789.0
    };
    

    // CartaCidade carta1;
    // CartaCidade carta2;

    // //atribuir variáveis cartas
    // printf("Vamos agora cadastrar a carta 1:\n");
    // carta1 = CriarCarta();

    // printf("=============================\n");
    // printf("Vamos agora cadastrar a carta 2:\n");
    // carta2 = CriarCarta();

    printf("=============================\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("=============================\n\n");

    
    int opcao1, opcao2, resultado1, resultado2;
    printf("\nMenu de comparação:\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    printf("Escolha o segundo atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    if(opcao1 == opcao2){
        printf("Você não pode escolher o mesmo atributo para comparar!\n");
        printf("Programa encerrado.\n");
        return 0;
    }

    resultado1 = CalcularResultado(carta1, carta2, opcao1);
    resultado2 = CalcularResultado(carta1, carta2, opcao2);

    if(resultado1 && resultado2){
        printf("A carta 1 (%s - %s) venceu!\n", carta1.codigo, carta1.cidade);
    } else if(resultado1 != resultado2){
        printf("Empate!\n");
    } else {
        printf("A carta 2 (%s - %s) venceu!\n", carta2.codigo, carta2.cidade);
    }

    printf("\n=============================\n");

    printf("Programa encerrado.\n");

    return 0;
    

}