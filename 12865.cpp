#include <iostream>
using namespace std;

int n, k;
int w[101];
int v[101];
int p[101][100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (w[i] > j)	//물건의 무게가 현재 배낭의 무게보다 큰 경우
				p[i][j] = p[i - 1][j];
			else
				p[i][j] = max(p[i - 1][j], p[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << p[n][k];
	return (0);
}
