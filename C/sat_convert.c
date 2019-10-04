#include <stdio.h>

int SAT_convert(char *origin, char *destiny)
{
    FILE *loader = fopen(origin,"r");
    FILE *writer = fopen(destiny,"w");
    int num_var, num_clause;
    int var_clause;
    int clause;
    int var;
    int i, j, k;

    if(loader==NULL || writer==NULL)
    {
        fprintf(stderr, "Erro!\n");
        return -1;
    }

    fscanf(loader,"%d %d", &num_var, &num_clause);
    fprintf(writer,"p cnf %d %d\n", num_var, num_clause);

    for(i=0;i<num_clause;i++)
    {
        fscanf(loader,"%d %*d",&var_clause);

        for(j=0;j<var_clause;j++)
        {
            fscanf(loader,"%d",&var);
            fprintf(writer,"%d ",var);
        }
        fprintf(writer, "0\n");
    }

    fclose(loader);
    fclose(writer);
    return 0;
}

int main()
{
    SAT_convert("novo1.txt","Test4.txt");

    return 0;
}
