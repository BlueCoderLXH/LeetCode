/*
    算法1：简单的两层循环
    时间复杂度：O(n^2)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;

		for (int i = 0; i < (int)nums.size() - 1; i++)
		{
			for (int j = i + 1; j < (int)nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					res.push_back(i);
					res.push_back(j);
					break;
				}
			}

			if (!res.empty())
			{
				break;
			}
		}

		return res;    
    }
};

/*
    算法2：先排序，然后两头索引
    时间复杂度：O(nlogn)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		vector<int> sortNums = nums;

		// 先排序
		sort(sortNums.begin(), sortNums.end());

		// 两头索引遍历
		int left = 0, right = (int)sortNums.size() - 1;
		while (left < right)
		{
			int sum = sortNums[left] + sortNums[right];
			if (sum == target)      // 相等得到目标值
			{
				break;
			}
			else if (sum < target)  // 小于目标值, 则应该更大一点儿, 即left++
			{
				left++;
			}
			else                    // 大于目标值, 则应该更小一点儿, 即right--
			{
				right--;
			}
		}

		// 获取对应元素的索引下标
		int firstNum = sortNums[left];
		int secondNum = sortNums[right];
		for (int i = 0; i < (int)nums.size(); i++)
		{
			if (nums[i] == firstNum || nums[i] == secondNum)
			{
				res.push_back(i);

				if (res.size() == 2)
				{
					break;
				}
			}
		}

		return res;
    }
};
