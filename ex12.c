/***************************************************************************
 *   ex12.c                                 Version 20160520.000202      *
 *                                                                         *
 *   Convert AFD into Exp Reg                                              *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file ex12.c
 * @ingroup GroupUnique
 * @brief Convert AFD into Exp Reg
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2016-05-20
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc ex12.c -o ex12.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include "ex12.h" /* library with definitions */
#include <string.h>

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <assert.h> */ /* Verify assumptions with assert */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./ex12 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
  int opt; /* return from getopt() */
  FILE *arq = NULL;
  quint_t q;

  arq = fopen("01-entrada.txt", "r");
  if(arq == NULL)
  {
    printf("Erro ao abrir arquivo\n");
    exit(0);
  }
  pegaEntrada(&q, arq);
  criaEstadoInicial(&q);
  criaEstadoFinal(&q);
  imprimeQuintupla(q);
  encurtaEstadoKleene(&q, 1);
  imprimeQuintupla(q);
  encurtaEstadoKleene(&q, 2);
  imprimeQuintupla(q);
  encurtaEstadoE(&q, 1);
  imprimeQuintupla(q);

  /*ex12_init();  initialization function */

  /*IFDEBUG("Starting optarg loop...\n"); */

  /* getopt() configured options:
   *        -h  help
   *        -V  version
   *        -v  verbose
   */
  opterr = 0;
  while((opt = getopt(argc, argv, "vhV")) != EOF)
    switch(opt)
    {
      case 'h':
        help();
        break;
      case 'V':
        copyr();
        break;
      case 'v':
        verb++;
        break;
      case '?':
      default:
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

  if(verb)
    printf("Verbose level set at: %d\n", verb);
  /* ...and we are done */
  return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
void pegaEntrada (quint_t *q, FILE *arq)
{
  /* as variaveis que comecam com p irao apenas guardar momentaneamente os dados */
  int pk;
  char pa;
  int ps0;
  char s[SBUFF];
  int pf[SBUFF];
  int i = 0;
  int c = 0;
  int pei;
  char pc;
  int pef;

  q->f = NULL;
  q->d = NULL; 
  fscanf(arq, "%d\n%c\n%d\n", &pk, &pa, &ps0);
  q->k = pk;
  q->a = pa;
  q->s0 = ps0;

  fgets(s, sizeof(s), arq);
  while(s[i] != '\0')
  {
    if(s[i] != ' ' && s[i] != '\n')
    {
      pf[c] = s[i] - ZERO_EM_ASCII;
      c++;
    }
    i++;
  }

  i = 0;
  /* while(pf[i] != '\0') */
  for(i = 0; i < c; i++)
  {
    insereNosEstadosFinais(&q->f, pf[i]);
  }

  while(!feof(arq))
  {
    fscanf(arq, "%d %c %d\n", &pei, &pc, &pef);
    insereNaFuncaoDelta(&q->d, pei, pc, pef);
  }

  return;
}

/* ---------------------------------------------------------------------- */
void insereNaFuncaoDelta (delta_t **d, int ei, char c, int ef)
{
  delta_t *cont = *d;;
  delta_t *ant = NULL;
  int i;

  while(cont != NULL)
  {
    ant = cont;
    cont = cont->prox;
  }
  cont = malloc(sizeof(delta_t));
  cont->prox = NULL;

  cont->ei = ei;
  i = finalDoVetor(cont->s);
  cont->s[i] = c;
  cont->ef = ef;

  if(ant != NULL)
    ant->prox = cont;
  else
    *d = cont;

  return;
}

/* ---------------------------------------------------------------------- */
void insereComVetorNaFuncaoDelta (delta_t **d, int ei, char s[SBUFF], int ef)
{
  delta_t *cont = *d;;
  delta_t *ant = NULL;

  while(cont != NULL)
  {
    ant = cont;
    cont = cont->prox;
  }
  cont = malloc(sizeof(delta_t));
  cont->prox = NULL;

  cont->ei = ei;
  strcpy(cont->s, s);
  cont->ef = ef;

  if(ant != NULL)
    ant->prox = cont;
  else
    *d = cont;

  return;
}

/* ---------------------------------------------------------------------- */
void novoElementoDelta (delta_t **d, int ei, char vet[SBUFF], int ef)
{
  delta_t *cont = *d;
  delta_t *ant = NULL;

  while(cont != NULL)
  {
    ant = cont;
    cont = cont->prox;
  }

  cont = malloc(sizeof(delta_t));
  cont->prox = NULL;
  cont->ei = ei;
  strcpy(cont->s, vet);
  cont->ef = ef;

  if(ant != NULL)
    ant->prox = cont;
  else
    *d = cont;

  return;
}

/* ---------------------------------------------------------------------- */
void insereNosEstadosFinais (ef_t **p, int f)
{
  ef_t *cont = *p;;
  ef_t *ant = NULL;

  while(cont != NULL)
  {
    ant = cont;
    cont = cont->prox;
  }
  cont = malloc(sizeof(ef_t));
  cont->prox = NULL;

  cont->f = f;

  if(ant != NULL)
    ant->prox = cont;
  else
    *p = cont;

  return;
}

/* ---------------------------------------------------------------------- */
int finalDoVetor (char s[SBUFF])
{
  int i = 0;

  while(s[i] != '\0')
    i++;

  return i;
}

/* ---------------------------------------------------------------------- */
void imprimeQuintupla (quint_t q)
{
  printf("QUINTUPLA\n\n");
  printf("numero de estados = %d\n", q.k);
  printf("ultima letra do alfabeto = %c\n", q.a);
  printf("estado inicial = %d\n", q.s0);
  imprimeListaDeEstadosFinais(q);
  imprimeFuncaoDelta(q.d);

  return;
}

/* ---------------------------------------------------------------------- */
void imprimeListaDeEstadosFinais (quint_t q)
{
  ef_t *cont = q.f;

  while(cont != NULL)
  {
    printf("%d\n", cont->f);
    cont = cont->prox;
  }
  return;
}

/* ---------------------------------------------------------------------- */
void imprimeFuncaoDelta (delta_t *head)
{
  delta_t *cont = head;

  while(cont != NULL)
  {
    printf("(%d, %s, %d)\n", cont->ei, cont->s, cont->ef);
    cont = cont->prox;
  }
  return;
}

/* ---------------------------------------------------------------------- */
void criaEstadoInicial (quint_t *q)
{
  insereNaFuncaoDelta(&q->d, q->k, 'E', q->s0);
  q->s0 = q->k;

  return;
}

/* ---------------------------------------------------------------------- */
void criaEstadoFinal (quint_t *q)
{
  ef_t *cont = q->f;
  ef_t *b = NULL;

  insereNosEstadosFinais(&q->f, (q->k+1));

  while(cont->prox != NULL)
    cont = cont->prox;

  insereNaFuncaoDelta(&q->d, q->f->f, 'E', cont->f);
  b = busca(q->f, q->f->f);
  if(b == NULL) /* para evitar segmentation fault */
    return;
  removerFinais(&q->f, b);

  return;
}

/* ---------------------------------------------------------------------- */
void encurtaEstadoE (quint_t *q, int e)
{
  delta_t *qfinal = NULL;
  delta_t *qinicial = NULL;
  delta_t *cont = q->d;
  delta_t *qicont = NULL;
  delta_t *qfcont = NULL;
  delta_t *busc = NULL;
  char vet[SBUFF];
  int i;
 /* char kleene[SBUFF]; */

  /* cria duas funcoes delta: */
  /*uma com as transicoes que tem o estado a se apagar como estado final */
  /*e uma com as transicoes que tem o estado a se apagar como estado inicial */
  while(cont != NULL)
  {
    if(cont->ef == e)
      insereComVetorNaFuncaoDelta(&qinicial, cont->ei, cont->s, cont->ef);
    if(cont->ei == e)
      insereComVetorNaFuncaoDelta(&qfinal, cont->ei, cont->s, cont->ef);
    cont = cont->prox;
  }
  if(qinicial->prox != NULL)
  {
    printf("\noutro inicial: ei = %d\n", qinicial->prox->ei);
    encurtaEstadoE(q, qinicial->prox->ei);
    return;
  }

  qicont = qinicial;
  qfcont = qfinal;

  printf("\nDEBUG\n\n");
  printf("qicont\n");
  imprimeFuncaoDelta(qicont);
  printf("\nqfcont\n");
  imprimeFuncaoDelta(qfcont);

  while(qicont != NULL)
  {
    while(qfcont != NULL)
    {
      for(i = 0; i < SBUFF; i++)
        vet[i] = 0;
      /*if(qfcont->ei == qfcont->ef)
      {
        montaKleene(qfcont->s, kleene);
        busc = buscaTransicaoCabecaKleene(qfinal, qfcont->ei);
        montaTransicaoKleene(qfcont, kleene, vet);
        printf("\nTransicao criada: %s\n", vet);
        novoElementoDelta(&q->d, qicont->ei, vet, qfcont->ef);
        printf("Vou remover o ei = %d e o ef = %d, cujas transicoes sao si = %s e sf = %s\n", qicont->ei, qfcont->ef, qicont->s, qfcont->s);
      } */
      /*else
      { */
      montaTransicao(qicont->s, qfcont->s, vet);
      printf("\ntranseicao criada: %s\n", vet);
      novoElementoDelta(&q->d, qicont->ei, vet, qfcont->ef);
      printf("Vou remover o ei = %d e o ef = %d, cujas transicoes sao si = %s e sf = %s\n", qicont->ei, qfcont->ef, qicont->s, qfcont->s);
      /*} */
      qfcont = qfcont->prox;
    }
    qfcont = qfinal;
    while(qfcont != NULL)
    {
      busc = buscaDelta(q->d, qfcont->ei, qfcont->ef, qfcont->s);
      if(busc != NULL)
        removerDelta(&q->d, busc);
      qfcont = qfcont->prox;
    }
    
    qicont = qicont->prox;
  }
  qicont = qinicial;
  while(qicont != NULL)
  {
    busc = buscaDelta(q->d, qicont->ei, qicont->ef, qicont->s);
    if(busc != NULL)
      removerDelta(&q->d, busc);
    qicont = qicont->prox;
  }

  
  return;
}

void encurtaEstadoKleene (quint_t *q, int e)
{
  delta_t *cont = q->d;
  delta_t *head = NULL;
  delta_t *aux = NULL;
  delta_t *busc = NULL;
  char kleene[SBUFF];
  char vet[SBUFF];

  while(cont != NULL)
  {
    if(cont->ei == e && cont->ef == e)
      insereComVetorNaFuncaoDelta(&head, cont->ei, cont->s, cont->ef);
    cont = cont->prox;
  }
  aux = head;
  cont = q->d;

  while(aux != NULL)
  {
    while(cont != NULL)
    {
      if(cont->ei == e && cont->ef != e)
      {
        montaKleene(aux->s, kleene);
        printf("\nkleene: %s\n", kleene);
        montaTransicao(kleene, cont->s, vet);
        printf("\nTransicao: %s\n", vet);
        /* se tiver erro, ta aq */
        busc = buscaDelta(q->d, aux->ei, aux->ef, aux->s);
        if(busc != NULL)
          removerDelta(&q->d, busc);
        busc = buscaDelta(q->d, cont->ei, cont->ef, cont->s);
        if(busc != NULL)
          removerDelta(&q->d, busc);
        //insereComVetorNaFuncaoDelta(&q->d, cont->ei, vet, cont->ef);
        insereComVetorNaFuncaoDelta(&q->d, e, vet, cont->ef);
      }
      cont = cont->prox;
    }
    cont = q->d;
    aux = aux->prox;
  }
/*  aux = head;
  cont = q->d;

  while(aux != NULL)
  {
    while(cont != NULL)
    {
      if(!(cont->ei == e && cont->ef == e))
      {
        montaKleene(aux->s, kleene);
        printf("\nkleene: %s\n", kleene);
        montaTransicao(kleene, cont->s, vet);
        printf("\nTransicao: %s\n", vet);
        insereComVetorNaFuncaoDelta(&q->d, cont->ei, vet, cont->ef);
        busc = buscaDelta(q->d, cont->ei, cont->ef, cont->s);
        if(busc != NULL)
          removerDelta(&q->d, busc); 
      }
      cont = cont->prox;
    }
    aux = aux->prox;
  }
  
  printf("\nTransicoes do estado %d que contem estrela de kleene:\n", e);
  imprimeFuncaoDelta(head); */
  return;
}

void encurtaEstadoOU (quint_t *q, int e)
{
  return;
}

void montaKleene(char kleene[SBUFF], char vet[SBUFF])
{
  char vetor[SBUFF];
  int i = 1;
  int j = 0;

  vetor[0] = '(';
  while(kleene[j] != '\0')
  {
    vetor[i+j] = kleene[j];
    j++;
  }
  vetor[i+j] = ')';
  vetor[i+j+1] = '*';

  strcpy(vet, vetor);

  return;
}

void montaTransicaoKleene(delta_t *d, char kleene[SBUFF], char vet[SBUFF])
{
  char vetor[SBUFF];

  montaTransicao(d->s, kleene, vetor);
  strcpy(vet, vetor);

  return;
}
/* ---------------------------------------------------------------------- */
delta_t *buscaTransicaoCabecaKleene (delta_t *head, int e)
{
  delta_t *cont = head;

  while(cont != NULL)
  {
    if(cont->ef == e && cont->ei != e)
      return cont;
    cont = cont->prox;
  }

  return NULL;
}

delta_t *buscaDelta (delta_t *head, int ei, int ef, char vet[SBUFF])
{
  delta_t *cont = head;

  while(cont != NULL)
  {
    if(cont->ei == ei && cont->ef == ef && !strcmp(cont->s, vet))
      return cont;
    cont = cont->prox;
  }

  return NULL;
}

/* ---------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */
ef_t *busca (ef_t *head, int f)
{
  ef_t *cont = head;

  while(cont != NULL)
  {
    if(cont->f == f)
      return cont;
    cont = cont->prox;
  }

  return NULL;
}

/* ---------------------------------------------------------------------- */
/* essa funcao esta com problema */
void montaTransicao (char sei[SBUFF], char sef[SBUFF], char vet[SBUFF])
{
    char vetor[SBUFF]="\0";
    
    /*do
    {
        vetor[i] = sei[i];
        i++;
    }while(i<strlen(sei));
   // vetor[i-1]="\0";
    do
    {
        vetor[i+j] = sef[j];
        j++;
    }while(j<strlen(sef));*/
      strcat(vetor, sei);
      strcat(vetor, sef);

      strcpy(vet, vetor);
     
    printf("vet = %s",vet);
    return;
}

/* ---------------------------------------------------------------------- */
void removerDelta(delta_t **head, delta_t *r) /* funcao de exclusao */
{
  delta_t *cont = *head;
  delta_t *plant = NULL;

  if(r == NULL)
    return;
  while(cont != NULL && cont != r)
  {
    plant = cont;
    cont = cont->prox;
  }
  if(cont == NULL) /* nao achou  */
    return;
  if(plant != NULL) /* tem anterior */
    plant->prox = cont->prox;
  else /* eliminando a cabeca */
    *head = cont->prox;
  
  free(cont);

  return;
}

/* ---------------------------------------------------------------------- */
void removerFinais(ef_t **head, ef_t *r) /* funcao de exclusao */
{
  ef_t *cont = *head;
  ef_t *plant = NULL;

  if(r == NULL)
    return;
  while(cont != NULL && cont != r)
  {
    plant = cont;
    cont = cont->prox;
  }
  if(cont == NULL) /* nao achou lista vazia */
    return;
  if(plant != NULL) /* tem anterior */
    plant->prox = cont->prox;
  else /* eliminando a cabeca */
    *head = cont->prox;
  
  free(cont);

  return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void help(void)
{
  IFDEBUG("help()");
  printf("%s v.%s - %s\n", "ex12", VERSION, "Convert AFD into Exp Reg");
  printf("\nUsage: %s [-h|-v]\n", "ex12");
  printf("\nOptions:\n");
  printf("\t-h,  --help\n\t\tShow this help.\n");
  printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
  printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
  /* add more options here */
  printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
  printf("\nTodo:\n\tLong options not implemented yet.\n");
  printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
  exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
  IFDEBUG("copyr()");
  printf("%s - Version %s\n", "ex12", VERSION);
  printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
  if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
  exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void ex12_init(void)
{
  IFDEBUG("ex12_init()");
  /* initialization */
  return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */
int funcexample(int i, int *o, int *z)
{
  IFDEBUG("funcexample()");
  i += *z;
  *o = (*z)++;
  return i-4;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=2 sw=2 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20150619.231433      */

