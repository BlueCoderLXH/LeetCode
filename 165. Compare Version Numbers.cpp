class Solution {
public:
    int compareVersion(string version1, string version2) {
		while (version1.length() || version2.length())
		{
			int pos1 = version1.find(".");
			int pos2 = version2.find(".");
			
			// 获取每一级的版本号
			string str1 = version1.substr(0, pos1);
			string str2 = version2.substr(0, pos2);

			int num1 = atoi(str1.c_str());
			int num2 = atoi(str2.c_str());
			
			// 比较每一级的版本号
			if (num1 > num2)
			{
				return 1;
			}
			else if (num1 < num2)
			{
				return -1;
			}
			
			// 删除已经比较过的子版本号
			if (pos1 >= 0)
			{
				version1.erase(0, pos1 + 1);
			}
			else
			{
				version1 = "";
			}

			if (pos2 >= 0)
			{
				version2.erase(0, pos2 + 1);
			}
			else
			{
				version2 = "";
			}			
		}

		return 0;
    }
};
