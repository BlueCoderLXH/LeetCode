/*
    算法1: 时间复杂度O(nlogn), 空间复杂度O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // 先排序

		int i = 0;
		while (i < (int)nums.size())
		{
			if (nums[i] == nums[i + 1]) // 出现两次的元素必定相邻
			{
				i += 2;
			}
			else                        // 相邻元素不等则是single number
			{
				break;
			}
		}

		return nums[i];
    }
};

/*
    算法2: 时间复杂度O(n), 空间复杂度O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int res = 0;
		
		/*
		    注意nums序列的规律: 仅有1个元素出现1次, 其余元素都出现2次.
		可想而知, 当不考虑只出现1次的元素key时, 我们只对出现2次的元素依次采用位异或操作,
		最终的结果是什么?是0.
		    然后0与key再做1次异或操作, 结果还是key.
			(异或: 相同为0, 不同为1)
		*/
		for (int i = 0; i < (int)nums.size(); i++)
		{
			res = res ^ nums[i];
		}

		return res;
    }
};
