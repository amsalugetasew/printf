/**
 * print_unsigned - Return Unsigned numbers
 * @type: fisrt input
 * @buffer: second input
 * @flags: third input
 * @width: fourth input
 * @precision: fifth input
 * @size: sixth input
 * Return: Always (Success)
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - Return an unsigned number in octal
 * @type: fisrt input
 * @buffer: second input
 * @flags: third input
 * @width: fourth input
 * @precision: fifth input
 * @size: sixth input
 * Return: Always (Success)
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i, BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 8];
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexa_decimal_upper - Return an unsigned number in upper hexa decimal
 * @type: fisrt input
 * @buffer: second input
 * @flags: third input
 * @width: fourth input
 * @precision: fifth input
 * @size: sixth input
 * Return: Always (Success)
 */
int print_hexa_decimal_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa_decimal(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}
/**
 * print_hexa_decimal_lower - Return an unsigned number in lower hexa d
ecimal
 * @type: fisrt input
 * @buffer: second input
 * @flags: third input
 * @width: fourth input
 * @precision: fifth input
 * @size: sixth input
 * Return: Always (Success)
 */
int print_hexa_decimal_lower(va_list types, char buffer[], int flags, int width, int precision, int size)
{
        return (print_hexa_decimal(types, "0123456789abcdef", buffer, flags, 'X', width, precision, size));
}
/**
 * print_hexa_decimal - Return an unsigned number in hexa decimal
 * @type: 1st input
 * @map_to: 2nd input
 * @buffer: 3rd input
 * @flags: 4th input
 * @flag_ch: 5th input
 * @width: 6th input
 * @precision: 7th input
 * @size: 8th input
 * Return: Always (Success)
 */
int print_hexa_decimal(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
        int i, BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

        UNUSED(width);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
        {
                buffer[i--] = '0';
        }
        buffer[BUFF_SIZE - 1] = '\0';
        while (num > 0)
        {
                buffer[i--] = map_to[num % 16];
                num /= 16;
        }
        if (flags & F_HASH && init_num != 0)
        {
                buffer[i--] = flag_ch;
                buffer[i--] = '0';
        }
        i++;
        return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
