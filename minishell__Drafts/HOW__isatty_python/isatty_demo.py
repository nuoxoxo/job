import sys


yell = '\033[33m'
noc = '\033[0m'
sep = '\n-\n'

print(yell + 'Stuff to do:')
print('0 - dry run')
print('1 - do: p3 demo.py > /dev/null')
print('2 - do: p3 demo.py > outfile && cat outfile')
print('3 - do: p3 demo.py > outfile 2> errfile')
print('4 - uncomment the input session and do: echo "hellooo" | p3 demo.py')
print('5 - do: p3 demo.py | cat')
print('6 - do: p3 demo.py |& cat', noc)

print(sep)

print('sys.stderr.isatty() =', sys.stderr.isatty())
print('sys.stdout.isatty() =', sys.stdout.isatty())
print('sys.stdin.isatty() =', sys.stdin.isatty())

print()
print('stdout says hi', file=sys.stdout)
print('stderr says hi', file=sys.stderr)
# print(f'received input ::: {input("type something ::: ")}')


print(sep)

"""
print(f'{sys.stderr.isatty() = }')
print(f'{sys.stdout.isatty() = }')
print(f'{sys.stdin.isatty() = }')
"""

print(yell + 'Definition: ')
print('\t*isatty \ncheck if a stream is connected to an interactive terminal')
print('\t*isatty=False \nstream is not connected to an interactive terminal')
print('\t*an interactive terminal / shell\nis any shell process that you use to feed commands and get outputs. ie. a terminal or a shell that we interact with')
print(noc)
