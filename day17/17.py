#!/usr/bin/python3
import sys
import heapq
import itertools
from collections import defaultdict, Counter, deque

#target area: x=235..259, y=-118..-62

p2 = 0
ans = 0
for DX in range(1000):
    for DY in range(-1000, 1000):
        ok = False
        max_y = 0
        x = 0
        y = 0
        dx = DX
        dy = DY
        for t in range(1000):
            x += dx
            y += dy
            max_y = max(max_y, y)
            if dx > 0:
                dx -= 1
            elif dx < 0:
                dx += 1
            dy -= 1
            if 235<=x<=259 and -118<=y<=-62:
                ok = True
        if ok:
            p2 += 1
            if max_y > ans:
                ans = max_y
                print(DX,DY,ans)
print(ans)
print(p2)

