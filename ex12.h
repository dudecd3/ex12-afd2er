
/***************************************************************************
 *   ex12.h                                 Version 20160520.000202      *
 *                                                                         *
 *   Library for ex12, a program that convert AFD into Exp Reg           *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License                *
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
/* definitions */

#ifndef VERSION
#define VERSION "20160520.000202" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 20 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb=0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

typedef struct st_ef
{
    int f;
    struct st_ef *prox;
} ef_t;

typedef struct s_delta
{
    int ei;
    char s[SBUFF];
    int ef;
    struct s_delta *prox;
} delta_t;

typedef struct s_quintupla
{
    int k;
    char a;
    int s0;
    ef_t *f;
    delta_t *d;
} quint_t;

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void ex12_init(void); /* global initialization function */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
void pegaEntrada (quint_t *q, FILE *arq);
int finalDoVetor (char s[SBUFF]);
void insereNaFuncaoDelta (delta_t **d, int ei, char c, int ef);
void insereNosEstadosFinais (ef_t **p, int f);
void imprimeQuintupla (quint_t q);
void imprimeListaDeEstadosFinais (quint_t q);

void imprimeFuncaoDelta (quint_t q);
void criaEstadoInicial (quint_t *q);
void apagaEstado (quint_t *q, int e);
delta_t *busca_ei (delta_t *head, int ei);
delta_t *busca_ef (delta_t *head, int ef);
ef_t *busca (ef_t *head, int f);
void removerDelta(delta_t **head, delta_t *r);
void removerFinais(ef_t **head, ef_t *r);
void novoElementoDelta (delta_t **d, int ei, char vet[SBUFF], int ef);

