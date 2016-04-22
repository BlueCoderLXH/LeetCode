class Solution {
public:
	int reverse(int x) {
		int revN = 0;
		int n = x;

		int upBorder = INT_MAX / 10;
		int downBorder = INT_MIN / 10;

		while (n)
		{
			revN *= 10;
			revN += n % 10;

			n /= 10;

			// 当有最后一位未逆序时, 判断是否溢出
			if ((n > 0 && n < 10) ||
				(n > -10 && n < 0))
			{
				if (revN >= upBorder || revN <= downBorder)
				{
					revN = 0;
					break;
				}
			}
		}

		return revN;
	}
};
