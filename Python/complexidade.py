def anbm (string):
    it = 0
    pos = 0

    while (string[pos] == 'a'):
        pos += 1
        it += 1

    if string[pos] == 'b':
        pos+=1
        it +=1
    else:
        return

    if (pos != len(string)):
        while (string[pos] == 'b'):
            pos +=1
            it += 1

            if(pos == len(string)):
                break

    pos -= 1
    it += 1

    while (string[pos] == 'a' or string[pos] == 'b'):
        pos -= 1
        it += 1

        if(pos == 0):
            it += 1
            break
    return it
#-----------------------------------------------------

def anbn_alg1 (string):
    it = anbm(string)
    pos = 0

    while (True):
        if string[pos] == 'a':
            string[pos] = '0'
            pos += 1
            it += 1

        while (string[pos] == 'a' or string[pos] == '0'):
            pos += 1
            it += 1

        if(string[pos] == 'b'):
            string[pos] = '0'
            pos -= 1
            it += 1

        while (string[pos] == '0'):
            pos -= 1
            it += 1

            if (pos == 0):
                break

        while (string[pos] == 'a'):
            pos -= 1
            it += 1

        if (string[pos] == '0'):
            pos += 1
            it += 1

    return it
        
