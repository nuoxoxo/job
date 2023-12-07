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
#       unit
#           the number of MY unit
#       recycler : Bool
#           1   > if it's a recycler whoever owns it
#           0   > if none
""" next 3 variables :: boolean helpers """
#       canBuild . can_build_a_recycler
#           1 if i can BUILD a recycler here THIS turn
#           0 otherwise
#       canSpawn
#           1 if i can SPAWN unit here this turn
#           0 otherwise
#       inRangeOfRecycler
#           1 if scrap_amount -= 1 at turn's end
#           0 otherwise"""

D = [(-1, 0), (1, 0), (0, 1), (0, -1)]

while True: # game loop

    coors = [] # all (r, c)
    foe4dir = {} # LRUD foes for all (r, c)
    
    G = {} # !default . info for a (r,c)
    
    land_neut = []
    unit_mine, land_mine, recy_mine = [], [], []
    unit_them, land_them, recy_them = [], [], []
    
    ### boiler begins ###
    my_matter, opp_matter = [int(i) for i in input().split()]
    for r in range(R):
        for c in range(C):
            scam, ownership, unit, recy, canbd, \
            cansp, recy_range = [int(k) for k in input().split()]
    ### boiler ends ###

    # 1 -- BUILD at shark infested waters
    # 2 -- SPAWN around the nearest shark
    # 3 -- MOVE either to them or to no mans land
            cell = (r, c)
            coors.append(cell)
            land_neut.append(cell)
            G[cell] = [scam, ownership, unit, recy == 1,
                canbd == 1, cansp == 1, recy_range == 1]
            # -1 foe . 0 peace . 1 is mine
            ## assert exclusive
            if ownership == 0: # neutral
                land_neut.append(cell)
            if ownership == 1: # self
                if unit > 0:
                    unit_mine.append(cell)
                if recy:
                    recy_mine.append(cell)
                land_mine.append(cell)
            if ownership == -1: # them
                if unit > 0:
                    unit_them.append(cell)
                if recy:
                    recy_them.append(cell)
                land_them.append(cell)
    # BUILD:
    # how many foe neighbours a cell got
    
    # print("their land:\n", land_them, file=sys.stderr, flush=True)
    # print("our land:\ne", land_mine, file=sys.stderr, flush=True)
    
    for coor in land_neut:
        curr = coor
        # print(me, file=sys.stderr, flush=True)
        r, c = curr
        for dr, dc in D:
            rr, cc = r + dr, c + dc
            # print(rr, cc, file=sys.stderr, flush=True)
            if (rr, cc) in land_them:
                foe4dir[curr] = 1 if curr not in foe4dir else foe4dir[curr] + 1
    
    # cell with most foes
    ## assert type == List[point]
    
    cell_hostile = max(foe4dir, key=foe4dir.get)
    print(cell_hostile, file=sys.stderr, flush=True)
    
    ## assert size == 1
    # cell_nearest_hostile = find_cell_nearest_hostile(units_mine, cells_hostile)
    
    for me in unit_mine:
        print(f'MOVE 1 {me[1]} {me[0]} {cell_hostile[0]} {cell_hostile[1]};', end='')
    
    print()





















# goodbye cruel world

