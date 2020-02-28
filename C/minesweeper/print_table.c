#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "print_table.h"
#include "minesweeper.h"


char display_cell(const struct table *table, int pos) {
    if(table->field[pos] == '0') {
        return ' ';
    } else {
        return table->field[pos];
    }
}

char print_cell(const struct table *table, int pos) {
    if (!table->digged[pos]) return '-';

    return display_cell(table, pos);
}

void print_table_victory(const struct table *table) {
    for(int i = 0; i < table->rows; i++) {
        printf("%d|", i);
        for(int j = 0; j < table->cols; j++) {
            int cell = table->rows*i + j;
            printf("%c|", display_cell(table, cell));
        }
        printf("\n");
    }
    printf(" |");
    for(int i = 0; i < table->cols; i++) {
        printf("%d|", i);
    }
    printf("\n");
}

void print_table_defeat(const struct table *table) {
    print_table_victory(table);
}

void print_table_unfinished(const struct table *table) {
    for(int i = 0; i < table->rows; i++) {
        printf("%d|", i);
        for(int j = 0; j < table->cols; j++) {
            int cell = table->rows*i + j;
            printf("%c|", print_cell(table, cell));
        }
        printf("\n");
    }
    printf(" |");
    for(int i = 0; i < table->cols; i++) {
        printf("%d|", i);
    }
    printf("\n");
}

void print_table(const struct table *table) {
    switch(table->status) {
    case MS_DEFEAT:
        print_table_defeat(table);
        break;
    case MS_VICTORY:
        print_table_victory(table);
        break;
    case MS_UNFINISHED:
        print_table_unfinished(table);
        break;
    }
}