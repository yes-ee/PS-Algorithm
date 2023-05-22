#include <iostream>
using namespace std;

int dp(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;

	return (dp(n - 1) + dp(n - 2) + dp(n - 3));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << dp(n) << endl;
	}

	return 0;
}