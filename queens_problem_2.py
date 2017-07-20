

from itertools import permutations


def queens(N=8, solution=0):
    cols = range(N)
    for combo in permutations(cols):
        if N==len(set(combo[i]+i for i in cols))==len(set(combo[i]-i for i in cols)):
            solution+=1
            print 'Solution '+str(solution)+': '+str(combo)+'\n'
            print '\n'.join(' . '*i + ' X '+' . '*(N-i-1) for i in combo) + '\n'

queens(8)
