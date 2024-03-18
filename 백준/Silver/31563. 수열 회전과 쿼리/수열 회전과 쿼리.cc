#include <iostream>

using namespace std;

long long n, q;
long long arr[200020];
long long prefix[200020];
long long st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i= 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		prefix[i] = prefix[i - 1] + arr[i];

	long long a, b, c;

	while (q--) {
		cin >> a >> b;

		if (a == 1) {
			st = (st - b + n) % n;
		} else if (a == 2) {
			st = (st + b) % n;
		} else {
			cin >> c;
			b = (b + st - 1) % n + 1;
			c = (c + st - 1) % n + 1;

			if (b <= c) {
				cout << prefix[c] - prefix[b - 1];
			} else {
				cout << prefix[n] - prefix[b - 1] + prefix[c];
			}
			cout << "\n";
		}
	}
}