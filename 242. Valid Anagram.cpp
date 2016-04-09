class Solution {
public:
    bool isAnagram(string s, string t) {
		// 长度不等必然不是
		if (s.length() != t.length())
		{
			return false;
		}

		// 字母重复次数的标记数组
		int sCount[26], tCount[26];

		// 初始化标记
		for (int i = 0; i < 26; i++)
		{
			sCount[i] = tCount[i] = 0;
		}

		// 统计S和T字符串中每一个字母出现的次数
		for (int i = 0; i < (int)s.length(); i++)
		{
			sCount[s[i] - 'a']++;

			tCount[t[i] - 'a']++;
		}

		// 查看每一个字母重复的次数是否相等
		for (int i = 0; i < 26; i++)
		{
			if (sCount[i] != tCount[i])
			{
				return false;
			}
		}

		return true;
    }
};
