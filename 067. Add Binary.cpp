class Solution {
public:
    string addBinary(string a, string b) {
		string result = "";

		int i = (int)a.length() - 1;
		int j = (int)b.length() - 1;
		int carry = 0; // 进位标记

		while (i > -1 || j > -1)
		{
			int digit = 0;
			if (i > -1)
			{
				digit += a[i] - '0';
			}
			
			if (j > -1)
			{
				digit += b[j] - '0';
			}
			
			digit += carry;

			// 重新计算进位
			carry = digit / 2;
			digit = digit % 2;

			// 加入新计算的位
			result = to_string(digit) + result;

			i--;
			j--;
		}

		// 如果还存在进位, 首部加一个1
		if (carry)
		{
			result = to_string(1) + result;
		}

		return result;
    }
};
