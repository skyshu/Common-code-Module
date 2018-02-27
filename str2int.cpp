void str2int(string str, int &val)
{
	val = 0;
	static string digits("0123456789");
	for (size_t i = 0; i < str.size(); i++)
	{
		for (size_t j = 0; j < digits.size(); j++)
		{
			if (str[i] == digits[j])
			{
				val *= 10;
				val += j;
			}
		}
	}
}

