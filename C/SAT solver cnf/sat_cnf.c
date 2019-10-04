#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SAT_ASSIGN 1
#define SAT_UNASSIGN 0

#define SIGNAL(X) (X > 0 ? 1 : (X < 0 ? -1 : 0))

#define SAT_FAIL 0
#define SAT_SUCCESS 1

#define MAX_VAR 128
#define MAX_CLAUSE 1024

struct vars
{
    int len;
    int assign;

    int clause[MAX_CLAUSE];
    int position[MAX_CLAUSE];
};

struct clause
{
    int alpha, beta;
    int var[MAX_VAR];
};

struct SAT
{
    int num_var;
    int num_clause;

    struct vars vars[MAX_VAR];
    struct clause clause[MAX_CLAUSE];
};

int load_files(char path[], struct SAT* sat)
{
    FILE *loader = fopen(path,"r");
    int num_var, num_clause;
    int var;
    int i, j;

    char buffer[128];

    if(loader==NULL)
        fprintf(stderr, "Erro!\n");

    while(fgets(buffer,128,loader))
        if(buffer[0] != 'c')
            break;

    sscanf(buffer,"p cnf %d %d", &num_var, &num_clause);
    sat->num_var = num_var;
    sat->num_clause = num_clause;

    for(i=0;i<num_var;i++)
    {
        sat->vars[i].len = 0;
        sat->vars[i].assign = SAT_UNASSIGN;
    }


    for(i=0;i<num_clause;i++)
    {
        for( j = 0;j < sat->num_var; j++)
        {
            fscanf(loader,"%d",&var);
            if(var == 0) break;

            sat->clause[i].var[j] = var;

            var = abs(var) - 1;

            sat->vars[var].clause[sat->vars[var].len] = i;
            sat->vars[var].position[sat->vars[var].len] = j;
            sat->vars[var].len++;
        }

        sat->clause[i].alpha = 0;
        sat->clause[i].beta = j;
    }

    fclose(loader);
    return 0;
}

void SAT_varcheck(struct SAT *sat, int var, int literal)
{
    int j;
    int current_clause;
    int current_position;

    for(j=0;j<sat->vars[var].len;j++)
        {
            current_clause = sat->vars[var].clause[j];
            current_position = sat->vars[var].position[j];
            if(sat->clause[current_clause].var[current_position]*literal > 0)
                sat->clause[current_clause].alpha++;
        }
}

void SAT_varuncheck(struct SAT *sat, int var, int literal)
{
    int j;
    int current_clause;
    int current_position;

    for(j=0;j<sat->vars[var].len;j++)
        {
            current_clause = sat->vars[var].clause[j];
            current_position = sat->vars[var].position[j];
            if(sat->clause[current_clause].var[current_position]*literal > 0)
                sat->clause[current_clause].alpha--;
        }
}

int SAT_solve(struct SAT *sat)
{
    int clause_it, i;
    int var, literal;

    int result = -1;

    //Checa se todas as cláusulas estão todas resolvidas
    for(clause_it=0;clause_it < sat->num_clause; clause_it++)
        if(sat->clause[clause_it].alpha == 0)
            break;

    //Se sim, retorne VERDADEIRO
    if(clause_it == sat->num_clause)
        return SAT_SUCCESS;

    //Se há uma cláusula não resolvida, marque a primeira cláusula sem valor definido
    for(i=0; i< sat->clause[clause_it].beta; i++)
    {
        var = abs(sat->clause[clause_it].var[i]) - 1;
        literal = SIGNAL(sat->clause[clause_it].var[i]);

        if(sat->vars[var].assign == SAT_UNASSIGN)
        {
            //Se há ao menos uma variável sem valor atribuído na cláusula, defina o literal como VERDADEIRO
            //i.e VERDADEIRO se Literal é VERDADEIRO, FALSO caso contrário
            sat->vars[var].assign = SAT_ASSIGN;
            SAT_varcheck(sat,var,literal);

            //Faça teste de Satisfatoriedade
            result = SAT_solve(sat);
            if(result == SAT_SUCCESS)
                return SAT_SUCCESS;

            //Se a atribuição causou uma cláusula FALSO,faça backtracking e defina o literal como FALSO
            SAT_varuncheck(sat,var,literal);
            SAT_varcheck(sat,var,-literal);

            result = SAT_solve(sat);
            if(result == SAT_SUCCESS)
                return SAT_SUCCESS;

            sat->vars[var].assign = SAT_UNASSIGN;
        }

    }
    //sat->vars[var].assign = SAT_ASSIGN;

    return SAT_FAIL;
}

int main()
{
    clock_t time;
    struct SAT sat;
    int result, i = 0;

    const char routine[] = "test_routine.txt";
    char path[64];

    FILE* loader = fopen(routine,"r");
    if(loader == NULL) fprintf(stderr,"Arquivo não %s encontrado\n", routine);

    while(fscanf(loader,"%s",path) != EOF)
    {
        time = clock();
        printf("%s\n",path);
        load_files(path,&sat);
        result = SAT_solve(&sat);
        time = clock() - time;
        printf("Teste %d: %s, %lf seconds.\n",i++,(result != SAT_FAIL ? "SAT" : "unSAT"), (double)((double)time/(double)CLOCKS_PER_SEC));
    }

    return 0;
}

