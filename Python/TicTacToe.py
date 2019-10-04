TicTacToe = []

def value(move):
    """ Determine the piece to be displayed on the Table """
    if move == 1:
        return 'O'
    elif move == -1:
        return 'X'
    else:
        return ' '

def printTable():
    """ Print the current Table, showing how the game is progressing """
    for i in range(0,3):
        row = ""
        for j in range(0,3):
            row += str(value(TicTacToe[i][j]))
            if j<2:
                row += "|"
        print(row)

def newTicTacToeGame():
    """ Reset the variables for start/restat the game """
    del TicTacToe[:]

    for i in range(0,3):
        TicTacToe.append([])
        for j in range(0,3):
            TicTacToe[i].append(0)

def checkWin():
    """ Check if there are any winner in the current game """
    t3 = TicTacToe
    
    for i in range(0,3):
        checker = 0
        for j in range(0, 3):
            checker+= t3[i][j]
        if checker == 3:
            return 1
        elif checker == -3:
            return -1
    
    for j in range(0,3):
        checker = 0
        for i in range(0, 3):
            checker+= t3[i][j]
        if checker == 3:
            return 1
        elif checker == -3:
            return -1

    checker = 0
    for i in range(0,3):
        checker+= t3[i][i]
        if checker == 3:
            return 1
        elif checker == -3:
            return -1

    checker = 0
    for i in range(0,3):
        checker+= t3[i][2-i]
        if checker == 3:
            return 1
        elif checker == -3:
            return -1
    return 0

def makeAMove(turn):
    move = None
    while move != 0:
        moveRow = int(input("Row: "))
        moveCol = int(input("Column: "))
        move = TicTacToe[moveRow-1][moveCol-1]
        
    TicTacToe[moveRow-1][moveCol-1] = int(turn)
    return checkWin()

def setFirst():
    who = input("Who is going to start (X or O)")

    if who == 'X':
        return -1
    else:
        return 1

def gameStart():
    x_wins = 0
    o_wins = 0
    ties = 0
    choice = 0
    
    while choice != 2:
        turn = setFirst()
        printTable()
        for moves in range(0,9):
            winner = makeAMove(turn)
            turn *= -1
            printTable()
            if(winner != 0):
                print(value(winner) + " Won!")
                if winner == 1:
                    o_wins+=1
                elif winner == -1:
                    x_wins+=1
                break
        else:
            print("Tie!")
            ties+=1
        
        print("O - " + str(o_wins) + " Wins, "),
        print("X - "+str(x_wins)+" Wins, "),
        print("Ties - "+str(ties))
        print("1 - Play Again")
        print("2 - Exit")
        choice = int(input("Choose: "))
        if choice == 1:
            newTicTacToeGame()
        elif choice == 2:
            exit()
    
    
def printHelp():
    helpfile = open("help.txt", "r")
    line = ""
    line = helpfile.read(80)
    print(line)
    helpfile.close()

def menuInterface():
    choice = 0
    while choice != 3:
        print("1 - Play")
        print("2 - Help")
        print("3 - Exit")

        try:
            choice = int(input("Choose: "))
            if choice == 1:
                gameStart()
            elif choice == 2:
                printHelp()
            elif choice == 3:
                exit()
            else:
                print("Erro: Número Inválido")
                pass
        except ValueError as verr:
            print("Erro: Resposta Inválida")
            pass

def play():
    newTicTacToeGame()
    menuInterface()

play()
