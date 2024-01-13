//누적합 알고리즘
#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int arr[MAX_N];	//배열 각 값 저장
int sum[MAX_N];	//누적합 저장

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
	return 0;
}