// 算法1
class Solution {
public:
    string getHint(string secret, string guess) {
		int bulls = 0, cows = 0;

		// 优先匹配bull
		for (int i = 0; i < (int)secret.length(); i++)
		{
			if (secret[i] == guess[i])
			{
				bulls++;
				
				// 标记数字位已匹配
				secret[i] = '#';
				guess[i] = '#';
			}
		}

		// 再匹配cow
		for (int i = 0; i < (int)guess.length(); i++)
		{
			// 之前已经匹配过该数字
			if (guess[i] == '#')
			{
				continue;
			}

			for (int j = 0; j < (int)secret.length(); j++)
			{
				// 之前已经匹配过该数字
				if (secret[j] == '#')
				{
					continue;
				}

				// 数字匹配
				if (guess[i] == secret[j])
				{
					cows++;

					// 标记数字位已匹配
					secret[j] = '#';

					break;
				}
			}
		}

		ostringstream outString;
		outString << bulls << "A" << cows << "B";

		string result = outString.str();

		return result;        
    }
};

// 算法2
class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0, cows = 0;

		/*
		    0 <= i <= 9;
			(1) flag[i] = 0: secret与guess中数字i的匹配持平
			(2) flag[i] > 0: secret中还有数字i未匹配
			(3) flag[i] < 0: guess中还有数字i未匹配
		*/
		int flag[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		for (int i = 0; i < (int)secret.length(); i++)
		{
			// bull
			if (secret[i] == guess[i])
			{
				bulls++;
			}
			// cows
			else
			{
				flag[secret[i] - '0']++;
				/*
				    此时flag[secret[i] - '0'] <= 0, 说明
				guess中之前存在数字secret[i]未匹配, 刚好与
				secret[i]匹配
				*/
				if (flag[secret[i] - '0'] <= 0)
				{
					cows++;
				}

				flag[guess[i] - '0']--;
				/*
				     此时flag[guess[i] - '0'] >= 0, 说明
				secret中之前存在数字guess[i]未匹配, 刚好与
				guess[i]匹配
				*/
				if (flag[guess[i] - '0'] >= 0)
				{
					cows++;
				}
			}
		}

		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};
