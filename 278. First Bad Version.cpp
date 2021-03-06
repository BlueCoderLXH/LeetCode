/*
    典型的二分法算法
    注意：mid = (l + r) / 2可能会导致溢出
    解决溢出的方法有两种：(1)采用unsigned int类型; (2)改为mid = l / 2 + r / 2;
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 注: 必须用无符号数, 否则后面+运算可能溢出
		unsigned int l = 1, r = n;
		unsigned int mid = (l + r) / 2;

		while (l < r)
		{
			if (isBadVersion(mid))// 如果mid为bad version, 向前查找
			{
				r = mid;
			}
			else                  // 否则想后查找
			{
				l = mid + 1;
			}

			mid = (l + r) / 2;
		}

		return mid;     
    }
};
