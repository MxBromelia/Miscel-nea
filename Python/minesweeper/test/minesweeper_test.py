from unittest import TestCase
from src.minesweeper import Minesweeper

class TestMinesweeper(TestCase):

    def test_digAHoleIncreasesDugCells(self):
        mine = Minesweeper(1, 1, 0)
        mine.dig(0, 0)
        self.assertEqual(mine.dug_cells, 1)

    def test_aHoleCannotBeDugTwice(self):
        mine = Minesweeper(1, 1, 0)
        mine.dig(0, 0)
        mine.dig(0, 0)
        self.assertEqual(mine.dug_cells, 1)

    def test_digAnEmptyHoleRevealsNothing(self):
        mine = Minesweeper(1, 1, 0)
        self.assertEqual(mine.dig(0, 0), Minesweeper.NOTHING)

    def test_digAHoleWithMinesRevealsIt(self):
        mine = Minesweeper(1, 1, 1)
        self.assertEqual(mine.dig(0, 0), Minesweeper.MINE)

    def test_digAHoleWithOneMineAroundShowsIt(self):
        mine = Minesweeper(1, 2, 1, lambda _x, _y: [1])
        self.assertEqual(mine.dig(0, 0), Minesweeper.ONE_AROUND)

    def test_startCondition(self):
        mine = Minesweeper(1, 1, 1)
        self.assertEqual(mine.status, Minesweeper.UNFINISHED)

    def test_loseCondition(self):
        mine = Minesweeper(1, 1, 1)
        mine.dig(0, 0)
        self.assertEqual(mine.status, Minesweeper.DEFEAT)

    def test_winCondition(self):
        mine = Minesweeper(1, 1, 0)
        mine.dig(0, 0)
        self.assertEqual(mine.status, Minesweeper.VICTORY)
