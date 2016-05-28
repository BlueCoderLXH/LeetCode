/*
    数列问题, 找规律即可得到答案
    假设最终有i个灯泡on, 每一个连续为i的序列是一个等差数列
    每一个序列第一个元素: n = i^2.
    因此i = sqrt(n).
    
    n   i
    -----
    1   1
    2   1
    3   1
    -----
    4   2
    5   2
    ...
    8   2
    -----
    9   3
    ...
    15  3
    -----
    16  4
    ...
    24  4
    -----
    25  5
    ...
*/
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
