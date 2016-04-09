class Solution {
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int index = (int)digits.size() - 1;
		int carry = 1; // 进位(默认为1)

		// 逐位进位
		while (index >= 0)
		{
			digits[index] = digits[index] + carry;

			// 超过9, 置0, 进位置1
			if (digits[index] > 9)
			{
				digits[index] = 0;
				carry = 1;
			}
			else// 否则进位置0
			{
				carry = 0;
			}

			index--;
		}

		// 还需要进位(每一位数字都是9的情况)
		if (carry == 1)
		{
		    digits.push_back(0); // 末尾添加一个0
			digits[0] = 1;       // 首位置1
		}

		return digits;
	}
};
