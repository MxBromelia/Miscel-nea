"""Tentativa de resolver problema dos tijolos"""
from itertools import chain
SUBTRACT = lambda _list, sublist: [el for el in _list if el not in sublist]
UNIQUE = lambda _list: [x for x in _list if _list.count(x) > 1] == []

def acc_sum(_list):
    """Retorna uma lista em que cada elemento é a soma dos anteriores"""
    acc_list = []
    acc = _list.pop(0)
    for elm in _list:
        acc_list.append(acc)
        acc += elm
    return acc_list

class Wall:
    """Estrutura de parede para algoritmo dos tijolos"""
    def __init__(self, n):
        self.bricks_number = n
        self.__brick_set = set(range(1, n+1))
        self.row_length = int(n*(n+1)/2)
        self.__joint_set = set(range(0, self.row_length))
        self.height = 0
        self.wall = []

    def brick_set(self):
        """Retorna conjunto de tijolos"""
        return self.__brick_set.copy()

    def joint_set(self):
        """Retorna conjunto de juntas"""
        return self.__joint_set.copy()

    def construct(self, xxx):
        """ Construct """
        return self.__satisfaction_test(xxx)

    def __satisfaction_test(self, wall):
        """Tenta construir uma parede seguindo as regras do problema"""
        if list(filter(lambda x: not self.__is_permutation(x), wall)) != []:
            return False

        c_wall = chain.from_iterable(map(acc_sum, wall))
        if UNIQUE(list(c_wall)):
            c_wall = set(c_wall)
        else:
            return False
        print(c_wall)
        print(self.__joint_set)
        return "Sim" if c_wall.issubset(self.__joint_set) else "Não"

    def __is_permutation(self, row):
        return list(filter(lambda x: x not in row, self.__brick_set)) == []

    def __repr__(self):
        return "Brick Wall containing {} bricks\n".format(self.bricks_number) \
            +  "Each row has length of {} units".format(self.row_length)

if __name__ == '__main__':
    print(Wall(3).construct([[1, 2, 3], [2, 3, 1]]))
