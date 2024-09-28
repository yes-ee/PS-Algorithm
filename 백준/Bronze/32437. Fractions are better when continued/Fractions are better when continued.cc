#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll ans[41];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	ans[0] = ans[1] = 1;

	for (int i = 2; i <= n; i++)
		ans[i] = ans[i - 1] + ans[i - 2];

	cout << ans[n];

	return 0;
}