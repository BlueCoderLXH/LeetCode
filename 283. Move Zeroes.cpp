class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int zeroCount = 0;
		int size = (int)nums.size();

		// 移动非零数到最左边
		for (int i = 0; i < size; i++)
		{
			if (nums[i] == 0)
			{
				zeroCount++;
			}
			else
			{
				nums[i - zeroCount] = nums[i];
			}
		}

		// 零复制到最右边
		for (int i = size - 1; i >= size - zeroCount; i--)
		{
			nums[i] = 0;
		}

    }
};
