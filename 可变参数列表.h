/* my_printf 函数*/

void my_printf(char* str, ...)
{
	va_list arg;
	va_start(arg, str);
	while (*str)
	{
		switch (*str)
		{
		case 'c':
			putchar(va_arg(arg, char));      //output char
			break;
		case 's':
			puts(va_arg(arg, char*));        //output string
			break;
		default:
			putchar(*str);
			break;
		}
		str++;
	}
	va_end(arg);
}

void main()
{
	char arr[] = "Hello";
	char* ptr = "Bit";
	my_printf("ccccc s", arr[0], arr[1], arr[2], arr[3], arr[4], ptr);
}