import pytest
import hangman as hangmodule

# class Word
@pytest.fixture
def word():
    return hangmodule.Word('word')

def test_word_starts_with_full_mask(word):
    assert word.mask == '____'

def test_guessing_a_character_correctly_uncovers_it(word):
    word.guess('w')
    assert word.mask == 'w___'

def test_word_starts_with_no_wrong_guesses(word):
    assert word.wrong_guesses == []

def test_guessing_a_character_correctly_does_not_add_to_wrong_guesses(word):
    word.guess('w')
    assert word.wrong_guesses == []

def test_guessing_a_character_wrong_adds_to_wrong_guesses(word):
    word.guess('s')
    assert 's' in word.wrong_guesses

def test_guessing_a_character_wrong_twice_does_not_adds_the_character_again(word):
    word.guess('s')
    word.guess('s')
    assert len(word.wrong_guesses) == 1

# Class Hangman
@pytest.fixture
def hangman():
    return hangmodule.Hangman('w', 1)

def test_hangman_starts_without_losing(hangman):
    assert hangman.lost() is False

def test_hangman_starts_without_winning(hangman):
    assert hangman.won() is False

def test_hangman_loses_after_missing_equivalent_to_the_number_of_lives(hangman):
    hangman.guess('s')
    assert hangman.lost() is True

def test_hangman_wins_after_guessing_all_letters(hangman):
    hangman.guess('w')
    assert hangman.won() is True