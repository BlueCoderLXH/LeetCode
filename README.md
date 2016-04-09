# LeetCode 2016/04/09
The open-source code of leetcode problems, ordered by ‘Difficulty’. Currently, it doesn't include solutions of all the problem, that's because I just have finished part of the problem. However, I'll update the code day by day.

#258 Add Digits
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
