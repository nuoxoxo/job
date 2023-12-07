class Cell(object):
    def __init__(self, r: int, c: int, sa: int, oship: int, u: int, \
                rcc: bool, canbd: bool, cansp: bool, inrange: bool):
        self.r = r
        self.c = c
        self.scrap_amount = sa
        self.ownership = oship
        self.units = u
    ### hello world
        self.recycler = rcc
        self.can_build = canbd
        self.can_spawn = cansp
        self.in_rc_range = inrange

cell = Cell(0, 0, 1024, 1, 42, True, True, False, False)
print(cell, end='\n\n')

c = vars(cell)
print(c, end='\n\n')

for cc in c.items():
    print(cc)
