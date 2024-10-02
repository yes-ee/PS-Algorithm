#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int t;
ll a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> a >> b;

		cout << a * b / __gcd(a, b) << "\n";
	}

	return 0;
}