#include <iostream>

using namespace std;

int t;
int a, b, res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> a >> b;

		if (b < a * 3) {
			res = a * 3 - b;
		} else if (b <= a * 4) {
			res = 0;
		} else if (b == 1 || b == 2) {
			res = (3 - b) + 1;
		} else if (b == 5) {
			res = 1 + (2 - a);
		} else {
			res = (b % 4 == 0 ? b / 4 : b / 4 + 1) - a;
		}
		cout << res << "\n";
	}
}
