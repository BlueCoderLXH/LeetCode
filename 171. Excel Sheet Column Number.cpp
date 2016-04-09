class Solution {
public:
    // 计算次方
	int pow(int num, int n)
	{
		int ret = 1;
		while (n)
		{
			ret *= num;
			n--;
		}

		return ret;
	}

	int titleToNumber(string s)
	{
	    // 26进制数的问题
		int len = (int)s.length();
		int result = 0;

		int i = 0;
		while (i < len)
		{
			int power = len - i - 1;
			int num = s[i] - 'A' + 1;

			result += pow(26, power) * num;

			i++;
		}

		return result;
	}
};
