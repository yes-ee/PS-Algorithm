#include <bits/stdc++.h>

using namespace std;

int cash;
int a, b;
int chart[14];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> cash;

	for (int i = 0; i < 14; i++) {
		cin >> chart[i];
	}

	int ca = cash;

	for (int i = 0; i < 14; i++) {
		if (ca >= chart[i]) {
			a += ca / chart[i];
			ca %= chart[i];
		}
	}
	a *= chart[13];
	a += ca;

	int cnt = 0;
	int cb = cash;

	for (int i = 1; i < 14; i++) {
		if (chart[i - 1] < chart[i]) {
			if (cnt > 0) {
				cnt++;
				if (cnt >= 3) {
					cb += b * chart[i];
					b = 0;
				}
			} else {
				cnt = 1;
			}
		} else if (chart[i - 1] > chart[i]) {
			if (cnt < 0) {
				cnt--;
				if (cnt <= -3) {
					b += cb / chart[i - 1];
					cb %= chart[i - 1];
				}
			} else {
				cnt = -1;
			}
		}
	}

	b *= chart[13];
	b += cb;

	if (a > b) {
		cout << "BNP";
	} else if (a < b) {
		cout << "TIMING";
	} else {
		cout << "SAMESAME";
	}
}