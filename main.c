#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "usuario.h"
#include "rede.h"

int menu() {
    int opcao;
    int resultado;
    
    printf("\n===== MENU =====\n");
    printf("1 - Cadastrar usuario\n");
    printf("2 - Excluir usuario\n");
    printf("3 - Criar amizade\n");
    printf("4 - Remover amizade\n");
    printf("5 - Listar usuarios\n");
    printf("6 - Listar amizades\n");
    printf("0 - Sair\n");
    
    printf("Escolha uma opcao: ");
    resultado = scanf("%d", &opcao);

    if (resultado != 1) {
        printf("Entrada invalida! Digite apenas numeros.\n");
        while (getchar() != '\n'); // limpa o buffer de entrada
        return -1; // retorna um valor inválido para o main tratar
    }

    return opcao;
}

int main() {
    int opcao;
    srand(time(NULL));

    do {
        opcao = menu();

        if (opcao == -1) continue; // se entrada inválida, volta pro menu

        switch (opcao) {
            case 1: cadastrarUsuario(); break;
            case 2: excluirUsuario(); break;
            case 3: criarAmizade(); break;
            case 4: removerAmizade(); break;
            case 5: listarUsuarios(); break;
            case 6: listarAmizadesUsuario(); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberação de memória antes de sair
    Usuario *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }

    return 0;
}