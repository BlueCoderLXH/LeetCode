class Solution {
public:
	int basicRoman(char ch)
	{
		switch (ch)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		}

		return -1;
	}

	int romanToInt(string s)
	{
		int integer = 0;

		for (int i = 0; i < (int)s.length();)
		{
			int num = basicRoman(s[i]);
			int next = basicRoman(s[i + 1]);

			if (num >= next)
			{
				integer += num;
				i++;
			}
			else
			{
				integer += next - num;
				i += 2;
			}
		}

		return integer;
	}
};
