#include <stdio.h>
#include "rede.h"
#include "usuario.h"

void criarAmizade() {
    int id1, id2;
    printf("\nDigite o ID do primeiro usuário: ");
    scanf("%d", &id1);
    printf("Digite o ID do segundo usuário: ");
    scanf("%d", &id2);

    if (id1 == id2) {
        printf("Um usuário não pode ser amigo dele mesmo.\n");
        return;
    }

    Usuario *u1 = buscarUsuarioPorID(id1);
    Usuario *u2 = buscarUsuarioPorID(id2);

    if (u1 == NULL || u2 == NULL) {
        printf("Um ou ambos os usuários não existem.\n");
        return;
    }

    int i = 0;
	for ( ; i < u1->qtdAmigos; i++) {
        if (u1->amigos[i] == u2) {
            printf("Esses usuários já são amigos.\n");
            return;
        }
    }

    if (u1->qtdAmigos >= MAX_AMIGOS || u2->qtdAmigos >= MAX_AMIGOS) {
        printf("Um dos usuários atingiu o limite de amigos.\n");
        return;
    }

    u1->amigos[u1->qtdAmigos++] = u2;
    u2->amigos[u2->qtdAmigos++] = u1;

    printf("\nAmizade criada com sucesso entre %s e %s!\n", u1->nome, u2->nome);
}

void removerAmizade() {
    int id1, id2;
    printf("\nDigite o ID do primeiro usuario: ");
    scanf("%d", &id1);
    printf("Digite o ID do segundo usuario: ");
    scanf("%d", &id2);

    if (id1 == id2) {
        printf("Um usuario nao pode remover amizade consigo mesmo.\n");
        return;
    }

    Usuario *u1 = buscarUsuarioPorID(id1);
    Usuario *u2 = buscarUsuarioPorID(id2);

    if (u1 == NULL || u2 == NULL) {
        printf("Um ou ambos os usuarios nao existem.\n");
        return;
    }

    int encontrou = 0;
    int i = 0;
    for ( ; i < u1->qtdAmigos; i++) {
        if (u1->amigos[i] == u2) {
            u1->amigos[i] = u1->amigos[u1->qtdAmigos - 1];
            u1->qtdAmigos--;
            encontrou = 1;
            break;
        }
    }

    if (encontrou) {
    	int i = 0;
        for ( ; i < u2->qtdAmigos; i++) {
            if (u2->amigos[i] == u1) {
                u2->amigos[i] = u2->amigos[u2->qtdAmigos - 1];
                u2->qtdAmigos--;
                break;
            }
        }
        printf("\nAmizade removida com sucesso.\n");
    } else {
        printf("\nEsses usuarios nao sao amigos.\n");
    }
}

void listarAmizadesUsuario() {
    if (inicio == NULL) {
        printf("\nNenhum usuario cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario: ");
    scanf("%d", &id);

    Usuario *atual = buscarUsuarioPorID(id);
    if (atual == NULL) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    if (atual->qtdAmigos == 0) {
        printf("O usuario %s (ID: %d) nao possui amigos.\n", atual->nome, atual->id);
        return;
    }

    printf("Amigos de %s (ID: %d):\n", atual->nome, atual->id);
    int i = 0;
    for ( ; i < atual->qtdAmigos; i++) {
        printf("- %s (ID: %d)\n", atual->amigos[i]->nome, atual->amigos[i]->id);
    }
}
