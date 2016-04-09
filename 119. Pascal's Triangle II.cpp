class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
        {
            rowIndex = 0;
        }
        
        rowIndex++;
        
        vector<int> curLevel, lastLevel;
        
        // 特殊情况(1, 2)
        if(rowIndex <= 2)
        {
            while(rowIndex-- > 0)
            {
                curLevel.push_back(1);
            }
            
            return curLevel;
        }
        
        lastLevel.resize(rowIndex);
        curLevel.resize(rowIndex);
        
        lastLevel[0] = lastLevel[1] = 1;
        
        int len = 3;
        
        while(len <= rowIndex)
        {
            // 计算当前层
            curLevel[0] = 1;
            for(int i=1; i <= (len/2); i++)
            {
                curLevel[i] = lastLevel[i-1] + lastLevel[i];
                curLevel[len-1 - i] = curLevel[i];
            }
            curLevel[len - 1] = 1;
            
            // 复制当前层, 以便计算下一层
            lastLevel = curLevel;
            
            len++;
        }
        
        return curLevel;
    }
};
