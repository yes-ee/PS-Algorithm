#include <iostream>
#define MAX 1000000
using namespace std;

long long ans;
int cnt[1000];
int sum[MAX];
int n, m, num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num;	//0~1000000000
	
		if (i == 0)
			sum[0] = num % m;
		else
			sum[i] = (sum[i - 1] + num) % m;	//0~999
		cnt[sum[i]]++;
	}

	ans = cnt[0];

	for (int i = 0; i < m; i++)
		ans += (long long)cnt[i] * (cnt[i] - 1) / 2;

	cout << ans;

	return 0;
}