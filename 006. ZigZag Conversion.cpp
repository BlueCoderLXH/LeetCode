class Solution {
private:
	vector<vector<char>> _mZigZag;

public:
	void initZigZag(string str, int row, int col) {
		_mZigZag.resize(row);

		// 先初始化zigzag表
		for (int r = 0; r < row; r++)
		{
			_mZigZag[r].assign(col, -1);
		}

		int k = 0;
		int i = 0, j = 0;
		while (k < (int)str.size())
		{
			i = 0;

			// Z形的纵列
			while (i < row && k < (int)str.size())
			{
				_mZigZag[i][j] = str[k];

				k++;

				i++;
			}

			i = row - 1;
			int l = j + row - 1;

			i--, j++;
			// Z形的斜边
			while (j < l && k < (int)str.size())
			{
				_mZigZag[i][j] = str[k];

				k++;

				i--;
				j++;
			}
		}
	}

	string getConvertString() {
		string zigzagStr = "";

		for (int i = 0; i < (int)_mZigZag.size(); i++)
		{
			for (int j = 0; j < (int)_mZigZag[i].size(); j++)
			{
				if (_mZigZag[i][j] != -1)
				{
					zigzagStr.push_back(_mZigZag[i][j]);
				}
			}
		}

		return zigzagStr;
	}

	string convert(string s, int numRows) {
		// 行数为1或不小于s的长度, 就直接返回其本身
		if (numRows <= 1 || numRows >= (int)s.length())
		{
			return s;
		}

		int r = numRows;
		// 列数的规律(很好找)
		int l = (r - 1) * s.length() / (2 * (r - 1)) + 1;

		// 字符串zigzag化
		initZigZag(s, r, l);

		// 返回zigzag化后的字符串
		return getConvertString();
	}
};
