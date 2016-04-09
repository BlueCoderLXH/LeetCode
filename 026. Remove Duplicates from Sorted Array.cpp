class Solution {
public:
	/*
		将nums中不同元素放在前i个位置, 然后将之后的(相同元素)删除,
	剩余的就是不同的元素集合
	*/
	int removeDuplicates(vector<int>& nums)
	{
		int size = (int)nums.size();
		int i = 0, j = 0;

		while (i < size)
		{
			int key = nums[j++];
			// 从左往右找出第一个不同的数
			while (j < size && nums[j] == key)
			{
				j++;
			}

			// 遍历完毕, 退出
			if (j >= size)
			{
				break;
			}

			i++;
			// 不同的数放在前i个位置
			nums[i] = nums[j];
		}

		// 将重复出现的数删除
		for (int k = i + 1; k < size; k++)
		{
			nums.pop_back();
		}

		return nums.size();
	}
};
