/*
    这是一个数学问题, 简单说明一下
    
    对n!做质因数分解: n! = 2^(X) * 3^(Y) * 5^(Z) * ……
    显然n!结果后面0的个数就是: min(X, Z)
    那么对于一个n!而言:
    (n! / 2)  >  (n! > 5)
    (n! / 2^(2))  >  (n! > 5^(2))
    ……
    (n! / 2^(k))  >  (n! > 5^(k))
    
    于是能知道X > Z, 即n!阶乘质因数分解中2的个数多于5的个数, 因此min(X, Z) = Z
    只要求出Z就能知道结果了
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int zeroTrailing = 0;
        
        // 求解n!阶乘质因数分解中, 5的个数
        while(n != 0)
        {
            zeroTrailing += n/5;
            n /= 5;
        }
        
        return zeroTrailing; 
    }
};
