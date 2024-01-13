#include <iostream>
#include <stack>
#define MAX 100000
using namespace std;

int k, sum, num;
stack<int> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}