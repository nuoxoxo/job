import sys, math
from dataclasses import dataclass

ME = 1
OPP = 0
NONE = -1

width, height = [int(i) for i in input().split()]

@dataclass
class Cell_Info:
    x: int
    y: int
    scam: int
    ownership: int
    units: int
    recy: bool
    canbd: bool
    cansp: bool
    in_recy_range: bool

def get_foe4dir(_coors):
    foe4dir = dict()
    for tile in _coors:
        currentNeibCount = 0
        for otherTile in _coors:
            if otherTile.x == tile.x and otherTile.y == tile.y:
                break
            if otherTile.x == tile.x +1 and otherTile.y == tile.y and otherTile.ownership == OPP:
                currentNeibCount += 1
            elif otherTile.x == tile.x -1 and otherTile.y == tile.y and otherTile.ownership == OPP:
                currentNeibCount += 1
            elif otherTile.x == tile.x and otherTile.y == tile.y+1 and otherTile.ownership == OPP:
                currentNeibCount += 1
            elif otherTile.x == tile.x and otherTile.y == tile.y-1 and otherTile.ownership == OPP:
                currentNeibCount += 1
        foe4dir[(tile.x, tile.y)] = currentNeibCount
    return foe4dir

def getUnitOpp(_coors):
    dictTileToUnitOpp = dict()
    for tile in _coors:
        dictTileToUnitOpp[(tile.x, tile.y)] = tile.units
    return dictTileToUnitOpp

def getTileBattleFront(tileops, mycoors):
    min = None
    closest = None
    for mytile in mycoors:
        for tileop in tileops:
            diff = abs(tileop.x-mytile.x) + abs(tileop.y-mytile.y)
            if min == None:
                min = diff
            else:
                if diff < min :
                    min = diff
                    closest = mytile
    return closest

def getDistance(a, b):
    return abs(a.x-b.x) + abs(a.y-b.y)

# game loop
while True:
    coors = []

    unit_mine = []
    unit_them = []

    recy_mine = []
    recy_them = []

    land_them = []
    land_mine = []
    land_neut = []

    my_matter, opp_matter = [int(i) for i in input().split()]

    for y in range(height):
        for x in range(width):
            # ownership: 1 = me, 0 = foe, -1 = neutral
            scam, ownership, units, recy, canbd, cansp, \
                    in_recy_range = [int(k) for k in input().split()]
            
            tile = Cell_Info(x, y, scam, ownership, units, recy == 1, \
                    canbd == 1, cansp == 1, in_recy_range == 1)

            coors.append(tile)

            if tile.ownership == ME:
                land_mine.append(tile)
                if tile.units > 0:
                    unit_mine.append(tile)
                elif tile.recy:
                    recy_mine.append(tile)
            
            elif tile.ownership == OPP:
                land_them.append(tile)
                if tile.units > 0:
                    unit_them.append(tile)
                elif tile.recy:
                    recy_them.append(tile)
            
            elif tile.scam > 0:
                land_neut.append(tile)

    actions = []

    #find the best place to build scrapper (most neibs)
    foe4dir = get_foe4dir(land_mine)
    bestNeibCount = -1
    for tile in land_mine:
        if foe4dir[(tile.x, tile.y)] > bestNeibCount:
            bestNeibCount = foe4dir[(tile.x, tile.y)]
            bestTile = tile

    #find closest tile to spawn robot
    battlefront = getTileBattleFront(unit_them, land_mine)

    for tile in land_mine:
        if tile.cansp:
            amount = 0 # TO DO: pick amount of robots to spawn here
            if battlefront:
                if tile.x == battlefront.x and tile.y == battlefront.y:
                    amount = 1
            if amount > 0:
                actions.append('SPAWN {} {} {}'.format(amount, tile.x, tile.y))
        if tile.canbd:
            if bestNeibCount > 0:
                should_build = (tile == bestTile) # TO DO: pick whether to build recy here
            else:
                should_build = False
            if should_build:
                actions.append('BUILD {} {}'.format(tile.x, tile.y))

    #find where the opp unit are
    dicUnitOppFromTile = getUnitOpp(unit_them)
    targets = list()
    for tile in unit_them:
        targets.append(tile)
    targets.sort(key=lambda x: x.units, reverse=True)
    #st = ''
    #for tile in targets:
    #    st += '(' + str(tile.x) + ', ' + str(tile.y) + ') '
    #actions.append('MESSAGE ' + st)

    # find targeted location (neutral or opp)
    targetedTiles = land_them.copy()
    targetedTiles += land_neut

    st = ''
    for tile in targetedTiles:
        st += '(' + str(tile.x) + ', ' + str(tile.y) + ') '
    #actions.append('MESSAGE ' + st)


    # move units
    for tile in unit_mine:
        targetedTiles.sort(key=lambda p: getDistance(tile, p))
        target = None

        if len(targetedTiles) > 0:
            target = targetedTiles[0]
            targetedTiles.remove(target)
        
        if target:
            amount = tile.units # TODO: pick amount of units to move
            actions.append('MOVE {} {} {} {} {}'.format(amount, tile.x, tile.y, target.x, target.y))

    # To debug: print("Debug messages...", file=sys.stderr, flus
    print(';'.join(actions) if len(actions) > 0 else 'WAIT')
