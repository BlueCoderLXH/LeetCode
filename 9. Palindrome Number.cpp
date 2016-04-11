class Solution {
public:
    bool isPalindrome(int x) {
        // 负数不是回文数
        if(x < 0)
        {
            return false;
        }
        
		int n = x;
		int num = 0;
		
		// 求逆序数
		while (n)
		{
			num *= 10;
			num += n % 10;
			n /= 10;
		}
        
        return num == x;
    }
};
