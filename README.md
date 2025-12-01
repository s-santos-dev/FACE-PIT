# Mini Rede Social em C ( FacePit )

Este projeto implementa um sistema simples que simula uma **mini rede social**, permitindo cadastrar usuários, gerenciar amizades e exibir informações da rede.  
Todo o programa foi desenvolvido em linguagem **C**, utilizando conceitos como **listas encadeadas**, **manipulação de ponteiros**, **modularização** e **alocação dinâmica de memória**.

---

## 📌 Funcionalidades

### 👤 **Gerenciamento de Usuários**
- Cadastrar usuários com ID único gerado automaticamente  
- Listar todos os usuários cadastrados  
- Buscar usuário pelo ID  
- Excluir usuário  
- Remover automaticamente o usuário da lista de amigos dos outros

### 🤝 **Gerenciamento de Amizades**
- Criar amizade entre dois usuários  
- Remover amizade  
- Listar todos os amigos de um usuário  

### 🧭 **Menu Interativo**
O usuário navega pelas funcionalidades através de um menu exibido no terminal.

---

## 📂 Estrutura do Projeto

O projeto está organizado em módulos, separando as responsabilidades em arquivos `.c` e `.h` para melhorar a organização, legibilidade e manutenção.

# main.c
Arquivo principal do programa.
Contém:
- Função main( )
- Função menu( )
- Loop principal de execução
- Chamadas para todos os módulos
- Liberação da memória ao final
---

## usuario.h
Cabeçalho do módulo de usuários.
Contém:
- Definição da struct Usuario
- Constantes (MAX_NOME, MAX_AMIGOS etc.)
- Protótipos das funções
- Declaração da variável global "inicio"
---

## usuario.c
implementa o módulo de usuários.
Contém:
- Implementação da lista encadeada
- Geração de IDs automáticos
- Cadastro de usuários
- Busca por ID
- Listagem
- Exclusão, incluindo remoção de amizades ligadas
---

## rede.h
Cabeçalho do módulo de amizades.
Contém:
- Protótipos para criar, remover e listar amizades
---

## rede.c
Implementando o módulo de amizades.  
Contém:  
- Criar Amizades (bi-direcional)  
- Remover amizade (bi-direcional)  
- Listar amizades de um usuário  

## Copilando
- Certifique-se de ter o gcc instalado.
- Compile no terminal com:
- gcc main.c usuario.c rede.c -o FacePit.exe

## Executando
- Abra o terminal e utilize.
- .\FacePit.exe

### Exemplo:

===== MENU =====  
1 - Cadastrar usuário  
2 - Excluir usuário  
3 - Criar amizade  
4 - Remover amizade  
5 - Listar usuários  
6 - Listar amizades  
0 - Sair  
Escolha uma opcao:  

## 👨‍💻 Autores:  
- Simão Santos  
- João Victor  
- Ariel Jafferson  

Desenvolvido para fins acadêmicos e didáticos, com foco em lógica de programação, modularização em C e estruturas encadeadas.  
