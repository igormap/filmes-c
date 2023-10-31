// inclusão das bibliotecas necessárias para a aplicacao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definição das cores a serem usadas nas mensagens para o usuário
#define COLOR_RED      "\x1b[31m"
#define COLOR_GREEN    "\e[0;32m"
#define COLOR_RESET    "\e[0m"

typedef struct info {
  char diretor[101]; //101 caracteres + 1 para fim de string
  char genero[51]; //50 caracteres + 1 para fim de string
  int ano;
  int faixaEtaria; // Use 0 para classificação livre
} Info;

typedef struct filme {
  char nome[101]; //100 caracteres + 1 para fim de string
  float preco; // Até duas casas decimais
  Info* informacoes; // Ponteiro para struct Info
} Filme;

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme();

// Função que mostra o menu de seleção de ações e retorna a opção escolhida pelo usuário
int menu();

// Função que mostra os subitens relacionadas ao menu de atualizar infos de um título e retorna opção escolhida pelo usuário
int submenu();

//Função que libera memória
void free_filme(Filme* f);

// Funçõo que exclui um filme do vetor
void excluir_filme(Filme** f, int pos, int tam);

//função que imprime informações de um filme
void imprimir_filme(Filme* f);

// Função que imprime a tabela atualizada dos filmes cadastrados
void print_tabela(Filme** tabela, int tam);

//FUNÇÕES DE MANIPULAÇÃO

//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo);

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo);

//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo);

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo);

//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo);

//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo);

// função que limpa buffer do teclado quando o usuário digita mais caracteres do que a vetor de char permite
void limpaBuffer(char *p1);

// função que lê string validando o tamanho da string passada como referência
void lerString(char *texto, int tam);