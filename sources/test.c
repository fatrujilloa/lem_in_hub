#include <stdio.h>

int         main()
{
    int     g[][3] = {{1, 2, -1}, {0, -1}};
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 2)
    {
        j = 0;
        while (g[i][j] != -1)
            printf("%d ", g[i][j++]);
        i++;
        printf("\n");
    }
    return (0);
}