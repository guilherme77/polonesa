/***************************************************************************
 *   ex3.c                                    Version 20180329.201538      *
 *                                                                         *
 *   Calculadora de notãcao polonesa reversa                               *
 *   Copyright (C) 2018         by Guilherme Barros                        *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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
 *   Guilherme da S. Barros                                                *
 *   Email: guilhermesilva986@gmail.com                                    *
 *   Webpage: https://github.com/guilherme77                               *
 *   Phone: +55 (81) 98429-6876                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Miscellaneous functions (rand, malloc, srand)*/
#include <string.h>     /* Strings functions definitions */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20180329.201538" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */
#define MAX 256

/* Typdefs */

typdef struct st_pilha
{
    int g;
    struct st_pilha *prox;
}pilha;

/* ---------------------------------------------------------------------- */
/* prototypes */
void push(pilha **cabeca, int x);
int pop(pilha **cabeca);
void operation(pilha **cabeca, char op);
void print(pilha **cabeca);
void clear(pilha **cabeca);
void help(void); /* print some help */
void copyr(void); /* print version and copyright information */

/* ---------------------------------------------------------------------- */
int main(void)
{
    pilha *p1=NULL;
    char str[MAX];
    char *cha;
    
    printf("\nOperadores Soma='+', subtracao='-', divisao='/', multiplicacao='*'\n");
    Printf("Insira a equacao na forma polonesa inversa:\n");
    fgets(str, MAX, stdin);
    cha = strtok(str, " ");

    while(pch != NULL)
    {
        if(*cha=='-' || *cha=='+' || *cha=='/' || *cha=='*')
            operation(&p1, *cha);
        else
            push(&pl, atoi(cha));

        cha=strtok(NULL, " ");
    }

}

void push(pilha **cabeca, int x)
{
    pilha *pl;

    pl= malloc(sizeof(pilha));
    pl->c=x;
    pl->prox=*cabeca;
    *cabeca=pl;
}

int pop(pilha **cabeca)
{
    pilha *pl = *cabeca;
    int x;

    x=pl->c;
    *cabeca=pl->prox;
    
    free(pl);
    return x;
}

void operation(pilha **cabeca, char op)
{}
void print(pilha **cabeca)
{}
void clear(pilha **cabeca)
{}

/* add more functions here */

/* ---------------------------------------------------------------------- */
/* Prints help information 
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex2", "Rede de petri");
    printf("\nUsage: %s\n\n", "ex2");
    printf("This program does...\n");
    /* add more stuff here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Guilherme Barros", "guilhermesilva986@gmail.com");
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information 
 *  usually called by opt -V
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex2", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2018, "Guilherme Barros", "guilhermesilva986@gmail.come");
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

