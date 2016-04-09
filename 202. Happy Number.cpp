class Solution {
public:
    // 求各位数的平方和
	int squareDigits(int num)
	{
		int result = 0;
		while (num)
		{
			int digit = num % 10;
			result += digit * digit;

			num /= 10;
		}

		return result;
	}

	bool isHappy(int n)
	{
	    // 非正数, 必定不是
		if (n <= 0)
		{
			return false;
		}

		map<int, int> retMap; // 存储结果集(判断结果是否发生循环)
		bool flag = true;

		int ret = n;
		retMap.insert(pair<int, int>(n, n));
	
		while ((ret = squareDigits(ret)) != 1)
		{
		    // 找相同结果(之前出现过), 则出现了循环
			if (retMap.find(ret) != retMap.end())
			{
				flag = false;
				break;
			}
			// 否则插入新的结果
			else
			{
				retMap.insert(pair<int, int>(ret, ret));
			}
		}

		return flag;
	}
};
