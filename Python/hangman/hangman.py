class Word:
    def __init__(self, word: str):
        self.word = word
        self.guesses = set()

    def guess(self, character: str) -> None:
        self.guesses.add(character)

    @property
    def wrong_guesses(self) -> list:
        return [guess for guess in self.guesses if guess not in self.word]

    @property
    def mask(self) -> list:
        return ''.join([char if char in self.guesses else '_' for char in self.word])

    def __str__(self):
        return self.word

class Hangman:
    def __init__(self, word:str = '', lives: int = 5):
        self.word = Word(word)
        self.lives = lives

    def guess(self, character: str):
        self.word.guess(character)

    def won(self) -> bool:
        return str(self.word) == self.word.mask

    def lost(self) -> bool:
        return len(self.word.wrong_guesses) >= self.lives
    
    def remaining_lives(self) -> int:
        return len(self.word.wrong_guesses) - self.lives
    
    def __str__(self):
        return f'{self.word.mask} - {self.remaining_lives()} vidas restantes'

if __name__ == '__main__':
    hangman = Hangman('word')
    print(hangman)
    while(not hangman.won() and not hangman.lost()):
        print('Escolha uma letra:')
        character = input()[0]
        hangman.guess(character)
        print(hangman)
    
    if(hangman.won()):
        print('Você venceu!')
    else:
        print('Você perdeu!')