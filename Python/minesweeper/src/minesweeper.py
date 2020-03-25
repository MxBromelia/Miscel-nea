from random import randint
from enum import Enum


class HoleContent(Enum):
    NOTHING = 0
    MINE = -1
    ONE_AROUND = 1

class Cell:
    def __init__(self, fill=HoleContent.NOTHING):
        self.__fill = fill
        # self.__dug = False
        self.dug = False

    # def dig(self):
    #     if self.__dug:
    #         return False

    #     self.__dug = True
    #     return True

    # @property
    # def dug(self):
    #     return self.__dug

    @property
    def fill(self):
        return self.__fill

    def __eq__(self, other):
        return self.fill == other.fill and self.dug == other.dug

class FieldRow(list):
    def __setitem__(self, idx, item):
        if not isinstance(item, Cell):
            raise TypeError
        super().__setitem__(idx, item)

class Field:
    def __init__(self, rows, cols, mines):
        self.__rows = rows
        self.__cols = cols
        self.__cells = self.rows * self.cols
        self.__mines = mines
        self.__table = [FieldRow([Cell() for _ in range(cols)]) for _ in range(rows)]
        self.__dug_cells = 0
        self.__dug = [False for _ in range(self.cells)]

    def all_dug(self):
        return self.__dug_cells == self.cells

    def index(self, row, col):
        return self.cols*row + col

    def dig(self, row, col):
        if self.dug[self.index(row, col)]:
            return False

        self.__dug_cells += 1
        self.dug[self.index(row, col)] = True
        return True

    @property
    def rows(self):
        return self.__rows

    @property
    def cols(self):
        return self.__cols

    @property
    def cells(self):
        return self.__cells

    @property
    def mines(self):
        return self.__mines

    @property
    def dug(self):
        return self.__dug

    def __getitem__(self, idx):
        return self.__table[idx]

    def __setitem__(self, idx, item):
        self.__table[idx] = item

class GameStatus(Enum):
    DEFEAT = 0
    VICTORY = 1
    UNFINISHED = 2

class Minesweeper:
    """ Campo Minado """

    def __init__(self, rows, cols, mines, mine_generator=None):
        self.__mine_generator = mine_generator or self.__generate_mines
        self.mine_field = self.__generate_mine_field__(rows, cols, mines)
        self.__status = GameStatus.UNFINISHED

    def dig(self, row, col):
        self.mine_field.dig(row, col)
        cell = self.mine_field[row][col].fill

        if cell == HoleContent.MINE:
            self.__status = GameStatus.DEFEAT
            return cell

        if self.mine_field.all_dug():
            self.__status = GameStatus.VICTORY

        return cell

    @property
    def status(self):
        return self.__status

    def __generate_mines(self, cells, mines):
        return [randint(0, cells-1) for _ in range(mines)]

    def __generate_mine_field__(self, rows, cols, mines):
        mine_field = Field(rows, cols, mines)
        for index in self.__mine_generator(mine_field.cells, mines):
            row = index // mine_field.cols
            col = index % mine_field.cols
            mine_field[row][col] = Cell(HoleContent.MINE)

        for row in range(mine_field.rows):
            for col in range(mine_field.cols-1):
                if mine_field[row][col+1].fill == HoleContent.MINE:
                    mine_field[row][col].fill = HoleContent.ONE_AROUND

        return mine_field
