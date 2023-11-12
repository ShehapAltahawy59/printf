#include "main.h"
void handle_char(va_list args, char** buffer, int* count) {
    char c = va_arg(args, int);
    (*buffer)[(*count)++] = c;
}

void handle_string(va_list args, char** buffer, int* count) {
    char *s = va_arg(args, char *);
    for (char *sp = s; *sp != '\0'; sp++) {
        (*buffer)[(*count)++] = *sp;
    }
}

void handle_percent(va_list args, char** buffer, int* count) {
    (*buffer)[(*count)++] = '%';
}

void itoa(int value, char* str) {
    char* start = str;
    int is_negative = 0;
    if (value < 0) {
        is_negative = 1;
        value = -value;
    }
    do {
        *str++ = '0' + (value % 10);
        value /= 10;
    } while (value != 0);
    if (is_negative) {
        *str++ = '-';
    }
    *str-- = '\0';
    while (start < str) {
        char temp = *start;
        *start++ = *str;
        *str-- = temp;
    }
}

void handle_int(va_list args, char** buffer, int* count) {
    int value = va_arg(args, int);
    char str[12];  // Buffer to hold the string representation of the integer
    itoa(value, str);
    for (char *sp = str; *sp != '\0'; sp++) {
        (*buffer)[(*count)++] = *sp;
    }
}

