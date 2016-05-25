class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;

		sort(nums.begin(), nums.end());            // 先排序(O(nlogn))

		int i = 0;
		int n = (int)nums.size();
		while (i < n)
		{
			if (i < n-1 && nums[i] == nums[i + 1]) // 重复出现两次的元素必定相邻
			{
				i += 2;
			}
			else                                   // 否则是single number
			{
				res.push_back(nums[i]);

				if (res.size() == 1)               // 只找到第一个, 继续找第二个
				{
					i++;
				}
				else                               // 两个都找到, 返回
				{
					break;
				}
			}
		}

		return res; 
    }
};
