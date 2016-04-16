// 算法1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
		// 长度不同, 必不同构
		if (s.length() != t.length())
		{
			return false;
		}
	
		int i = 0, j = 0;

		while (i < (int)s.length())
		{
			while (i < (int)s.length() && s[i] == '\0') i++;

			for (j = i + 1; j < (int)s.length(); j++)
			{
				// 之前没出现过(即非重复字符)
				if (s[j] != '\0')
				{
					if (s[i] == s[j])
					{
						// 标记相同字符为'\0'
						s[j] = '\0';
						
						// s同, t不同
						if (t[i] != t[j])
						{
							return false;
						}
					}
					else
					{
					    // s不同, t同
					    if(t[i] == t[j])
					    {
					        return false;
					    }
					}
				}
			}

			i++;
		}

		return true;
    }
};

//算法2
class Solution {
public:
    // 判断s -> t的映射
    bool mapStoT(string s, string t) {
        map<char, char> stMap;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(stMap.find(s[i]) == stMap.end())
            {
                stMap[s[i]] = t[i];
            }
            else
            {
                if(stMap[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
		// 长度不同, 必不同构
		if (s.length() != t.length())
		{
			return false;
		}

		return mapStoT(s, t) && mapStoT(t, s);
    }
};
