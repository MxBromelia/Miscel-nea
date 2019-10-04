"""Unit Tests for Guess The Number Game"""
import unittest
import guess

class GuessTest(unittest.TestCase):
    """Unit Test for match function"""
    def test_match_right(self):
        """ Cenário 1: Tentativa está totalmente correta """
        self.assertEqual(guess.match('1234', '1234'), '++++')
    def test_match_wrong(self):
        """ Cenário 2: Tentativa está totalmente errada """
        self.assertEqual(guess.match('1234', '5678'), '----')
    def test_match_disarray(self):
        """ Cenário 3: Tentativa tem dígitos corretos, mas fora do lugar """
        self.assertEqual(guess.match('1234', '4321'), '****')
    def test_match_almost(self):
        """ Cenário 4: Tentativa tem 1 exato e 1 fora de lugar """
        self.assertEqual(guess.match('1234', '1528'), '+-*-')

    def test_assert_match(self):
        """ Cenário 1: Tentativa Acertada """
        self.assertEqual(guess.assert_match("++++"), True)

if __name__ == '__main__':
    unittest.main()
