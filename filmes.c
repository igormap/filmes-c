#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filmes.h"

//estrutura para um Filme
typedef struct filme Filme;

void lerString(char *texto, int tam) {

  if(tam == 101) {
    while (scanf("%101[^\n]", texto) == 1 && strlen(texto) > tam-1) {
      limpaBuffer(texto);
      printf(COLOR_RED"Limite de caracteres excedido. Tente novamente: \n"COLOR_RESET);
    }
  } else if(tam == 51) {
    while (scanf("%51[^\n]", texto) == 1 && strlen(texto) > tam-1) {
      limpaBuffer(texto);
      printf(COLOR_RED"Limite de caracteres excedido. Tente novamente: \n"COLOR_RESET);
    }
  }
  limpaBuffer(texto);

}

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme() {
  Filme* novoFilme = malloc(sizeof(Filme));
  char nome[101];
  char genero[51];
  char diretor[101];
  float preco;
  int ano, faixaEtaria;

  printf("\nNome: ");
  lerString(nome, sizeof(nome));
  set_nome(novoFilme, nome);

  printf("Preco: ");
  scanf("%f%*c", &preco);
  set_preco(novoFilme, preco);

  novoFilme->informacoes = malloc(sizeof(Info));

  printf("Diretor: ");
  lerString(diretor, sizeof(diretor));
  set_diretor(novoFilme, diretor);

  printf("Ano: ");
  scanf("%d%*c", &ano);
  set_ano(novoFilme, ano);

  printf("Genero: "); 
  lerString(genero, sizeof(genero));
  set_genero(novoFilme, genero);

  printf("Faixa etaria: ");
  scanf("%d%*c", &faixaEtaria);

  if(strstr(novoFilme->informacoes->genero, "Terror") || strstr(novoFilme->informacoes->genero, "terror")) {
    while(faixaEtaria < 18) {
      printf(COLOR_RED"Faixa etária inválida. Tente novamente.\n"COLOR_RESET);
      printf("Faixa etaria: ");
      scanf("%d%*c", &faixaEtaria);
    }
  }

  set_faixaetaria(novoFilme, faixaEtaria);
  printf("\n");

  return novoFilme;
}

int menu() {
  int n;
  printf("\n==========================================");
  printf("\nMENU DE OPCOES\n\n");
  printf("1 - CADASTRAR UM NOVO TITULO \n2 - ATUALIZAR INFO DE UM TITULO \n3 - EXCLUIR UM TITULO \n4 - FINALIZAR OPERACAO\n\n");
  
  printf("Opcao: ");
  scanf("%d%*c", &n);
  return n;
}

int submenu() {
  int n;
  printf("  1 - RENOMEAR TITULO \n  2 - ATUALIZAR PRECO \n  3 - ATUALIZAR GENERO\n\n");

  printf("Opcao: ");
  scanf("%d%*c", &n);
  return n;
}

void free_filme(Filme* f) {
  free(f);
}

void excluir_filme(Filme** f, int pos, int tam) {
  for(int i = pos; i < tam-1; i++) {
    f[i] = f[i+1];
  }

  free_filme(f[tam]);
}

void imprimir_filme(Filme* f) {
  printf("%.2f R$ || ", f->preco);
  printf("%s ", f->nome);
  printf("(%s, %d) || ", f->informacoes->genero, f->informacoes->faixaEtaria);
  printf("%s %d\n", f->informacoes->diretor, f->informacoes->ano);
}

void print_tabela(Filme** tabela, int tam) {
  printf("-------------TABELA DE FILMES-------------\n\n");

  for(int i = 0; i < tam; i++){
    printf("%.4d -- ",i+1); //código de 4 caracteres
    imprimir_filme(tabela[i]);
  }
  if(tam == 0) printf("Nenhum filme cadastrado.");
  printf("\n");

  // menu();
}

//FUNÇÕES DE MANIPULAÇÃO

void set_nome(Filme* f, char* novo) {
  strcpy(f->nome, novo);
}

void set_preco(Filme* f, float novo) {
  f->preco = novo;
}

void set_diretor(Filme* f, char* novo) {
  strcpy(f->informacoes->diretor, novo);
}

void set_genero(Filme* f, char* novo) {
  strcpy(f->informacoes->genero, novo);
}

void set_ano(Filme* f, int novo) {
  f->informacoes->ano = novo;
}

void set_faixaetaria(Filme* f, int novo) {
  f->informacoes->faixaEtaria = novo;
}

void limpaBuffer(char *p1) {
  int lenp1 = strlen(p1);

  if(p1[lenp1] == '\n') {
    p1[--lenp1] = 0;
    lenp1 = strlen(p1);
  }
  else {
    char ch = p1[lenp1];
    do {
      ch = getchar();
    } while(ch != '\n');
  }
}