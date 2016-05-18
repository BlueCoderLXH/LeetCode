class Solution {
public:
	bool isInteger(char ch) {
		return ch >= '0' && ch <= '9';
	}

	int myAtoi(string str) {
		int result = 0;
		int i = 0;
		int signFlag = 1;

		// 首先去除空格字符, 并识别符号位和不合法的字符
		while (i < (int)str.length() && !isInteger(str[i]))
		{
			if (str[i] == ' ')
			{
				i++;
			}
			else if (str[i] == '+')
			{
				signFlag = 1;
				i++;
				break;
			}
			else if (str[i] ==  '-')
			{
				signFlag = -1;
				i++;
				break;
			}
			else
			{
				return 0;
			}
		}

		int upBorder = INT_MAX / 10;

		// 计算合法整数位
		while (i < (int)str.length())
		{
			if (isInteger(str[i]))
			{
			    int curBit = str[i] - '0';
			    
				// 处理溢出的特殊情况
				if (result > upBorder)
				{
					result = (signFlag == 1) ? INT_MAX : INT_MIN;
					return result;
				}
				else if (result == upBorder)
				{
					if (signFlag == 1 && curBit >= 7)
					{
						result = INT_MAX;
						return result;
					}
					else if (signFlag == -1 && curBit >= 8)
					{
						result = INT_MIN;
						return result;
					}
				}

				result *= 10;
				result += curBit;
			}
			else
			{
				break;
			}

			i++;
		}

		return result * signFlag;
	}
};
