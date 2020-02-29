#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include "minesweeper.h"
#include "table.h"
#include "print_table.h"

int main(void) {
    struct table table;
    int row, col;

    setup(&table, 8, 8);
    print_table(&table);
    printf("linha: ");
    scanf("%d", &row);
    printf("Coluna: ");
    scanf("%d", &col);

    new_game(&table, 10, row, col);
    dig(&table, row, col);

    while(table.status == MS_UNFINISHED) {
        print_table(&table);
        printf("linha: ");
        scanf("%d", &row);
        printf("Coluna: ");
        scanf("%d", &col);

        dig(&table, row, col);
        printf("------------------------------");
        printf("\n\n\n");
    }
    print_table(&table);

    if(table.status == MS_VICTORY)
        printf("Você Ganhou!\n");
    else if(table.status == MS_DEFEAT)
        printf("Você Perdeu!");

    return 0;
}