#include <stdio.h>

int SAT_convert(char *origin, char *destiny)
{
    FILE *loader = fopen(origin,"r");
    FILE *writer = fopen(destiny,"w");
    int num_var, num_clause;
    int clause;
    int var;
    int i, j, k;

    int cl[32];
    char buffer[128];

    if(loader==NULL || writer==NULL)
    {
        fprintf(stderr, "Erro!\n");
        return -1;
    }

    while(fgets(buffer,128,loader))
        if(buffer[0] != 'c')
            break;

    sscanf(buffer,"p cnf %d %d", &num_var, &num_clause);
    fprintf(writer,"%d %d\n", num_var, num_clause);

    for(i=0;i<num_clause;i++)
    {
        fprintf(writer,"\n");

        j = 0;
        while(1)
        {
            fscanf(loader,"%d",&var);
            if(var == 0)
                break;

            cl[j] = var;
            j++;

        }

        fprintf(writer, "%d 0", j);
        for(k=0;k<j;k++)
            fprintf(writer," %d", cl[k]);
    }

    fclose(loader);
    fclose(writer);
    return 0;
}

int main()
{
    SAT_convert("uuf50-01.cnf","uuf50-01.txt");
    printf("Done!");

    return 0;
}
