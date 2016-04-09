class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) {
            return false;
        }
        
        int num = n;
        
        while(num % 3 == 0) {
            num /= 3;
        }
        
        return num == 1;
    }
};
