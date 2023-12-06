import math
import re


# Global
GreenB  = '\033[1;32;40m'
Green   = '\033[0;32;40m'
Yello   = '\033[0;33;40m'
Cyan    = '\033[0;36;40m'
Red     = "\033[0;31;40m"
Lowkey  = "\033[0;2m"
# Reset   = '\033[0m' 
Reset   = '\033[0;0m'
Linebreak = '\n-\n'
FormulaF = 'raw bits \n' + Green + 'applied:' + Yello + ' n * (1 << 8) (for float)' + Reset
FormulaI = 'raw bits \n' + Green + 'applied:' + Yello + ' n << 8 (for int)' + Reset
toFloat  = 'toFloat() \n'  + Green + 'applied:' + Yello + ' m / (1 << 8) ' + Reset
toInt    = 'toInt()\n' + Green + 'applied:' + Yello + ' m >> 8 ' + Reset


# Fpv printer
def fpv(n) -> None:
    
    # Print what we are testing & its type
    print(f'{GreenB}TESTING:{Yello} {n} {Reset} ')
    print(f'{Cyan}type   {Reset}: {str(type(n))[8:-2]} {Reset} ')

    # case Float, use algo `n * (1 << 8)`
    if type(n) is float:
        # print(f'{Cyan}binary {Reset}:{Red} no binary representation for non-int{Reset}')
        print(f'{Cyan}binary {Reset}:')
        m = n * (1 << 8)
        m = round(m)
        bin_num = format(m, '{}_b'.format(4))
        
        print(FormulaF)
        print(f'{Cyan}result {Reset}: {m} {Red}round() applied for float {n} {Reset}')
        print(f'{Cyan}binary {Reset}: {bin_num} ')
        
        print(toInt)
        print(f'{Cyan}result {Reset}: {m >> 8} ')
        
        print(toFloat)
        print(f'{Cyan}result {Reset}: {m / (1 << 8)} ')
    # case Int, applied algo `n << 8`
    if type(n) is int:
        
        bin_num = format(n, '0{}_b'.format(4))
        print(f'{Cyan}binary {Reset}: {bin_num}')
        m = n << 8
        bin_num = format(m, '{}_b'.format(4))
        
        print(FormulaI)
        print(f'{Cyan}result : {m}')
        print(f'{Cyan}binary {Reset}: {bin_num} ')
        
        print(toInt)
        print(f'{Cyan}result {Reset}: {m >> 8} ')
        
        print(toFloat)
        print(f'{Cyan}result {Reset}: {m // (1 << 8)} ')
    print(Linebreak)


# Default tests
fpv(42)
fpv(1)
fpv(333)
fpv(math.pi)
fpv(196883)
fpv(math.tau)
fpv(123.4567)


# Test your own input
print("Test your own input:" )
infile = ''
while (True):
    infile = input().strip()
    if not re.findall('^[0-9\.]+$', infile):
        break
    res = int(infile) if '.' not in infile else float(infile)
    fpv(res)






