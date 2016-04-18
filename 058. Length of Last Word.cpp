class Solution {
public:
    int lengthOfLastWord(string s) {
		int i = (int)s.length() - 1;
		int lastWordLen = 0;

		// 从右向左找到第一个不是空格的字符
		while (i >= 0 && s[i] == ' ')
		{
			i--;
		}

		// 统计最后一个单词的长度
		while (i >= 0 && s[i] != ' ')
		{
			lastWordLen++;
			i--;
		}

		return lastWordLen;
    }
};
