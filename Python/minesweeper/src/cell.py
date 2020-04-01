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
        """ Returns whether the cell has a mine """
        return self.__has_mine

    def digged(self):
        """ REturns whether the cell has been dug """
        return self.__state == CellState.UNCOVERED

    def flagged(self):
        """ Returns whether the Cell is Flagged """
        return self.__state == CellState.FLAGGED

    def dig(self):
        """ Sets the Cell State as Uncovered """
        if self.__state != CellState.COVERED:
            return False
        self.__state = CellState.UNCOVERED
        return True

    def switch_flag(self):
        """ If Cell has not been dug, switch between flagged and unflagged state"""
        if self.__state == CellState.UNCOVERED:
            return
        if self.__state == CellState.COVERED:
            self.__state = CellState.FLAGGED
        elif self.__state == CellState.FLAGGED:
            self.__state = CellState.COVERED

    def winnable(self):
        """ Returns if the cell state is in winnable """
        return self.has_mine() ^ self.digged()

    def __eq__(self, other):
        return self.has_mine() == other.has_mine() and \
               self.digged() == other.digged() and \
               self.flagged() == other.flagged()

    def __repr__(self):
        return f"Cell(Mine: {repr(self.has_mine())}, State: {repr(self.__state)})"
