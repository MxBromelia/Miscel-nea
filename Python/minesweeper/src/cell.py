from enum import Enum

class CellState(Enum):
    COVERED = 0
    UNCOVERED = 1
    FLAGGED = -1

class Cell:
    def __init__(self, has_mine=False):
        self.__has_mine = has_mine
        self.__state = CellState.COVERED

    def has_mine(self):
        return self.__has_mine

    def digged(self):
        return self.__state == CellState.UNCOVERED

    def flagged(self):
        return self.__state == CellState.FLAGGED

    def dig(self):
        if self.__state != CellState.COVERED:
            return False
        self.__state = CellState.UNCOVERED
        return True

    def switch_flag(self):
        if self.__state == CellState.UNCOVERED:
            return
        elif self.__state == CellState.COVERED:
            self.__state = CellState.FLAGGED
        elif self.__state == CellState.FLAGGED:
            self.__state = CellState.COVERED

    def __eq__(self, other):
        return self.has_mine() == other.has_mine() and \
               self.digged() == other.digged() and \
               self.flagged() == other.flagged()