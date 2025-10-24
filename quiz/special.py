#!/usr/bin/env python3
import sys

def rstrip_space(s):
    return ' '.join(s.strip().split())

fa, fb = open(sys.argv[2]), open(sys.argv[3])
while True:
    la, lb = fa.readline(), fb.readline()
    if la:
        if not lb or rstrip_space(la) != rstrip_space(lb):
            quit(1)
    elif lb:
        quit(1)
    else:
        break


