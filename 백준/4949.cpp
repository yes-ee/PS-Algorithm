#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

int main(void)
{
	string s;

	while (1)
	{
		getline(cin, s);
		if (s == ".")
			break;
		int i = 0;
		while(!st.empty()) 
			st.pop();
		while (s[i])
		{
			if (s[i] == '(')
				st.push('(');
			else if (s[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
				{
					cout << "no\n";
					break;
				}
			}
			else if (s[i] == '[')
				st.push('[');
			else if (s[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
				{
					cout << "no\n";
					break;
				}
			}
			i++;
		}
		if (i == s.length())
		{
			if (st.empty())
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}

	return 0;
}