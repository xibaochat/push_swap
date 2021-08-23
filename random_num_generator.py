import os
from random import randint


if __name__ in '__main__':
    NB_TO_GENERATE = int(os.environ['NB_TO_GENERATE'])

    n = []
    for i in range(NB_TO_GENERATE):
        random_n = str(randint(-2147483648, 2147483647))
        if random_n not in n:
            n.append(random_n)

    print(' '.join(n))
