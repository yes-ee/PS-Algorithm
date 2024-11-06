#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

int phi(int n)
{
	int ans = n;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
		ans -= ans / n;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		ans += phi(i);
	}

	cout << ans;

	return 0;
}