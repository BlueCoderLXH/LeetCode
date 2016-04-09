class Solution {
public:
	/*
		先排序，然后比较相邻的数是否相同

		时间复杂度O(N lg N)，主要花在排序上
	*/
	bool containsDuplicate(vector<int>& nums)
	{
		// 排序
		sort(nums.begin(), nums.end());

		int len = (int)nums.size();
		for (int i = 0; i < len - 1; i++)
		{
			// 比较相邻的数是否相同
			if (nums[i] == nums[i + 1])
			{
				return true;
			}
		}

		return false;
	}
};
