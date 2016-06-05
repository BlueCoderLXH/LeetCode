/*
     算法简述：先求得所有元素的和sum, 然后求nums中所有元素的和realSum, 两个之差就是missing number
     算法时间复杂度：O(n), 空间复杂度：O(1)
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = (int)nums.size();
		int sum = (1 + n) * n / 2;
		int realSum = 0;

		for (int i = 0; i < n; i++)
		{
			realSum += nums[i];
		}

		return sum - realSum;
	}
};
