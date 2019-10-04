import random

class NoneTypeException(Exception):
    def x():
        return
    
class Knot:
    key = 0
    content = None
    left = None
    right = None

    def __init__(self, key, content):
        self.key = key

    def addKnot(self, knot):
        if  (knot.key < self.key):
            if(self.left == None):
                self.left = knot
            else:
                self.left.addKnot(knot)
        elif(knot.key > self.key):
            if(self.right == None):
                self.right = knot
            else:
                self.right.addKnot(knot)

    def printTree(self):
        self.printKnot(0)

    def printKnot(self, height):
        s = ""
        sLeft = self.left
        sRight = self.right
        
        if(self == None):
            return

        for i in range(0,height):
            s = s + "  "

        if(sRight != None):
            sRight.printKnot(height+1)
        else:
            print(s + "  **")
        
        print(s + str(self.key))
        
        if(sLeft != None):
            sLeft.printKnot(height+1)
        else:
            print(s + "  **")

    def print(self):
        print(self.key)

k = Knot(random.randint(0,100), None)

for i in range(0,10):
    k.addKnot(Knot(random.randint(0,100), None))

k.printTree()
