class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1)
        {
            return false;
        }
        
        int num = n;
        
        // num如果为偶数, 继续
        while(num % 2 == 0)
        {
            num /= 2;
        }
        
        // 最终num为1, 表明n是2的幂;num为非1的奇数, 则不是
        return num == 1;
    }
};
