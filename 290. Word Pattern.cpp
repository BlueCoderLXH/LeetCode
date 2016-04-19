class Solution {
public:
	// 分割字符串(以空格分割) - c++没有此功能的库函数, 就自己写一个
	vector<string> splitString(string str) {
		vector<string> splitStrs;
		int len = (int)str.length();

		int start(0); // 每一个分割字符串在str中的起始下标
		int end(0);   // 每一个分割字符串在str中的终止下标

		while (end < len)
		{
			// 找到每一个分割字符串的起始下标
			while (start < len && str[start] == ' ') start++;

			if (start >= len)
			{
				break;
			}

			end = start;
			// 找到每一个分割字符串的终止下标
			while (end < len && str[end] != ' ') end++;

			splitStrs.push_back(str.substr(start, end - start));

			end++;
			start = end;
		}

		return splitStrs;
	}

	bool charMapToString(string pattern, vector<string> vecStr) {
		// char到string的映射
		map<char, string> strMap;
		
		for (int i = 0; i < (int)pattern.length(); i++)
		{
			if (strMap.find(pattern[i]) == strMap.end())
			{
				// 插入新映射
				strMap.insert(pair<char, string>(pattern[i], vecStr[i]));
			}
			else
			{
				// 映射不等
				if (strMap[pattern[i]] != vecStr[i])
				{
					return false;
				}
			}
		}

		return true;
	}

	bool stringMapToChar(vector<string> vecStr, string pattern) {
		// string到char的映射
		map<string, char> strMap;

		for (int i = 0; i < (int)vecStr.size(); i++)
		{
			if (strMap.find(vecStr[i]) == strMap.end())
			{
				// 插入新映射
				strMap.insert(pair<string, char>(vecStr[i], pattern[i]));
			}
			else
			{
				// 映射不等
				if (strMap[vecStr[i]] != pattern[i])
				{
					return false;
				}
			}
		}

		return true;
	}

	bool wordPattern(string pattern, string str) {
		if (str.empty())
		{
			return false;
		}

		vector<string> vecStr = splitString(str);

		// 长度不等必不是
		if (pattern.length() != vecStr.size())
		{
			return false;
		}

		// 判断双射
		return charMapToString(pattern, vecStr) &&
			stringMapToChar(vecStr, pattern);
	}
};
