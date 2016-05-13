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

/*
    算法3：对算法2用multimap实现的更优雅的code
    注意：使用multimap的原因是，有可能nums存在重复的元素
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		multimap<int, int> numsMap;

		for (int i = 0; i < (int)nums.size(); i++)
		{
			numsMap.insert(pair<int, int>(nums[i], i));
		}

		// 两头索引遍历
		multimap<int, int>::iterator left = numsMap.begin();
		multimap<int, int>::iterator right = numsMap.find((*numsMap.rbegin()).first);
		while (true)
		{
			int sum = (*left).first + (*right).first;
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
		res.push_back((*left).second);
		res.push_back((*right).second);

		return res;
    }
};

/*
    算法4：用map记录每一次遍历的结果, 当再次遍历新元素时, 先查看map中知否已包含已有结果
    时间复杂度：O(nlogn)
    注：map中find的时间复杂度为O(logn)
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> numsMap;

		for (int i = 0; i < (int)nums.size(); i++)
		{
			int second = target - nums[i]; // 另一个元素值
			map<int, int>::iterator secondIte = numsMap.find(second);

			// map表中存在second元素, 即找到对应结果
			if (secondIte != numsMap.end())
			{
				res.push_back((*secondIte).second);
				res.push_back(i);
				break;
			}

			// map表中不存在second元素, 插入当前元素nums[i[]及其下标索引i
			numsMap.insert(pair<int, int>(nums[i], i));
		}

		return res;
	}
};
