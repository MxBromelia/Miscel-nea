#include "table.h"

int cell(struct table table, int row, int col) {
    return table.rows*row+col;
}

int cells(struct table table) {
    return table.rows*table.cols;
}

int cell_up(struct table table, int pos) {
    int check = pos - table.cols;
    return check >= 0 ? check : NO_POSITION;
}

int cell_down(struct table table, int pos) {
    int check = pos + table.cols;
    return check < cells(table) ? check : NO_POSITION;
}

int cell_left(struct table table, int pos) {
    int check = pos - 1;
    return check >= 0 && check % table.cols >= 0 ? check : NO_POSITION;
}

int cell_right(struct table table, int pos) {
    int check = pos + 1;
    return check % table.cols > pos % table.cols ? check : NO_POSITION;
}

int cell_upper_left(struct table table, int pos) {
    int check = cell_up(table, pos);
    return check != NO_POSITION ? cell_left(table, check) : NO_POSITION;
}

int cell_upper_right(struct table table, int pos) {
    int check = cell_up(table, pos);
    return check != NO_POSITION ? cell_right(table, check) : NO_POSITION;
}

int cell_lower_left(struct table table, int pos) {
    int check = cell_down(table, pos);
    return check != NO_POSITION ? cell_left(table, check) : NO_POSITION;
}

int cell_lower_right(struct table table, int pos) {
    int check = cell_down(table, pos);
    return check != NO_POSITION ? cell_right(table, check) : NO_POSITION;
}