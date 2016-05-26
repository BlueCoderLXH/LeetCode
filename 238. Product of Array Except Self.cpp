/*
    算法1: O(n), 用了除法, 需要考虑特殊情况0
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> output;
		output.resize(nums.size());

		int allProduct = 1; // 非0元素乘积
		int zeroCount = 0;  // 0个数标记

		// 先计算所有元素的乘积
		for (auto item : nums)
		{
			if (item)
			{
				allProduct *= item;
			}
			else
			{
				zeroCount++;
			}
		}

		// 然后除去nums[i]
		for (int i = 0; i < (int)nums.size(); i++)
		{
			if (nums[i]) // nums[i]非0
			{
				if (zeroCount > 0) // nums中有0, 那么output[i]为0
				{
					output[i] = 0;
				}
				else               // nums中没有0
				{
					output[i] = allProduct / nums[i];
				}
			}
			else         // nums[i]为0
			{
				if (zeroCount > 1) // nums中0个数大于1
				{
					output[i] = 0;
				}
				else               // nums中只有nums[i]这1个0
				{
					output[i] = allProduct;
				}

			}
		}

		return output;     
    }
};

/*
    算法2: O(n)
*/
class Solution {
public:
	/*
	 i\j 1  2  3  4
	 --------------
	 1|  *  1  1  1
	 2|  2  *  2  2
	 3|  3  3  *  3
	 4|  4  4  4  *
	*/
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> output;
		output.resize(nums.size(), 1);

		int right_upper = 1; // 右上角(*以上)
		int left_lower = 1;  // 左下角(*以下)
		for (int i = 0, j = nums.size() - 1; i < (int)nums.size() - 1; i++, j--)
		{
			right_upper *= nums[i];
			left_lower  *= nums[j];

			output[i + 1] *= right_upper;
			output[j - 1] *= left_lower;
		}

		return output;
    }
};
