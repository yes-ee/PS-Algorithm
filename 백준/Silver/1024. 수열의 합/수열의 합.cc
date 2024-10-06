// binary search

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, l;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;

	for (; l <= 100; l++) {
		if (l % 2) {
			if (n % l) continue;

			int a = n / l;
			int st = a - (l / 2);
			
			if (st < 0) continue;

			for (int i = st; i < st + l; i++)
				cout << i << " ";
			return 0;
		} else {
			if (n % (l / 2)) continue;
			
			int sum = n / (l / 2);
			if (sum % 2 == 0) continue;

			int a = sum / 2;
			int st = a - (l / 2 - 1);

			if (st < 0) continue;
			
			for (int i = st; i < st + l; i++)
				cout << i << " ";
			return 0;
		}

		l++;
	}

	cout << "-1";

	return 0;
}
