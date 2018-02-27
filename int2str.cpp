void int2str(int val, string &str)
{
	static string digits("9876543210123456789");
	char buf[6], *p = buf;
	int i = val;
	do {
		int loc = i % 10;
		i /= 10;
		*p++ = digits[loc + 9];
	} while (i != 0);
	if (val<0)
		*p++ = '-';
	*p = '\0';
	std::reverse(buf, p);
	str = buf;
}