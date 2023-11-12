#include "main.h"

handler_t* create_handlers() {
    static handler_t handlers[] = {
        {'c', handle_char},
        {'s', handle_string},
        {'%', handle_percent},
        {'d', handle_int},
        {'i', handle_int},
        {'\0', NULL}
    };
    return handlers;
}

int _printf(const char *format, ...) {
    va_list args;
    int count;
    char *buffer;
    const char *p = format;
    handler_t *h;
    handler_t *handlers;


    va_start(args,format);

    handlers = create_handlers();

    buffer = malloc(1024 * sizeof(char));
    if (buffer == NULL) {
        return -1;
    }
    count = 0;
    for (; *p != '\0'; p++) {
        if (*p != '%') {
            buffer[count++] = *p;
            continue;
        }

        p++;

        for (h = handlers; h->specifier != '\0'; h++) {
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
