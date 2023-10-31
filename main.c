#include "filmes.h"

int main() {
  int n, m, i, tam = 0, opMenu, opSubMenu, idFilme;
  printf("Entre com o tamanho da sua tabela: ");
  scanf("%d%*c", &n);

  Filme** v = malloc(sizeof(Filme) * n);
  tam = n;

  for(i=0; i<n; i++) {
    v[i] = malloc(sizeof(Filme));
    printf("Filme %d:", i+1);
    v[i] = criar_filme();
    printf(COLOR_GREEN"Filme %d cadastrado\n\n"COLOR_RESET, i+1);
  }

  printf("\n");
  print_tabela(v, tam);

  opMenu = menu();
  while(opMenu != 4) {
    switch (opMenu) {
      // CADASTRAR NOVO TITULO
      case 1:
        tam++;
        v = realloc(v, sizeof(Filme) * tam);
        v[tam - 1] = malloc(sizeof(Filme));

        printf("Digite os dados do filme:");
        v[tam - 1] = criar_filme();

        printf(COLOR_GREEN"Filme cadastrado com sucesso!\n\n"COLOR_RESET);
        print_tabela(v, tam);

        break;
        
      // SUBMENU 
      case 2:
        if(tam == 0) {
          printf(COLOR_RED"Nenhum filme cadastrado. Selecione outra opção: "COLOR_RESET);
          break;
        } 
        opSubMenu = submenu();

        print_tabela(v, tam);
        printf("Selecione o filme a ser editado: ");

        while(scanf("%d%*c", &idFilme), idFilme > tam || idFilme <= 0) {
          printf(COLOR_RED"Valor incorreto. Digite novamente: "COLOR_RESET);
        }

        idFilme = idFilme - 1;
        
        switch(opSubMenu) {
          // ATUALIZAR NOME E DIRETOR
          case 1:

            {
              char nome[101];
              printf("Nome: ");
              lerString(nome, sizeof(nome));
              set_nome(v[idFilme], nome);
            }

            {
              char diretor[101];
              printf("Diretor: ");
              lerString(diretor, sizeof(diretor));
              set_diretor(v[idFilme], diretor);
            }

            printf(COLOR_GREEN"Dados atualizados com sucesso!\n\n"COLOR_RESET);

            break;
          
          // ATUALIZAR PRECO
          case 2:

            {
              float preco;
              printf("Preco: ");
              scanf("%f%*c", &preco);
              set_preco(v[idFilme], preco);
            }

            printf(COLOR_GREEN"Dados atualizados com sucesso!\n\n"COLOR_RESET);

            break;

          case 3:
            // ATUALIZAR GENERO

            {
              char genero[51];
              printf("Genero: ");
              lerString(genero, sizeof(genero));
              set_genero(v[idFilme], genero);
            }
            printf(COLOR_GREEN"Dados atualizados com sucesso!\n\n"COLOR_RESET);

            break;
          
          default:
            printf(COLOR_RED"Opcao invalida. Tente novamente: "COLOR_RESET);
            break;
        }
        print_tabela(v, tam);
        break;
      // EXCLUIR FILME
      case 3:
        if(tam == 0) {
          printf(COLOR_RED"Nenhum filme cadastrado. Selecione outra opção: "COLOR_RESET);
          break;
        } 
        print_tabela(v, tam);

        printf("Selecione o filme a ser excluido: ");
        while(scanf("%d%*c", &idFilme), idFilme > tam || idFilme <= 0) {
          printf(COLOR_RED"Valor incorreto. Digite novamente: "COLOR_RESET);
        }
        idFilme = idFilme - 1;

        excluir_filme(v, idFilme, tam);
        tam--;
        v = realloc(v, sizeof(Filme) * tam);

        printf(COLOR_GREEN"Exclusao realizada com sucesso!\n\n"COLOR_RESET);
        print_tabela(v, tam);

        break;
      default:
        printf(COLOR_RED"Opcao invalida. Tente novamente:"COLOR_RESET);

        break;
    }

    opMenu = menu();
  }

  printf(COLOR_GREEN"\nPrograma encerrado\n"COLOR_RESET);
  
  return 0;
}