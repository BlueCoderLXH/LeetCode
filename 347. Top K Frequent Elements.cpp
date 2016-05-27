/*
    算法思路：基于桶排序思想, 先用一个elementCountMap统计每一个不同元素出现的次数, 以元素值为key,
元素出现次数为value, 相当于一个桶. 再用一个countElementMap, 以元素出现次数为key, 元素值为value. 
countElementMap中按照元素出现次数排序(默认是升序), 然后从后往前遍历countElementMap, 遍历k次就得到
top-k元素.
    时间复杂度：O(nlogk)
    n为初始数组元素的个数, k为不同元素的个数, 显然k<n. 于是O(nlogk) < O(nlogn), 满足题目要求.
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
