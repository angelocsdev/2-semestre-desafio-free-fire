#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// -----------------------------------------------------
// STRUCT ITEM
// Armazena dados essenciais de um objeto do inventário
// -----------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor global de itens
Item mochila[MAX_ITENS];
int totalItens = 0;

// -----------------------------------------------------
// Função: inserirItem()
// Adiciona um novo item à mochila (até 10 itens)
// -----------------------------------------------------
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n❌ A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo do item (arma, municao, cura...): ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\n✔ Item cadastrado com sucesso!\n");
}

// -----------------------------------------------------
// Função: removerItem()
// Remove um item pelo nome (busca sequencial)
// -----------------------------------------------------
void removerItem() {
    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {

            // Desloca os itens após o removido
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            totalItens--;
            printf("\n✔ Item removido com sucesso!\n");
            return;
        }
    }

    printf("\n❌ Item não encontrado!\n");
}

// -----------------------------------------------------
// Função: listarItens()
// Exibe todos os itens cadastrados
// -----------------------------------------------------
void listarItens() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    printf("\n====== ITENS NA MOCHILA ======\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// -----------------------------------------------------
// Função: buscarItem()
// Busca sequencial por nome e exibe os dados
// -----------------------------------------------------
void buscarItem() {
    char nomeBuscar[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBuscar);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBuscar) == 0) {
            printf("\n📌 Item encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\n❌ Item não encontrado!\n");
}

// -----------------------------------------------------
// Função principal: menu de interação
// -----------------------------------------------------
int main() {
    int opcao;

    do {
        printf("\n======== SISTEMA DE INVENTÁRIO ========\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;

            case 2:
                removerItem();
                listarItens();
                break;

            case 3:
                listarItens();
                break;

            case 4:
                buscarItem();
                break;

            case 5:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
