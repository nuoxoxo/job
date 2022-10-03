

#include "unistd.h"
#include "stdint.h"

int     main()
{
        uint8_t count = 100;

        ++count;
        while (--count)
        {
                if (count < 100 && count > 9)
                {
                        int     t = count / 10 + 48;
                        int     u = count % 10 + 48;
                        write(1, &t, 1);
                        write(1, &u, 1);
                }
                else
                {
                        int     c = count + 48;
                        write(1, &c, 1);
                }
                int     nl = 10;
                write(1, &nl, 1);
        }
        return (0);
}

/*
#include "stdio.h"
#include "stdint.h"

int     main()
{
        int     count = 6;
        while (--count)
        {
                printf("%d\n", count);
        }
        return (0);
}
*/
