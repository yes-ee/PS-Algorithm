#include <iostream>
#include <queue>
using namespace std;

int n, e;
queue<int> q;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		q.push(i + 1);

	while (q.size() != 1)
	{
		if (e % 2 == 0)
			q.pop();
		else
		{
			int x = q.front();
			q.push(x);
			q.pop();
		}
		e++;
	}

	cout << q.front();
}