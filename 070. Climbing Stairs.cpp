class Solution {
public:
    int climbStairs(int n) {
        /*
            这个其实就是一个斐波那契数列
        */
        
		int preOne = 1;
		int current = 1;
		int temp = -1;

		for (int i = 2; i <= n; i++)
		{
			temp = current;
			current += preOne;
			preOne = temp;
		}

		return current;
    }
};
