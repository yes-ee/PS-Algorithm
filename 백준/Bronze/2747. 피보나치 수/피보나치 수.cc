#include <iostream>

using namespace std;

int n;
int ans[46];

int main() {
	cin >> n;

	ans[1] = 1;

	for (int i = 2; i <= 45; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}

	cout << ans[n];

	return 0;
}