#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a, b;
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;

	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}

	cout << cnt;

	return 0;
}
