/*
    时间复杂度: O(nlogk)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		map<int, int> elementCountMap;      // key = element, value = count
		multimap<int, int> countElementMap; // key = count, value = element

		// 先求elementCountMap(O(nlogk))
		for (int i = 0; i < (int)nums.size(); i++)
		{
			map<int, int>::iterator item = elementCountMap.find(nums[i]);
			if (item == elementCountMap.end())
			{
				elementCountMap.insert(pair<int, int>(nums[i], 1));
			}
			else
			{
				item->second += 1;
			}
		}

		// 再求countElementMap(O(klogk))
		for (auto item : elementCountMap)
		{
			countElementMap.insert(pair<int, int>(item.second, item.first));
		}

		res.resize(k);
		multimap<int, int>::reverse_iterator item = countElementMap.rbegin();
		// 求top-k元素(O(k))
		for (int i = 0; i < k; item++, i++)
		{
			res[i] = item->second;
		}

		return res;
    }
};
