#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    handler_t handlers[] = {
        {'c', handle_char},
        {'s', handle_string},
        {'%', handle_percent},
        {'d', handle_int},
        {'i', handle_int},
        {'\0', NULL}  // End of array marker
    };

    char* buffer = malloc(1024 * sizeof(char));
    if (buffer == NULL) {
        return -1;
    }

    int count = 0;
    for (const char *p = format; *p != '\0'; p++) {
        if (*p != '%') {
            buffer[count++] = *p;
            continue;
        }

        p++;

        for (handler_t *h = handlers; h->specifier != '\0'; h++) {
            if (h->specifier == *p) {
                h->handler(args, &buffer, &count);
                break;
            }
        }
    }

    write(1, buffer, count);
    free(buffer);

    va_end(args);
    return count;
}
