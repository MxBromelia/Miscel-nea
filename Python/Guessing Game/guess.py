"""Guess The Number Game"""

def match(number, guess):
    """Compara o número com a tentativa do usuário"""
    ret = ""

    rnge = min(len(number), len(guess))
    for i in range(0, rnge):
        if guess[i] == number[i]:
            ret += '+'
        elif number.find(guess[i]) != -1:
            ret += '*'
        else:
            ret += '-'
    return ret

def assert_match(match_str):
    """Checa se a tentativa está correta"""
    for match_ch in match_str:
        if match_ch != '+':
            return False
    return True

def guess_game(number, tries):
    """Main Loop"""
    print("Guess a number: ")
    for i in range(0, tries):
        inp = input()
        aux = match(number, inp)

        if assert_match(aux) is True:
            print("Ganhou")
            break
        else:
            print("{}, mais {} tentativas".format(aux, tries - i))
    else:
        print("Perdeu")


if __name__ == '__main__':
    guess_game("1234", 8)
