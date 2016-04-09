class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		if (numRows < 0)
		{
			numRows = 1;
		}
        
		vector<vector<int>> results;
		results.resize(numRows);

		for (int i = 0; i < numRows; i++)
		{
			int len = i + 1;
			results[i].resize(len);

			// 每一行首位置1
			results[i][0] = 1;
			for (int j = 1; j < len - 1; j++)
			{
				// 中间置为上一行与(i, j)相邻的两个数之和
				results[i][j] = results[i - 1][j - 1] + results[i - 1][j];
			}
			// 每一行尾部置1
			results[i][len - 1] = 1;
		}

		return results;  
    }
};
