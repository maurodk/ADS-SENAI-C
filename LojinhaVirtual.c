#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxproducts 10

void clean()
{
    // Limpar terminal
    printf("\e[1;1H\e[2J");
}

typedef struct
{
    int code;
    char ProductName[100];
    float ProductPrice;
} product;

product products[maxproducts];

int NumProducts = 0;
int code = 0;

void AddProduct()
{
    if (NumProducts == maxproducts)
    {
        printf("\n!!! VOCÊ ATINGIU O MÁXIMO DE PRODUTOS ADICIONADOS !!!\n");
        return;
    }

    product product;

    printf("Informe o nome do produto: ");
    fgets(product.ProductName, 100, stdin);

    printf("Informe o preço do produto: ");
    scanf("%f", &product.ProductPrice);

    product.code = ++code;

    products[NumProducts++] = product;

    clean();
    printf("Seu produto foi cadastrado com sucesso!\nO código do produto é: %d\n", product.code);
}

void FindProduct()
{
    int code;
    printf("Informe o código do produto: ");
    scanf("%d", &code);

    for (int i = 0; i < NumProducts; i++)
    {
        if (products[i].code == code)
        {
            clean();
            printf("\nSeu produto foi encontrado com sucesso!\nNome: %sPreço: R$%.2f\n", products[i].ProductName, products[i].ProductPrice);
            return;
        }
        else
        {
            clean();
            printf("\nSeu produto não foi encontrado :(\n");
        }
    }
}

int main()
{
    int option;

    while (1)
    {
        printf("\nBem-vindo ao Pompas! Sua loja digital!\n\n");
        printf("1. Cadastrar produto.\n");
        printf("2. Buscar produto cadastrado.\n");
        printf("3. Sair do sistema\n\n");
        printf("Porfavor, digite a opção desejada: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            AddProduct();
            break;
        case 2:
            FindProduct();
            break;
        case 3:
            printf("Saindo do sistema...\n");
            return 0;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
