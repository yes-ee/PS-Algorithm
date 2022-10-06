//누적합 구하기
#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int sum[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
	return 0;
}