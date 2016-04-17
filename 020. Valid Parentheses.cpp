class Solution {
public:
    bool isValid(string s) {
		stack<char> bracketsStack;

		for (auto ch : s)
		{
			switch (ch)
			{
			// 左括号压栈
			case '(':
				bracketsStack.push(')');
				break;
			case '[':
				bracketsStack.push(']');
				break;
			case '{':
				bracketsStack.push('}');
				break;

			// 右括号出栈
			case ')':
			case ']':
			case '}':
				if (bracketsStack.empty() || bracketsStack.top() != ch)
				{
					return false;
				}
				bracketsStack.pop();
			}
		}

		return bracketsStack.empty();   
    }
};
