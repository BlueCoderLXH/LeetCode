class Solution {
public:
    int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // 先排序(O(nlogn))

		int i = 0;
		while (i < (int)nums.size() - 1)
		{
			if (nums[i] == nums[i + 1]) // 出现三次的元素必定相邻
			{
				i += 3;
			}
			else                        // 否则就是single number
			{
				break;
			}
		}

		return nums[i];
    }
};
