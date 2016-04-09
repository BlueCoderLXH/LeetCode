class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int size = (int)nums.size();

		int i = 0;
		while (i < size)
		{
			// 相等
			if (nums[i] == val)
			{
				// 将等于val的元素与序列的最后一个交换
				int temp = nums[i];
				nums[i] = nums[size - 1];
				nums[size - 1] = temp;

				// 删除最后一个元素(即等于val的元素)
				nums.pop_back();

				// 删除后需要重新获取序列长度
				size = (int)nums.size();
			}
			// 不等, 则指向下一个
			else
			{
				i++;
			}
		}

		return size;
    }
};
