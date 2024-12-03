#include <iostream>
#include <math.h>

using namespace std;

int ans, n, cur = 1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	int num = 1;
	int cnt2 = 0; // max 4

	for (int i = 1; i <= n; i++) {
		num = i;
		while (num % 2 == 0) {
			num /= 2;
			cnt2++;
		}

		while (num % 5 == 0) {
			num /= 5;
			cnt2--;
		}

		cur = (cur * num) % 10;
	}


	cnt2 = cnt2 % 4;

	if (cnt2 == 0) cnt2 = 4;

	int mul = pow(2, cnt2);
	cur = (cur * mul) % 10;

	cout << cur;

	return 0;
}