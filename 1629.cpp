#include <iostream>

using namespace std;

int a, b, c;

long long pow(int a, int n) {
	if (n == 1) 
		return a % c;

	long long x = pow(a, n/2) % c;
	if (n % 2 == 0) 
		return x * x % c;
	else 
		return x * x % c *  a % c;
}

int main() {
	cin >> a >> b >> c;

	cout << pow(a, b);

	return 0;
}