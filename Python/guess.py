def check_guess(number, guess):
    ret = []

    rnge = min(len(number),len(guess))
    for i in range(0,rnge):
        if guess[i] == number[i]:
            ret.append('+')
        elif number.find(guess[i]) != -1:
            ret.append('*')
        else:
            ret.append('-')
    return ret