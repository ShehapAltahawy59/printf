#include "main.h"

/**
 * handle_char - print the char
 * @args:arguments
 * @buffer: buffer hold string
 * @count: num of char printed
 * Return:void
 */
void handle_char(va_list args, char **buffer, int *count)
{
	char c = va_arg(args, int);
	(*buffer)[(*count)++] = c;
}

/**
 * handle_string - print the string
 * @args:arguments
 * @buffer: buffer hold string
 * @count: num of char printed
 * Return:void
 */
void handle_string(va_list args, char **buffer, int *count)
{
	char *s = va_arg(args, char *);
	char *sp;

	for (sp = s; *sp != '\0'; sp++)
	{
		(*buffer)[(*count)++] = *sp;
	}
}

/**
 * handle_percent - print the %
 * @args:arguments
 * @buffer: buffer hold string
 * @count: num of char printed
 * Return:void
 */
void handle_percent(va_list args, char **buffer, int *count)
{
	(void)args;

	(*buffer)[(*count)++] = '%';
}

/**
 * itoa - convert int to string
 * @value:the number
 * @str:the string
 * Return:void
 */
void itoa(int value, char *str)
{
	char *start = str;
	int is_negative = 0;
	char temp;

	if (value < 0)
	{
		is_negative = 1;
		value = -value;
	}
	do {
		*str++ = '0' + (value % 10);
		value /= 10;
	} while (value != 0);
	if (is_negative)
	{
		*str++ = '-';
	}
	*str-- = '\0';
	while (start < str)
	{
		temp = *start;
		*start++ = *str;
		*str-- = temp;
	}
}
/**
 * handle_int - print the num
 * @args:arguments
 * @buffer: buffer hold string
 * @count: num of char printed
 * Return:void
 */
void handle_int(va_list args, char **buffer, int *count)
{
	int value = va_arg(args, int);
	char str[12];
	char *sp;

	itoa(value, str);
	for (sp = str; *sp != '\0'; sp++)
	{
		(*buffer)[(*count)++] = *sp;
	}
}

