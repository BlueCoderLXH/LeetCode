class Solution {
public:
	string countAndSay(int n) {
		string curNumStr("1"), nextNumStr("1");
		int  numCount; // 当前连续重复数字的统计
		char num;      // 当前连续重复的数字

		int i(1);
		while (i < n)
		{
			nextNumStr.clear();

			num = curNumStr[0];
			numCount = 0;
			// 根据当前数字串求下一个数字串
			for (int j = 0; j < (int)curNumStr.length(); j++)
			{
				// 相等, 统计+1
				if (curNumStr[j] == num)
				{
					numCount++;
				}
				else // 不等
				{
					// 加入已经统计的数字串("num连续重复次数" + "num")
					nextNumStr.append(to_string(numCount) + to_string(num - '0'));

					numCount = 1;
					num = curNumStr[j];
				}
			}

			// 加入末尾的数字串
			nextNumStr.append(to_string(numCount) + to_string(num - '0'));

			// 继续求下一个数字串
			curNumStr = nextNumStr;

			i++;
		}

		return nextNumStr;
	}
};
