
import random
'''
This method implements generator in Python, which is basiclly iterator, but return value with some operation.
The conflict method will calculates that the existed state and next one can not be in the same row/column nor same diagnol
The queens generator will traverse all possible solutions. Recursive and backtrack/situation record is realized by the "yield"
'''

def conflict(state, nextX):
  nextY=len(state)
  for i in range(nextY):
    if abs(state[i]-nextX) in (0, nextY-i):
      return True
      
def queens(num=4, state=()):
  #print 'Call queens, ', 'num: ', num, 'state: ', state
  for pos in range(num):
    if not conflict(state, pos):
      if len(state) == num-1:
        yield (pos,)
      else:
        for result in queens(num, state+(pos,)):
          yield (pos,)+result
    #else:
      #print 'Confliction violated! pos: ', pos, 'state: ', state
      
def prettyprint(solution):
  def line(pos, length=len(solution)):
    return ' . '*(pos)+' X '+' . '*(length-pos-1)
  for pos in solution:
    print line(pos)

solution_list = list(queens(4))
print solution_list
#prettyprint(random.choice(list(queens(4))))
for i in range(len(solution_list)):
  print 'Solution No. i'
  prettyprint(solution_list[i])
  print ''
  
