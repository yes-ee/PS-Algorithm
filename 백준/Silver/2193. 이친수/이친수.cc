// 시작 1
// 11 x

#include <iostream>

using namespace std;

int n;
long long fib[91];

int main() {
	cin >> n;

	fib[1] = 1;

	for (int i = 2; i <= n; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	cout << fib[n];

	return 0;
}