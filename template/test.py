#test1.py
#import os
#os.chdir(os.path.dirname(os.path.abspath(__file__)))
import sys
from csclib import *

def main():
  q = 16

  x = Share([1,2,3], q)
  print("x")
  x.print()

if __name__ == '__main__':
  party = -1

  args = sys.argv
  if len(args) >= 2:
    party = int(args[1])
  Csclib_start(party)

  main()

