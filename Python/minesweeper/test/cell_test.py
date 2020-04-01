#pylint: disable=missing-module-docstring
from unittest import TestCase
from src.cell import Cell

#pylint: disable=missing-class-docstring
class CellTest(TestCase):
    #pylint: disable=missing-function-docstring
    def test_cell_starts_not_digged(self):
        cell = Cell()
        self.assertFalse(cell.digged())

    def test_cell_starts_not_flagged(self):
        cell = Cell()
        self.assertFalse(cell.flagged())

    def test_has_mine_without_mine(self):
        cell = Cell()
        self.assertFalse(cell.has_mine())

    def test_has_mine_with_mine(self):
        cell = Cell(True)
        self.assertTrue(cell.has_mine())

    def test_digged_not_digged(self):
        cell = Cell()
        self.assertFalse(cell.digged())

    def test_digged_digged(self):
        cell = Cell()
        cell.dig()
        self.assertTrue(cell.digged())

    def test_flagged_not_flagged(self):
        cell = Cell()
        self.assertFalse(cell.flagged())

    def test_flagged_flagged(self):
        cell = Cell()
        cell.switch_flag()
        self.assertTrue(cell.flagged())

    def test_switch_flag_covered(self):
        cell = Cell()
        cell.switch_flag()
        self.assertTrue(cell.flagged())

    def test_switch_flag_uncovered(self):
        cell = Cell()
        cell.dig()
        cell.switch_flag()
        self.assertFalse(cell.flagged())

    def test_switch_flag_flagged(self):
        cell = Cell()
        cell.switch_flag()
        cell.switch_flag()
        self.assertFalse(cell.flagged())

    def test_dig_once_returns_true(self):
        cell = Cell()
        self.assertTrue(cell.dig())

    def test_dig_twice_returns_false(self):
        cell = Cell()
        cell.dig()
        self.assertFalse(cell.dig())

    def test_dig_marks_digged_as_true(self):
        cell = Cell()
        cell.dig()
        self.assertTrue(cell.digged())
  
    def test_equality_mine(self):
        cell_1 = Cell(False)
        cell_2 = Cell(False)
        self.assertTrue(cell_1 == cell_2)

    def test_inequality_mine(self):
        cell_1 = Cell(True)
        cell_2 = Cell(False)
        self.assertFalse(cell_1 == cell_2)

    def test_equality_dig(self):
        cell_1 = Cell(True)
        cell_1.dig()
        cell_2 = Cell(True)
        cell_2.dig()
        self.assertTrue(cell_1 == cell_2)

    def test_inequality_dig(self):
        cell_1 = Cell(False)
        cell_1.dig()
        cell_2 = Cell(False)
        self.assertFalse(cell_1 == cell_2)

    def test_equality_flag(self):
        cell_1 = Cell(True)
        cell_1.switch_flag()
        cell_2 = Cell(True)
        cell_2.switch_flag()
        self.assertTrue(cell_1 == cell_2)

    def test_inequality_flag(self):
        cell_1 = Cell(True)
        cell_1.switch_flag()
        cell_2 = Cell(True)
        self.assertFalse(cell_1 == cell_2)

    def test_winnable_no_mine_no_dug(self):
        cell = Cell(False)
        self.assertFalse(cell.winnable())

    def test_winnable_no_mine_dug(self):
        cell = Cell(False)
        cell.dig()
        self.assertTrue(cell.winnable())

    def test_winnable_mine_no_dug(self):
        cell = Cell(True)
        self.assertTrue(cell.winnable())

    def test_winnable_mine_dug(self):
        cell = Cell(True)
        cell.dig()
        self.assertFalse(cell.winnable())
