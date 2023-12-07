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
    scrap_amount: int
    owner: int
    units: int
    recycler: bool
    can_build: bool
    can_spawn: bool
    in_range_of_recycler: bool

def getTileNeighbors(_tiles):
    dictTileToNeibs = dict()
    for tile in _tiles:
        currentNeibCount = 0
        for otherTile in _tiles:
            if otherTile.x == tile.x and otherTile.y == tile.y:
                break
            if otherTile.x == tile.x +1 and otherTile.y == tile.y and otherTile.owner == OPP:
                currentNeibCount += 1
            elif otherTile.x == tile.x -1 and otherTile.y == tile.y and otherTile.owner == OPP:
                currentNeibCount += 1
            elif otherTile.x == tile.x and otherTile.y == tile.y+1 and otherTile.owner == OPP:
                currentNeibCount += 1
            elif otherTile.x == tile.x and otherTile.y == tile.y-1 and otherTile.owner == OPP:
                currentNeibCount += 1
        dictTileToNeibs[(tile.x, tile.y)] = currentNeibCount
    return dictTileToNeibs

def getUnitOpp(_tiles):
    dictTileToUnitOpp = dict()
    for tile in _tiles:
        dictTileToUnitOpp[(tile.x, tile.y)] = tile.units
    return dictTileToUnitOpp

def getTileBattleFront(tileops, mytiles):
    min = None
    closest = None
    for mytile in mytiles:
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
    tiles = []

    my_units = []
    opp_units = []

    my_recyclers = []
    opp_recyclers = []

    opp_tiles = []
    my_tiles = []
    neutral_tiles = []

    my_matter, opp_matter = [int(i) for i in input().split()]

    for y in range(height):
        for x in range(width):
            # owner: 1 = me, 0 = foe, -1 = neutral
            scrap_amount, owner, units, recycler, can_build, can_spawn, \
                    in_range_of_recycler = [int(k) for k in input().split()]
            
            tile = Cell_Info(x, y, scrap_amount, owner, units, recycler == 1, \
                    can_build == 1, can_spawn == 1, in_range_of_recycler == 1)

            tiles.append(tile)

            if tile.owner == ME:
                my_tiles.append(tile)
                if tile.units > 0:
                    my_units.append(tile)
                elif tile.recycler:
                    my_recyclers.append(tile)
            
            elif tile.owner == OPP:
                opp_tiles.append(tile)
                if tile.units > 0:
                    opp_units.append(tile)
                elif tile.recycler:
                    opp_recyclers.append(tile)
            
            elif tile.scrap_amount > 0:
                neutral_tiles.append(tile)

    actions = []

    #find the best place to build scrapper (most neibs)
    dicNeibFromTile = getTileNeighbors(my_tiles)
    bestNeibCount = -1
    for tile in my_tiles:
        if dicNeibFromTile[(tile.x, tile.y)] > bestNeibCount:
            bestNeibCount = dicNeibFromTile[(tile.x, tile.y)]
            bestTile = tile

    #find closest tile to spawn robot
    battlefront = getTileBattleFront(opp_units, my_tiles)

    for tile in my_tiles:
        if tile.can_spawn:
            amount = 0 # TODO: pick amount of robots to spawn here
            if battlefront:
                if tile.x == battlefront.x and tile.y == battlefront.y:
                    amount = 1
            if amount > 0:
                actions.append('SPAWN {} {} {}'.format(amount, tile.x, tile.y))
        if tile.can_build:
            if bestNeibCount > 0:
                should_build = (tile == bestTile) # TODO: pick whether to build recycler here
            else:
                should_build = False
            if should_build:
                actions.append('BUILD {} {}'.format(tile.x, tile.y))

    #find where the opp unit are
    dicUnitOppFromTile = getUnitOpp(opp_units)
    targets = list()
    for tile in opp_units:
        targets.append(tile)
    targets.sort(key=lambda x: x.units, reverse=True)
    #st = ''
    #for tile in targets:
    #    st += '(' + str(tile.x) + ', ' + str(tile.y) + ') '
    #actions.append('MESSAGE ' + st)

    # find targeted location (neutral or opp)
    targetedTiles = opp_tiles.copy()
    targetedTiles += neutral_tiles

    st = ''
    for tile in targetedTiles:
        st += '(' + str(tile.x) + ', ' + str(tile.y) + ') '
    #actions.append('MESSAGE ' + st)


    # move units
    for tile in my_units:
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
