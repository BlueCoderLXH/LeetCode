class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		vector<int> tempNums;
		int n = (int)nums.size();
		tempNums.resize(n);
		
		// k是n的倍数时, 等同于不需要移位
		if (k % n == 0)
			return;
		
		// 循环移位
		for (int i = 0; i < n; i++)
		{
			int index = (i + k) % n;
			tempNums[index] = nums[i];
		}

		nums = tempNums;
    }
};
