#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*handler_func)(va_list args, char** buffer, int* count);

typedef struct {
    char specifier;
    handler_func handler;
} handler_t;

void handle_char(va_list args, char** buffer, int* count);
void handle_string(va_list args, char** buffer, int* count);
void handle_percent(va_list args, char** buffer, int* count);
void itoa(int value, char* str);
void handle_int(va_list args, char** buffer, int* count);
handler_t* create_handlers();
int _printf(const char *format, ...);
#endif
