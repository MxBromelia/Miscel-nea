from random import randint

class Minesweeper:
    NOTHING = 0
    MINE = -1
    ONE_AROUND = 1

    DEFEAT = 0
    VICTORY = 1
    UNFINISHED = 2

    def __init__(self, rows, cols, mines, mine_generator=None):
        self.rows = rows
        self.cols = cols
        self.mines = mines
        self.__cells = self.rows * self.cols
        self.dug_cells = 0
        self.dug = [False for _ in range(self.cells)]
        self.__status = self.UNFINISHED
        self.__mine_generator = mine_generator or self.__generate_mines
        self.mine_field = self.__generate_mine_field__()

    def dig(self, row, col):
        cell_index = self.cols*row + col
        cell = self.mine_field[cell_index]

        if not self.dug[cell_index]:
            self.dug_cells += 1
            self.dug[cell_index] = True

        if cell == self.MINE:
            self.__status = self.DEFEAT
            return cell

        if self.cells == self.dug_cells:
            self.__status = self.VICTORY

        return cell

    @property
    def status(self):
        return self.__status

    @property
    def cells(self):
        return self.rows * self.cols

    def __generate_mines(self, cells, mines):
        return [randint(0, cells-1) for _ in range(mines)]

    def __generate_mine_field__(self):
        mine_field = [self.NOTHING for _ in range(self.cells)]
        for index in self.__mine_generator(self.cells, self.mines):
            mine_field[index] = self.MINE

        for index in range(self.cells-1):
            if mine_field[index+1] == self.MINE:
                mine_field[index] = self.ONE_AROUND

        return mine_field
