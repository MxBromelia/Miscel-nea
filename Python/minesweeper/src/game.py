from enum import Enum
from src.cell import Cell

class Board:
    def __init__(self, rows: int, cols: int, placement: list):
        self.__rows = rows
        self.__cols = cols
        self.__table = self.__generate_table(rows, cols, placement)

    @property
    def rows(self):
        return self.__rows

    @property
    def cols(self):
        return self.__cols

    @property
    def cells(self):
        return self.rows * self.cols

    def at(self, row: int, col: int):
        return self.__table[row][col]

    def around(self, row: int, col: int):
        ret = []
        if row-1 >= 0 and col-1 >= 0:
            ret.append(self.at(row-1, col-1))
        if row-1 >= 0 and col >= 0:
            ret.append(self.at(row-1, col))
        if row-1 >= 0 and col+1 < self.cols:
            ret.append(self.at(row-1, col+1))
        if row >= 0 and col-1 >= 0:
            ret.append(self.at(row, col-1))
        if row >= 0 and col+1 < self.cols:
            ret.append(self.at(row, col+1))
        if row+1 < self.rows and col-1 >= 0:
            ret.append(self.at(row+1, col-1))
        if row+1 < self.rows and col >= 0:
            ret.append(self.at(row+1, col))
        if row+1 < self.rows and col+1 < self.cols:
            ret.append(self.at(row+1, col+1))
        return ret
        

    def __generate_table(self, rows, cols, placement):
        from src.exceptions import ValidationError
        if rows*cols != len(placement):
            raise ValidationError
        if len([x for x in placement if not isinstance(x, bool)]) != 0:
            raise ValidationError
        
        table = [[None for _ in range(cols)] for _ in range(rows)]
        index = lambda row, col: row*cols + col

        for row in range(rows):
            for col in range(cols):
                has_mine = placement[index(row, col)]
                table[row][col] = Cell(has_mine)

        return table
