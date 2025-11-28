#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Struct representando um item da mochila
struct Item {
    char nome[50];
    char tipo[50];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA - DESAFIO CODIGO DA ILHA =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch(opcao) {
            case 1: {
                if (totalItens >= MAX_ITENS) {
                    printf("\n⚠️ Mochila cheia! Nao e possivel adicionar mais itens.\n");
                    break;
                }

                printf("\n--- Adicionar Item ---\n");
                printf("Nome: ");
                fgets(mochila[totalItens].nome, 50, stdin);
                strtok(mochila[totalItens].nome, "\n");

                printf("Tipo: ");
                fgets(mochila[totalItens].tipo, 50, stdin);
                strtok(mochila[totalItens].tipo, "\n");

                printf("Quantidade: ");
                scanf("%d", &mochila[totalItens].quantidade);
                getchar();

                totalItens++;

                printf("\n✔ Item adicionado com sucesso!\n");
                break;
            }

            case 2: {
                if (totalItens == 0) {
                    printf("\n⚠️ Nenhum item na mochila para remover.\n");
                    break;
                }

                char nomeRemover[50];
                printf("\n--- Remover Item ---\n");
                printf("Nome do item: ");
                fgets(nomeRemover, 50, stdin);
                strtok(nomeRemover, "\n");

                int encontrado = -1;
                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if (encontrado == -1) {
                    printf("\n❌ Item nao encontrado!\n");
                } else {
                    // Desloca itens para preencher o espaço removido
                    for (int i = encontrado; i < totalItens - 1; i++) {
                        mochila[i] = mochila[i + 1];
                    }
                    totalItens--;
                    printf("\n✔ Item removido com sucesso!\n");
                }
                break;
            }

            case 3: {
                printf("\n--- Itens na Mochila ---\n");

                if (totalItens == 0) {
                    printf("A mochila esta vazia.\n");
                } else {
                    printf("%-20s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("-------------------------------------------------------\n");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-20s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;
            }

            case 4:
                printf("\nSaindo... Ate mais, guerreiro!\n");
                break;

            default:
                printf("\n❌ Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
