import sys, math
from collections import defaultdict

# boiler
C, R = [int(i) for i in input().split()]

""" first 4 variables :: properties for the tile:"""
#      scrap_amount
#           number of energy
#      owner:
#           -1  > enemy
#           0   > neutral
#           1   > i own it
#       units
#           the number of MY units
#       recycler : Bool
#           1   > if it's a recycler whoever owns it
#           0   > if none
""" next 3 variables :: boolean helpers """
#       canBuild . can_build_a_recycler
#           1 if i can BUILD a recycler here THIS turn
#           0 otherwise
#       canSpawn
#           1 if i can SPAWN units here this turn
#           0 otherwise
#       inRangeOfRecycler
#           1 if scrap_amount -= 1 at turn's end
#           0 otherwise"""

class Cell(object):
    def __init__(self, r: int, c: int, sc: int, ow: int, un:int, \
            rc: bool, canbd: bool, cansp: bool, in_rc_range: bool):
        self.r = r
        self.c = c
        self.scrap_amount = sc
        self.ownership = ow
        self.units = un
        self.recycler = rc
        self.can_build = canbd
        self.can_spawn = cansp
        self.in_rc_range = in_rc_range

D = [(-1, 0), (1, 0), (0, 1), (0, -1)]

while True: # game loop

    G = []
    land_neut = []
    army_mine, land_mine, recy_mine = [], [], []
    army_them, land_them, recy_them = [], [], []
    
    counts = {}

    ### boiler begins
    my_matter, opp_matter = [int(i) for i in input().split()]
    for r in range(height):
        for c in range(width):
            counts[(r, c)] = 0 # save coor
            # owner: 1 = me, 0 = foe, -1 = neutral
            sc, ow, un, rc, canbd, cansp, \
            in_rc_range = [int(k) for k in input().split()]
    ### boiler ends
    # Store cells
            cell = Cell(r, c, sc, pw, un, rc == 1, \
                canbd == 1, cansp == 1, in_rc_range == 1)
            G.append(cell)
            # -1 foe . 0 peace . 1 is mine
            if cell.ownership == 0: # neutral
                land_neut.append(cell)
            if cell.ownership == 1: # self
                if cell.units > 0:
                    army_mine.append(cell)
                if cell.recycler:
                    recy_mine.append(cell)
                land_mine.append(cell)
            if cell.ownership == -1: # other
                if cell.units > 0:
                    army_them.append(cell)
                if cell.recycler:
                    recy_them.append(cell)
                land_them.append(cell)
    for cell in G:
        r, c = cell.r, cell.c
        for d in D:
            rr, cc = r + d[0], c + d[1]
            if (rr, cc) not in counts:
                continue
            if 




    print("WAIT")






























# goodbye cruel world
