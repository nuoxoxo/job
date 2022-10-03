```coffee
fetch
    - Dont check !bloc otherwise all lines turn out null
    - init buff[BU + 1], dont use malloc, thus no free if bytes == -1
    - while (bytes && !sch(bloc)), check sch(bloc), not sch(buff)
    - seal buff at the end of every loop:
        - buff[bytes] = 0
    bloc = paste_bloc(bloc, buff)

paste
    - check !bloc
        - if yes, malloc bloc to size of 1
    - len = Len(bloc) + Len(buff)
    - malloc len + 1 // FIXME
    - copy bloc
    - copy buff
    - seal: res[ i ] = 0
    - free(bloc), Important! bloc replaced by res for the 1st time // 0xhighlight

get_line
    - check !len(bloc)
        - if yes, return null ;
    - count i until \0 or \n
    - malloc i + 2 // FIXME
    - copy Bloc to Line until potential \n or \0
    - if end is a \n ie. 10, line[i] = bloc[i]
    - seal: line[++i] = 0

regen
    - count i until \0 or \n
    - if end is a \0
        - free(bloc), return null ;
    - size = len(bloc) - i, prepare size covering position \n + 1 to \0
    - malloc size + 1
        - ie. len(bloc) - i + 1
    - i++;
    - j=0;
    - copy bloc[i] to res[j]
    - seal: res[j] = 0
    - free(bloc), Important! replace bloc with res for the 2nd time around // 0xhighlight
```
