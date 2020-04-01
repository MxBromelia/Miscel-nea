# pylint: disable=missing-module-docstring
# pylint: disable=missing-class-docstring
# pylint: disable=missing-function-docstring
from unittest import TestCase
from src.game import Board
from src.exceptions import ValidationError

class BoardTest(TestCase):
    def test_start_cells(self):
        board = Board(2, 2, [True, True, False, False])
        self.assertEqual(board.cells, 4)

    def test_rows_is_immutable(self):
        board = Board(1, 1, [True])
        with self.assertRaises(AttributeError):
            board.rows = 2

    def test_cols_is_immutable(self):
        board = Board(1, 1, [True])
        with self.assertRaises(AttributeError):
            board.cols = 2

    def test_generation_puts_mines(self):
        board = Board(1, 1, [True])
        self.assertTrue(board.at(0,0).has_mine())

    def test_generation_puts_nothing(self):
        board = Board(1, 1, [False])
        self.assertFalse(board.at(0,0).has_mine())

    def test_generation_raises_when_less_values(self):
        with self.assertRaises(ValidationError):
            Board(2, 2, [True, True, False])

    def test_generation_raises_when_more_values(self):
        with self.assertRaises(ValidationError):
            Board(2, 1, [True, True, False])

    def test_generation_raises_when_invalid_input(self):
        with self.assertRaises(ValidationError):
            Board(2, 2, [True, False, True, 'False'])

    def test_around_not_cornered_cell(self):
        board = around_board()
        compare = filter_cells(board, 0, 1, 2, 3, 5, 6, 7, 8)
        self.assertEqual(compare, board.around(1, 1))

    def test_around_first_row(self):
        board = around_board()
        compare = filter_cells(board, 0, 2, 3, 4, 5)
        self.assertEqual(compare, board.around(0, 1))

    def test_around_last_row(self):
        board = around_board()
        compare = filter_cells(board, 3, 4, 5, 6, 8)
        self.assertEqual(compare, board.around(2, 1))

    def test_around_first_column(self):
        board = around_board()
        compare = filter_cells(board, 0, 1, 4, 6, 7)
        self.assertTrue(compare, board.around(1, 0))

    def test_around_last_column(self):
        board = around_board()
        compare = filter_cells(board, 1, 2, 4, 7, 8)
        self.assertEqual(compare, board.around(1, 2))

    def test_arount_first_row_first_column(self):
        board = around_board()
        compare = filter_cells(board, 1, 3, 4)
        self.assertEqual(compare, board.around(0, 0))

    def test_around_first_row_last_column(self):
        board = around_board()
        compare = filter_cells(board, 1, 4, 5)
        self.assertEqual(compare, board.around(0, 2))

    def test_around_last_row_first_column(self):
        board = around_board()
        compare = filter_cells(board, 3, 4, 7)
        self.assertEqual(compare, board.around(2, 0))

    def test_around_last_row_last_column(self):
        board = around_board()
        compare = filter_cells(board, 4, 5, 7)
        self.assertEqual(compare, board.around(2, 2))

def filter_cells(board, *indexes):
    ret = []
    for index in indexes:
        ret.append(board.at_index(index))
    return ret

def around_board():
    placement = [True, False, True, False, True, False, True, False, True]
    return Board(3, 3, placement)
