class Solution {
public:
	// 判断行
	bool isRowValid(vector<vector<char>>& board) {
		vector<int> rowFlags;

		for (int i = 0; i < 9; i++)
		{
			rowFlags.clear();
			rowFlags.assign(9, 0);

			// 判断每一行
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					continue;
				}

				int index = board[i][j] - '1';

				if (rowFlags[index] == 0) // 不存在
				{
					rowFlags[index] = 1;
				}
				else                      // 已存在
				{
					return false;
				}
			}
		}

		return true;
	}

	// 判断列
	bool isColumnValid(vector<vector<char>>& board) {
		vector<int> columnFlags;

		for (int j = 0; j < 9; j++)
		{
			columnFlags.clear();
			columnFlags.assign(9, 0);

			// 判断每一列
			for (int i = 0; i < 9; i++)
			{
				if (board[i][j] == '.')
				{
					continue;
				}

				int index = board[i][j] - '1';

				if (columnFlags[index] == 0) // 不存在
				{
					columnFlags[index] = 1;
				}
				else                         // 已存在
				{
					return false;
				}
			}
		}

		return true;
	}

	// 判断九宫格
	bool isNineValid(vector<vector<char>>& board) {
		vector<int> nineFlags;

		for (int i = 2; i < 9; i += 3)
		{
			for (int j = 2; j < 9; j += 3)
			{
				nineFlags.clear();
				nineFlags.assign(9, 0);

				// 判断每一个九宫格
				for (int r = i - 2; r <= i; r++)
				{
					for (int c = j - 2; c <= j; c++)
					{
						if (board[r][c] == '.')
						{
							continue;
						}

						int index = board[r][c] - '1';

						if (nineFlags[index] == 0) // 不存在
						{
							nineFlags[index] = 1;
						}
						else                        // 已存在
						{
							return false;
						}
					}
				}
			}
		}

		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		return isRowValid(board) && isColumnValid(board) && isNineValid(board);
	}
};
