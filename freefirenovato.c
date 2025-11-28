#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Definições globais
#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_TIPO 20

// Estrutura do Item (Nível Novato + Prioridade do Mestre)
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
    int prioridade; // 1 a 5
} Item;

// Variáveis Globais de Controle
Item mochila[MAX_ITENS];
int totalItens = 0;
bool ordenadoPorNome = false; // Flag para validar busca binária

// --- Funções Auxiliares ---

// Limpa o buffer do teclado para evitar erros no scanf/fgets
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Funcionalidades Nível Novato ---

void adicionarItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n[!] A mochila está cheia! Descarte algo primeiro.\n");
        return;
    }

    Item novoItem;
    
    printf("\n--- Adicionando Item ---\n");
    printf("Nome: ");
    scanf(" %29[^\n]", novoItem.nome); // Lê string com espaços
    
    printf("Tipo (ex: Arma, Cura, Municao): ");
    scanf(" %19[^\n]", novoItem.tipo);
    
    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);

    do {
        printf("Prioridade (1-Baixa a 5-Alta): ");
        scanf("%d", &novoItem.prioridade);
    } while (novoItem.prioridade < 1 || novoItem.prioridade > 5);

    mochila[totalItens] = novoItem;
    totalItens++;
    ordenadoPorNome = false; // Ao adicionar, a lista pode perder a ordenação
    printf("[+] Item '%s' adicionado com sucesso!\n", novoItem.nome);
}

void listarItens() {
    if (totalItens == 0) {
        printf("\n[!] A mochila está vazia.\n");
        return;
    }

    printf("\n--- Conteúdo da Mochila ---\n");
    printf("%-20s | %-15s | %-3s | %-3s\n", "Nome", "Tipo", "Qtd", "Prio");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%-20s | %-15s | %03d | %d\n", 
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
}

void removerItem() {
    char nomeAlvo[MAX_NOME];
    printf("\nNome do item para remover: ");
    scanf(" %29[^\n]", nomeAlvo);

    int encontrado = -1;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeAlvo) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        // Move os itens subsequentes para trás para preencher o buraco
        for (int i = encontrado; i < totalItens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        totalItens--;
        printf("[-] Item '%s' removido.\n", nomeAlvo);
    } else {
        printf("[!] Item não encontrado.\n");
    }
}
