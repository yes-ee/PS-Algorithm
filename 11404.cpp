#include <iostream>
#define MAX 101
#define INF 99999999
using namespace std;

int n, m, w;
int arr[MAX][MAX];

void solve(void)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = INF;
			if (i == j)
				arr[i][j] = 0;
		}
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}

	solve();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF)
				cout << "0 ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}