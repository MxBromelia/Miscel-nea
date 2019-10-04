import random

class Conta:
    agencia = None
    conta = None
    saldo = 0
    num_op = 0
    extrato = []

    def __init__(self, saldo):
        self.agencia = 12345
        self.conta = int(10000*(random.random()+1))
        self.saldo = float(saldo)

    def saque(self, valor):
        if(self.saldo - valor >= 0):
            self.num_op += 1
            self.saldo -= valor
            self.extrato.append({"n": self.num_op, "tipo":"saque", "valor":valor})
            return self.saldo
        else:
            return -1

    def deposito(self, valor):
        self.num_op+=1
        self.saldo += valor
        self.extrato.append({"n": self.num_op, "tipo":"depósito", "valor":valor})

    def mostrarExtrato(self):
        for op in self.extrato:
            print("#"+str(op["n"])+": "+op["tipo"]+" "+str(op["valor"]))

c = Conta(200)
c.saque(50)
c.deposito(30)
c.mostrarExtrato()
