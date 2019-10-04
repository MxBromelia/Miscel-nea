#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int var_clause;
    int var;
    int i, j;

    if(loader==NULL)
        fprintf(stderr, "Erro!\n");

    fscanf(loader,"%d %d", &num_var, &num_clause);
    sat->num_var = num_var;
    sat->num_clause = num_clause;

    for(i=0;i<num_var;i++)
    {
        sat->vars[i].len = 0;
        sat->vars[i].assign = SAT_UNASSIGN;
    }

    for(i=0;i<num_clause;i++)
    {
        fscanf(loader,"%d %*d",&var_clause);
        sat->clause[i].alpha = 0;
        sat->clause[i].beta = var_clause;

        for(j=0;j<var_clause;j++)
        {
            fscanf(loader,"%d",&var);

            sat->clause[i].var[j] = var;

            var = abs(var) - 1;

            sat->vars[var].clause[sat->vars[var].len] = i;
            sat->vars[var].position[sat->vars[var].len] = j;
            sat->vars[var].len++;
        }
    }
    fclose(loader);
    return 0;
}

int SAT_solve(struct SAT *sat)
{
    int clause_it, j;
    int var, literal;

    int current_clause = 0;
    int current_position = 0;

    int result;

    //Checa se todas as cláusulas estão todas resolvidas
    for(clause_it=0;clause_it < sat->num_clause; clause_it++)
        if(sat->clause[clause_it].alpha == 0)
            break;

    //Se sim, retorne VERDADEIRO
    if(clause_it == sat->num_clause)
        return SAT_SUCCESS;

    //Se há uma cláusula não resolvida, marque a primeira cláusula sem valor definido
    for(j=0; j< sat->clause[clause_it].beta; j++)
    {
        var = abs(sat->clause[clause_it].var[j]) - 1;
        literal = SIGNAL(sat->clause[clause_it].var[j]);

        if(sat->vars[var].assign == SAT_UNASSIGN)
            break;
        else
            printf("Clause %d: Variable %d already assigned.\n",clause_it,var);
    }

    //Se há uma clausula não resolvida em que todas as variáveis possuem valor, retorne FALSO.
    //Falha resulta em backtracking
    if(j==sat->clause[clause_it].beta)
    {
        printf("Clause %d set as False\n",clause_it);
        return SAT_FAIL;
    }

    sat->vars[var].assign = SAT_ASSIGN;

    //Se há ao menos uma variável sem valor atribuído na cláusula, defina o literal como verdadeiro
    //i.e Verdadeiro se Literal é Verdadeiro, False caso contrário
    for(j=0;j<sat->vars[var].len;j++)
    {
        current_clause = sat->vars[var].clause[j];
        current_position = sat->vars[var].position[j];
        if(sat->clause[current_clause].var[current_position]*literal > 0)
            sat->clause[current_clause].alpha++;
    }

    printf("Clause %d: Variable %d is now assigned.\n", clause_it, var);

    //Faça teste de Satisfatoriedade
    result = SAT_solve(sat);
    if(result == SAT_SUCCESS)
        return SAT_SUCCESS;

    for(j=0;j<sat->vars[var].len;j++)
    {
        current_clause = sat->vars[var].clause[j];
        current_position = sat->vars[var].position[j];

        if(sat->clause[current_clause].var[current_position]*literal > 0)
            sat->clause[current_clause].alpha--;
        else if(sat->clause[current_clause].var[current_position]*literal < 0)
            sat->clause[current_clause].alpha++;
    }

    return SAT_solve(sat);
}

int main()
{
    struct SAT sat;
    int result;

    load_files("Teste1.txt",&sat);
    result = SAT_solve(&sat);
    printf("%s\n",(result != SAT_FAIL ? "SAT" : "unSAT"));

    return 0;
}
