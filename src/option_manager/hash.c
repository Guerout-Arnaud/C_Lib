#include <stddef.h>

unsigned int hash (const unsigned char *const key, const size_t length)
{
    unsigned int hash = 0;

    if (length > 16843009)
        return 0;

    for (size_t i = 0; i < length; i++)
        hash = hash + key[i];
    return hash;
}
