#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "usuario.h"

Usuario *inicio = NULL; // cabeça da lista

// Função para verificar se um ID já existe
int idExiste(int id) {
    Usuario *temp = inicio;
    while (temp != NULL) {
        if (temp->id == id)
            return 1;
        temp = temp->prox;
    }
    return 0;
}

// Cadastrar novo usuário
void cadastrarUsuario() {
    Usuario *novo = (Usuario*) malloc(sizeof(Usuario));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    int aleatorio;
    do {
        aleatorio = rand() % 9000 + 1000;
        novo->id = 20250000 + aleatorio;
    } while (idExiste(novo->id));

    printf("\nDigite o nome completo do usuario: ");
    fflush(stdin);
    fgets(novo->nome, MAX_NOME, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &novo->idade);

    novo->qtdAmigos = 0;
    novo->prox = inicio;
    inicio = novo;

    printf("\nUsuario cadastrado com sucesso!\n");
    printf("ID: %d\n", novo->id);
}

// Listar todos os usuários
void listarUsuarios() {
    if (inicio == NULL) {
        printf("\nNenhum usuario cadastrado.\n");
        return;
    }

    printf("\n===== PERFIS CADASTRADOS =====\n");
    Usuario *atual = inicio;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s | Idade: %d | Amigos: %d\n",
               atual->id, atual->nome, atual->idade, atual->qtdAmigos);
        atual = atual->prox;
    }
}

// Buscar usuário por ID
Usuario* buscarUsuarioPorID(int id) {
    Usuario *atual = inicio;
    while (atual != NULL) {
        if (atual->id == id)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

// Excluir usuário e remover suas amizades
void excluirUsuario() {
    int id;
    printf("\nDigite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);

    if (inicio == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    Usuario *atual = inicio, *anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    Usuario *temp = inicio;
    while (temp != NULL) {
        int i = 0;
        while (i < temp->qtdAmigos) {
            if (temp->amigos[i] == atual) {
                temp->amigos[i] = temp->amigos[temp->qtdAmigos - 1];
                temp->qtdAmigos--;
            } else {
                i++;
            }
        }
        temp = temp->prox;
    }

    if (anterior == NULL)
        inicio = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    printf("Usuario removido com sucesso.\n");
}
