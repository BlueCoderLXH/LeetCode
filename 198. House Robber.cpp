/*
	动态规划算法

	分析:
	    对于任一房间i而言, robber可以考虑偷或者不偷. 但是为了得到最大利益，需考虑如下:
	如果偷房间i, 那么房间i-1必然不能偷, 因为连续房间被偷会报警;如果不偷房间i, 那么房间i
	前面的房间偷或不偷, 就无所谓了.
	    假设steal[i]是偷房间i获得的最大利益, nosteal[i]是不偷房间i获得的最大利益, 那么
	对于状态i而言, 能获得的最大利益为: benifit[i] = max(steal[i], nosteal[i]).
	    因此状态转移方程如下:
	            steal[i] = nums[i] + nosteal[i-1];
	            nonsteal[i] = benifit[i-1];
	            benifit[i] = max(steal[i], nonsteal[i]);
*/
class Solution {
public:
    int rob(vector<int>& nums) {
		int steal, nosteal, benifit;

		// 初始化初始状态
		steal = 0;
		nosteal = benifit = 0;

		// 迭代
		for (int i = 0; i < (int)nums.size(); i++)
		{
			steal = nums[i] + nosteal;
			nosteal = benifit;

			benifit = max(steal, nosteal);
		}

		return benifit;;
    }
};
