/*
    算法时间复杂度O(n), 空间复杂度O(n)
*/
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result;

		result.push_back(0); // 预先保存countBits(0)
		if (num == 0)
		{
			return result;
		}

		result.push_back(1); // 预先保存countBits(1)
		if (num == 1)
		{
			return result;
		}

		/*
		    注意两个规律:
			(1)对于一个非负整数i, 必然存在一个非负整数k, 使得i∈[2^k, 2^(k+1))
			(2)countBits(2^k) = 1

		    设m = i - 2^k, 当求countBits(i)时, 之前countBits(m)已经求得, 因此可以
		简单利用之前求得值来计算当前的countBits(i), 显然有以下结论:
		                  countBits(i) = countBits(m) + 1
		*/
		for (int i = 2; 1; i *= 2)
		{
			result.push_back(1); // countBits(2^k) = 1

			int j = i + 1;
			while (j <= num && j < i*2)
			{
				int m = j - i;
				result.push_back(result[m] + 1); // countBits(i) = countBits(m) + 1
				j++;
			}

			if (j > num) break;
		}

		return result;
	}
};
