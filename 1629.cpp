#include <iostream>
using namespace std;

int a, b, c;

long long pow(int b)
{
	if (b == 1)
		return a % c;

	long long x = pow(b / 2) % c;

	if (b % 2 == 0)
		return x * x % c;
	else
		return x * x % c * a % c;
}

int main()
{
	cin >> a >> b >> c;

	cout << pow(b);
}