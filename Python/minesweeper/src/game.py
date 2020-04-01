from src.cell import Cell
from src.exceptions import ValidationError


class Board:
    def __init__(self, rows: int, cols: int, placement: list):
        self.__rows = rows
        self.__cols = cols
        self.__table = self.__generate_table(rows, cols, placement)

    @property
    def rows(self):
        """ Return the number of rows in the board """
        return self.__rows

    @property
    def cols(self):
        """ Return the number of columns in the board """
        return self.__cols

    @property
    def cells(self):
        """ Returns the number of cells in the board """
        return self.rows * self.cols

    def index(self, row, col):
        """ Returns the cell index equivalent to the coordinates"""
        return row*self.cols + col

    def at(self, row: int, col: int): # pylint: disable=invalid-name
        """ Returns the cell in the given coordinates """
        return self.__table[row][col]

    def at_index(self, index: int):
        """ Returns the cell in the given index """
        return self.at(index // self.cols, index % self.cols)

    def around(self, row: int, col: int):
        """ Returns the cell around the cell in the given coordinates """
        valid_cell = lambda row, col: row in range(self.rows) and col in range(self.cols)
        ret = []
        for i in range(-1, 2):
            for j in range(-1, 2):
                if (i != 0 or j != 0) and valid_cell(row+i, col+j):
                    ret.append(self.at(row+i, col+j))
        return ret

    def __generate_table(self, rows, cols, placement):
        if rows*cols != len(placement):
            raise ValidationError
        if len([x for x in placement if not isinstance(x, bool)]) != 0:
            raise ValidationError

        table = [[None for _ in range(cols)] for _ in range(rows)]

        for row in range(rows):
            for col in range(cols):
                has_mine = placement[self.index(row, col)]
                table[row][col] = Cell(has_mine)

        return table
