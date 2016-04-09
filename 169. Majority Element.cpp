class Solution {
public:
    int majorityElement(vector<int>& nums) {
		// 先排序
		sort(nums.begin(), nums.end());

		int n = (int)nums.size();
		int numCount = 1;         // 重复数统计

		int i = 0;
		for (; i < n - 1; i++)
		{
			if (nums[i] == nums[i + 1])
			{
				numCount++;
			}
			else
			{
				numCount = 1;
			}

			if (numCount > n/2)
			{
				break;
			}
		}

		return nums[i];
    }
};
