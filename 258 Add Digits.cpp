class Solution {
public:
    int addDigits(int num) {
        int sumDigit;
        
        while(1)
        {
            sumDigit = 0;
            
            // 求各位数之和
            while(num) {
                sumDigit += num % 10;
                num /= 10;
            }
            
            // 小于10返回
            if(sumDigit < 10)
            {
                break;
            }
            // 不小于10继续求
            else
            {
                num = sumDigit;
            }
        }
        
        return sumDigit;
    }
};
