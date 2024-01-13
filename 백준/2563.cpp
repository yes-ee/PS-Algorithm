#include <iostream>
using namespace std;

int arr[100][100];
int n, x, y, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		for (int i = y; i < y + 10; i++)
		{
			for (int j = x; j < x + 10; j++)
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
				ans++;
		}
	}

	cout << ans;

	return 0;
}