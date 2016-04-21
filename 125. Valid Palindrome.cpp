class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = (int)s.length() - 1;

		while (left < right)
		{
			while (left < right && !isalnum(s[left])) left++;
			while (left < right && !isalnum(s[right])) right--;

			if (left >= right)
			{
				break;
			}

			// 不等
			if (s[left] != s[right])
			{
				// 不全是字母
				if (!isalpha(s[left]) || !isalpha(s[right]))
				{
					return false;
				}

				// 不区分大小写
				if (fabs(s[left] - s[right] * 1.0f) != ('a' - 'A'))
				{
					return false;
				}
			}

			left++;
			right--;
		}

		return true;
	}
};
