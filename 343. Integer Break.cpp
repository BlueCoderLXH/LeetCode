/*
    算法简述：数论问题, 当n大于4时, 划分为尽可能多的3, 这样就能保证乘积最大;
                        当n小于等于4时, 按特殊情况处理
    算法时间复杂度：O(n), 空间复杂度：O(1)
*/
class Solution {
public:
	int integerBreak(int n) {
		if (n == 2)
		{
			return 1;
		}

		if (n == 3)
		{
			return 2;
		}

		int product = 1;
	
		while (n > 4)
		{
			product *= 3;
			n -= 3;
		}

		product *= n;

		return product;
	}
};
