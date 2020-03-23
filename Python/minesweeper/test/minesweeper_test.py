from unittest import TestCase
from src.minesweeper import Minesweeper, FieldEnum, Field

class TestField(TestCase):
    def test_digAHoleSuccessfully(self):
        field = Field(1, 1, 1)
        self.assertTrue(field.dig(0, 0))

    def test_digAHoleTwiceFails(self):
        field = Field(1, 1, 1)
        field.dig(0, 0)
        self.assertFalse(field.dig(0, 0))

    def test_getFieldElement(self):
        field = Field(1, 1, 1)
        self.assertEqual(field[0][0], FieldEnum.NOTHING)

class TestMinesweeper(TestCase):
    def test_digAnEmptyHoleRevealsNothing(self):
        mine = Minesweeper(1, 1, 0)
        self.assertEqual(mine.dig(0, 0), FieldEnum.NOTHING)

    def test_digAHoleWithMinesRevealsIt(self):
        mine = Minesweeper(1, 1, 1)
        self.assertEqual(mine.dig(0, 0), FieldEnum.MINE)

    def test_digAHoleWithOneMineAroundShowsIt(self):
        mine = Minesweeper(1, 2, 1, lambda _x, _y: [1])
        self.assertEqual(mine.dig(0, 0), FieldEnum.ONE_AROUND)

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
