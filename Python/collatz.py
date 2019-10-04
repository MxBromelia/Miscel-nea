def collatz(number):
    if number%2 == 0:
        col = number//2
    else:
        col = 3*number+1
    print(str(col))
    return col

def collatzToOne(number):
    col = collatz(number)
    while(col != 1):
        col = collatz(col)
