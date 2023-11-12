#include "main.h"

/**
 * create_handlers - create handlers
 * Return:handlers
 */
handler_t *create_handlers(void)
{
	static handler_t handlers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'%', handle_percent},
		{'d', handle_int},
		{'i', handle_int},
		{'\0', NULL}
	};
	return (handlers);
}

/**
 * _printf - print
 * @format:the string
 * Return:number of printed char
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count, i;
	char *buffer;
	const char *p = format;
	handler_t *h;
	handler_t *handlers;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	handlers = create_handlers();
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
	{
		return (-1);
	}
	count = 0;
	for (; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			buffer[count++] = *p;
			continue;
		}
		p++;

		if (*p == '\0')
		{
			count--;
			break;
		}
		for (h = handlers; h->specifier != '\0'; h++)
		{
			if (h->specifier == *p)
			{
				h->handler(args, &buffer, &count);
				break;
			}
		}
		if (h->specifier == '\0')
		{
			buffer[count++] = '%';
			buffer[count++] = *p;
		}
	}
	for (i = 0; i < count; i++)
	{
		_putchar(buffer[i]);
	}
	free(buffer);
	va_end(args);
	return (count);
}
