#include "main.h"
#include <errno.h>
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)

{
        size_t bufsize = 0;
        ssize_t n_read = getline(lineptr, &bufsize, stream);

        if (lineptr == NULL || n == NULL || stream == NULL)
        {
                errno = EINVAL; /* Invalid argument */
                return -1;
        }
        
        if (n_read == -1)
        {
               if (feof(stream))
                        errno = 0; /* Clear any previous errors caused by EOF */
                else
                        perror("getline");
        }

        return n_read;
}