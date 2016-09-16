enum status
{
	_TRUE,
	_FALSE
};
status sta = _TRUE;


long long strToIntCode(char* str, bool signal)
{
	long long num = 0;
	while (*str <= '9' && *str >= '0')
	{
		num *= 10;
		num += (*str - '0');
		if ((signal && num > 0x80000000) || (!signal && num > 0x7fffffff))
		{
			num = 0;
			break;
		}
		str++;
	}
	if (*str == '\0')
	{
		return signal ? -num : num;
	}
	else
	{
		sta = _FALSE;
		return 0;
	}

}
int strToInt(char* str)
{
	if (str == NULL || *str == '\0')
	{
		sta = _FALSE;
		return 0; 
	}
	else
	{
		long long num = 0;
		bool signal = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			signal = true;
			str++;
		}
		num = strToIntCode(str, signal);
		return (int)num;
	}
}