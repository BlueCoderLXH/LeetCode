class Solution {
public:
    string convertToTitle(int n) {
		string result = "";

		while (n > 0)
		{
			n--; // 每次将1~26转换为0~25, 即标准的26进制问题

			char ch = n % 26 + 'A';
			result = ch + result;

			n /= 26;
		}

		return result;        
    }
};
