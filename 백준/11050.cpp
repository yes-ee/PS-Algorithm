#include <iostream>

using namespace std;

int n, k, sum;

int main() {
	cin >> n >> k;

	sum = 1;

	for (int i = 0; i < k; i++) {
		sum *= (n - i);
	}
	for (int i = 1; i <= k; i++) {
		sum /= i;
	}

	cout << sum;

	return 0;
}