#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 100
#define MAX_NOME 50
#define MAX_AMIGOS 50

typedef struct Usuario {
    int id;
    char nome[MAX_NOME];
    int idade;
    struct Usuario *amigos[MAX_AMIGOS];
    int qtdAmigos;
    struct Usuario *prox;
} Usuario;

// Variável global (cabeça da lista)
extern Usuario *inicio;

// Protótipos
void cadastrarUsuario();
void listarUsuarios();
Usuario* buscarUsuarioPorID(int id);
int idExiste(int id);
void excluirUsuario();

#endif
