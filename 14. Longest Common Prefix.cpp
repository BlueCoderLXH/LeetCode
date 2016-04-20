class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
	    if(strs.size() == 0)
	    {
	        return "";
	    }
	    
		// 先排序
		sort(strs.begin(), strs.end());

		string prexStr = "";

		// 取最短的字符串的所有前缀串
		for (int i = (int)strs[0].length(); i > 0; i--)
		{
			prexStr = strs[0].substr(0, i);

			int j = 1;
			// 判断前缀串在其它字符串中是否存在
			for (; j < (int)strs.size(); j++)
			{
				if (strs[j].substr(0, i) != prexStr)
				{
					break;
				}
			}

			// 存在
			if (j >= (int)strs.size())
			{
				break;
			}
			else
			{
				prexStr = "";
			}
		}

		return prexStr;
	}
};
