
#include <bsd\string.h>
#include <stdio.h>

int     main(void)
{
        char    src[] = "batatas";
        char    dest[] = "ceboulas";

        printf("%i \n", strlcat(dest, src, 20));
        printf("%s \n", dest);
}

