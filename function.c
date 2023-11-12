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

	if (s == NULL)
	{
		s = "(null)";
	}
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
void itoa(int value, char* str)
{
	unsigned int n;
	
	if (value < 0)
	{
		*str++ = '-';
		n = -value;
	}
	else
	{
		n = value;
	}

	char* p = str;
	do {
		*p++ = '0' + (n % 10);
		n /= 10;
	} while (n != 0);

	*p-- = '\0';
	while (str < p)
	{
		char temp = *str;
		*str++ = *p;
		*p-- = temp;
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

